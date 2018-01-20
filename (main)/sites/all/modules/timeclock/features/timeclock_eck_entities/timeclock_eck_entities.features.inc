<?php
/**
 * @file
 * timeclock_eck_entities.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function timeclock_eck_entities_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function timeclock_eck_entities_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function timeclock_eck_entities_eck_bundle_info() {
  $items = array(
    'client_client' => array(
      'machine_name' => 'client_client',
      'entity_type' => 'client',
      'name' => 'client',
      'label' => 'Client',
      'config' => array(
        'managed_properties' => array(
          'uid' => 'uid',
          'created' => 'created',
          'changed' => 'changed',
          'revision_id' => 'revision_id',
          'title' => 0,
        ),
      ),
    ),
    'job_job' => array(
      'machine_name' => 'job_job',
      'entity_type' => 'job',
      'name' => 'job',
      'label' => 'Job',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
          'uid' => 'uid',
          'created' => 'created',
          'changed' => 'changed',
          'revision_id' => 'revision_id',
        ),
      ),
    ),
    'job_non_client_job' => array(
      'machine_name' => 'job_non_client_job',
      'entity_type' => 'job',
      'name' => 'non_client_job',
      'label' => 'Non-Client Job',
      'config' => array(),
    ),
    'punch_punch' => array(
      'machine_name' => 'punch_punch',
      'entity_type' => 'punch',
      'name' => 'punch',
      'label' => 'Punch',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function timeclock_eck_entities_eck_entity_type_info() {
  $items = array(
    'client' => array(
      'name' => 'client',
      'label' => 'Client',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'revision_id' => array(
          'label' => 'Revision',
          'type' => 'positive_integer',
          'behavior' => 'revision',
        ),
      ),
    ),
    'job' => array(
      'name' => 'job',
      'label' => 'Job',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'revision_id' => array(
          'label' => 'Revision',
          'type' => 'positive_integer',
          'behavior' => 'revision',
        ),
      ),
    ),
    'punch' => array(
      'name' => 'punch',
      'label' => 'Punch',
      'properties' => array(
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'revision_id' => array(
          'label' => 'Revision',
          'type' => 'positive_integer',
          'behavior' => 'revision',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_flag_default_flags().
 */
function timeclock_eck_entities_flag_default_flags() {
  $flags = array();
  // Exported flag: "Flag".
  $flags['flag'] = array(
    'entity_type' => 'punch',
    'title' => 'Flag',
    'global' => 0,
    'types' => array(
      0 => 'punch',
    ),
    'flag_short' => 'Flag this punch',
    'flag_long' => 'Punches that are flagged can not be edited or approved until the user who flagged it removes their flag.',
    'flag_message' => 'This punch has been flagged',
    'unflag_short' => 'Unflag this punch',
    'unflag_long' => 'Punches that are flagged can not be edited or approved until the user who flagged it removes their flag.',
    'unflag_message' => 'The flag from this punch has been removed.',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 1,
    'flag_confirmation' => 'Are you sure you want to flag this punch?',
    'unflag_confirmation' => 'Are you sure you want to remove the flag from this punch?',
    'module' => 'timeclock_eck_entities',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
