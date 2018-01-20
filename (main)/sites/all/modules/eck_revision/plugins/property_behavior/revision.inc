<?php

/**
 * @file
 * ECK Revision Revision property behavior file.
 */

/*
 * Implementation of Revision property behavior, which represents the language of an entity.
 */
$plugin = array(
  'label' => "Revision",
  'schema' => 'eck_revision_property_schema',
  'property_info' => 'eck_revision_property_property_info',
  'entity_info' => 'eck_revision_property_entity_info',
  'entity_save' => 'eck_revision_property_entity_save',
  'property_add' => 'eck_revision_property_property_add',
  'property_remove' => 'eck_revision_property_property_remove',
  'default_widget' => 'eck_revision_revision_property_widget',
  'unique' => TRUE,
);

function eck_revision_revision_property_widget($property, $vars) {
  $entity = $vars['entity'];

  // If entity is now, do not show the form.
  if (isset($entity->is_new) && $entity->is_new == TRUE) {
    return;
  }

  $form = array(
    '#weight' => 99,
  );

  $form['revision_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Revision information'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#attributes' => array(
      'class' => array('entity-form-revision-information'),
    ),
    '#tree' => TRUE,
  );

  $form['revision_information']['revision'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create new revision'),
    '#default_value' => 0,
  );

  $form['revision_information']['revision']['#states'] = array(
    'checked' => array(
      'textarea[name="log"]' => array('empty' => FALSE),
    ),
  );

  $form['revision_information']['log'] = array(
    '#type' => 'textarea',
    '#title' => t('Revision log message'),
    '#rows' => 4,
    '#default_value' => '',
    '#description' => t('Provide an explanation of the changes you are making. This will help other authors understand your motivations.'),
  );

  return $form;
}

function eck_revision_property_property_info($property, $vars) {
  $vars['properties'][$property]['type'] = 'positive_integer';
  $vars['properties'][$property]['description'] = t("The current {entity_type}_revision.vid version identifier.");
  return $vars;
}

function eck_revision_property_schema($property, $vars) {
  $entity_type = $vars['entity_type'];
  $vars['schema']["eck_{$entity_type->name}_revision"] = eck_revision__entity_type__schema($entity_type);
  return $vars;
}

function eck_revision_property_property_add($property, $var) {

  $name = $var['name'];
  $entity_type = $var['entity_type'];
  $property_data = $var['property'];

  // Verify if the property being added is a revision.
  if (isset($var['property']['behavior']) && $var['property']['behavior'] == 'revision') {
    // Create Revision table.
    if (!db_table_exists("eck_{$entity_type->name}_revision")) {
      $schema = eck_revision__entity_type__schema($entity_type);
      db_create_table("eck_{$entity_type->name}_revision", $schema);
    }
  }

  if (db_table_exists("eck_{$entity_type->name}_revision")) {
    // Add field to revision table.
    $schema = eck_property_type_schema($property_data['type']);
    if (!db_field_exists("eck_{$entity_type->name}_revision", $name)) {
      db_add_field("eck_{$entity_type->name}_revision", $name, $schema);
    }
  }

}

function eck_revision_property_property_remove($property, $var) {

  $name = $var['name'];
  $entity_type = $var['entity_type'];
  $property_data = $var['property'];

  // Make sure database table exists.
  if (db_table_exists("eck_{$entity_type->name}_revision")) {
    // Verify if the property being removed is a revision.
    if (isset($var['property']['behavior']) && $var['property']['behavior'] == 'revision') {
      // Revision property has been removed, so we delete the revision table and all its data.
      // @see eck_revision_batch_operation_delete_entity_revisions()
    }
    else {
      // We remove the column from the revision table.
      db_drop_field("eck_{$entity_type->name}_revision", $name);
    }
  }
}

function eck_revision_property_entity_info($property, $var) {
  $info = $var;

  $info['eck_revision'] = TRUE;
  $info['revision table'] = $info['base table'] . '_revision';
  $info['entity keys']['revision'] = $property;

  // This needs to be added because entity info has already processed
  // the schema fields sql for the entity type.
  $info['schema_fields_sql']['revision table'] = drupal_schema_fields_sql($info['base table'] . '_revision');

  return $info;
}

function eck_revision_property_entity_save($property, $vars) {
  $entity = $vars['entity'];
  $values = isset($vars['form_state']['values']) ? $vars['form_state']['values'] : array();

  if (isset($values['revision_information']['revision']) && $values['revision_information']['revision']) {
    $entity->is_new = FALSE;
    $entity->is_new_revision = TRUE;
    $entity->default_revision = TRUE;

    if (!empty($values['revision_information']['log'])) {
      $entity->revision_log = $values['revision_information']['log'];
    }
    else {
      $entity->revision_log = NULL;
    }
  }
}
