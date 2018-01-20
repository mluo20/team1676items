<?php
/**
 * @file
 * timeclock_departments.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function timeclock_departments_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-department-field_finance_code'.
  $field_instances['taxonomy_term-department-field_finance_code'] = array(
    'bundle' => 'department',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_finance_code',
    'label' => 'Finance Code',
    'required' => FALSE,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Finance Code');

  return $field_instances;
}
