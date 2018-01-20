<?php

/**
 * @file
 * Page callbacks for revisions management for entities.
 */

/**
 * Generates an overview table of older revisions of an entity.
 */
function eck_revision_revision_overview($entity_type, $entity_id) {

  if (!is_object($entity_id)) {
    // Load entity
    $entity = reset(entity_load($entity_type, array($entity_id)));
  }
  else {
    $entity = $entity_id;
  }

  drupal_set_title(t('Revisions for %title', array('%title' => entity_label($entity_type, $entity))), PASS_THROUGH);

  $header = array(t('Revision'), array('data' => t('Operations'), 'colspan' => 2));

  $revisions = eck_revision_entity_revision_list($entity_type, $entity);

  $rows = array();
  $revert_permission = FALSE;
  if ((user_access("eck revert {$entity_type} entity revisions") || user_access("eck revert {$entity_type} {$entity->type} entity revisions"))) {
    $revert_permission = TRUE;
  }
  $delete_permission = FALSE;
  if ((user_access("eck delete {$entity_type} entity revisions") || user_access("eck revert {$entity_type} {$entity->type} entity revisions"))) {
    $delete_permission = TRUE;
  }

  $crud_info = get_bundle_crud_info($entity_type, $entity->type);
  $path = eck_revision_get_real_path($crud_info['view']['path'], $entity);

  foreach ($revisions as $revision) {
    $row = array();
    $operations = array();

    $date = isset($revision->created) ? $revision->created : NULL;
    $user = isset($revision->uid) ? theme('username', array('account' => user_load($revision->uid))) : NULL;

    // Verify if we set the revision path or we keep the current entity path.
    $revision_path = $path;
    if ($revision->revision_id <> $entity->revision_id) {
      $revision_path = $path . "/revisions/$revision->revision_id/view";
    }

    // Set Data
    $data = $revision->revision_id . ' - ';
    if (!empty($date) && !empty($user)) {
      $data .= t('!date by !username', array('!date' => format_date($date, 'short'), '!username' => $user));
    }
    elseif (empty($date) && !empty($user)) {
      $data .= t('By !username', array('!username' => $user));
    }
    elseif (!empty($date) && empty($user)) {
      $data .= t('!date', array('!date' => format_date($date, 'short')));
    }

    if ($revision->revision_log != '') {
      $data .= '<p class="revision-log">' . filter_xss($revision->revision_log) . '</p>';
    }

    if ($revision->revision_id == $entity->revision_id) {
      $row[] = array('data' =>  l($data, $revision_path, array('html' => TRUE)),
                     'class' => array('revision-current'));
      $operations[] = array('data' => drupal_placeholder(t('current revision')), 'class' => array('revision-current'), 'colspan' => 2);
    }
    else {
      $row[] = l($data, $revision_path, array('html' => TRUE));
      if ($revert_permission) {
        $operations[] = l(t('revert'), $path . "/revisions/$revision->revision_id/revert");
      }
      if ($delete_permission) {
        $operations[] = l(t('delete'), $path . "/revisions/$revision->revision_id/delete");
      }
    }
    $rows[] = array_merge($row, $operations);
  }

  $build['entity_revisions_table'] = array(
    '#theme' => 'table',
    '#rows' => $rows,
    '#header' => $header,
  );

  return $build;
}

/**
 * Asks for confirmation of the reversion to prevent against CSRF attacks.
 */
function eck_revision_revision_revert_confirm($form, $form_state, $entity_type, $entity_id, $revision_id) {

  // If Entity ID is entity object then set ID.
  if (is_object($entity_id)) {
    $entity_id = $entity_id->id;
  }

  // Load revision
  $revision = entity_revision_load($entity_type, array($revision_id));

  // Validate that revision exists.
  if (empty($revision)) {
    drupal_not_found();
    return;
  }

  $crud_info = get_bundle_crud_info($entity_type, $revision->type);
  $path = eck_revision_get_real_path($crud_info['view']['path'], $revision);

  $form['#entity_type'] = $entity_type;
  $form['#entity_id'] = $entity_id;
  $form['#revision'] = $revision;
  $form['#path'] = $path;

  return confirm_form($form, t('Are you sure you want to revert to the revision %num?', array('%num' => $revision_id)), $path . '/revisions', '', t('Revert'), t('Cancel'));
}

/**
 * Form submission handler for eck_revision_revision_revert_confirm().
 */
function eck_revision_revision_revert_confirm_submit($form, &$form_state) {
  $revision = $form['#revision'];
  $revision_id = $revision->revision_id;
  $title = entity_label($form['#entity_type'], $revision);

  $revision->is_new = FALSE;
  $revision->is_new_revision = TRUE;
  $revision->default_revision = TRUE;
  $revision->revision_log = t('Copy of the revision %num.', array('%num' => $revision->revision_id));
  $revision->save();

  watchdog('eck_revision', '@type: reverted %title revision %num.', array('@type' => $revision->type, '%title' => $title, '%num' => $revision_id));
  drupal_set_message(t('@type %title has been reverted back to the revision from %num.', array('@type' => $revision->type, '%title' => $title, '%num' => $revision_id)));
  $form_state['redirect'] = $form['#path'] . '/revisions';
}

/**
 * Asks for confirmation of the deletion to prevent against CSRF attacks.
 */
function eck_revision_revision_delete_confirm($form, $form_state, $entity_type, $entity_id, $revision_id) {

  // If Entity ID is entity object then set ID.
  if (is_object($entity_id)) {
    $entity_id = $entity_id->id;
  }

  // Load revision
  $revision = entity_revision_load($entity_type, array($revision_id));

  // Validate that revision exists.
  if (empty($revision)) {
    drupal_not_found();
    return;
  }

  $crud_info = get_bundle_crud_info($entity_type, $revision->type);
  $path = eck_revision_get_real_path($crud_info['view']['path'], $revision);

  $form['#entity_type'] = $entity_type;
  $form['#entity_id'] = $entity_id;
  $form['#revision'] = $revision;
  $form['#path'] = $path;

  return confirm_form($form, t('Are you sure you want to delete the revision %num?', array('%num' => $revision_id)), $path . '/revisions', t('This action cannot be undone.'), t('Delete'), t('Cancel'));
}

/**
 * Form submission handler for eck_revision_revision_delete_confirm().
 */
function eck_revision_revision_delete_confirm_submit($form, &$form_state) {
  $revision = $form['#revision'];
  $revision_id = $revision->revision_id;
  $title = entity_label($form['#entity_type'], $revision);

  // Delete the revision.
  entity_revision_delete($form['#entity_type'], $revision_id);

  watchdog('content', '@type: deleted %title revision %num.', array('@type' => $revision->type, '%title' => $title, '%num' => $revision_id));
  drupal_set_message(t('Revision %num from %title of @type has been deleted.', array('%num' => $revision_id, '@type' => $revision->type, '%title' => $title)));
  $form_state['redirect'] = $form['#path'] . '/revisions';
}
