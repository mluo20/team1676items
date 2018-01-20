<?php
/**
 * @file
 * timeclock_eck_entities.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function timeclock_eck_entities_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_client_client';
  $strongarm->value = '1';
  $export['auto_entitylabel_client_client'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_job_job';
  $strongarm->value = '1';
  $export['auto_entitylabel_job_job'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_client_client';
  $strongarm->value = '<?php
echo $entity->field_first_name[\'und\'][0][\'value\'];
echo " ";
echo $entity->field_last_name[\'und\'][0][\'value\'];
?>';
  $export['auto_entitylabel_pattern_client_client'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_job_job';
  $strongarm->value = '<?php
$term = taxonomy_term_load($entity->field_department[\'und\'][0][\'tid\']);
echo $term->name;
echo " - ";
$client = entity_load(\'client\', array($entity->field_client[\'und\'][0][\'target_id\']));
echo $client[$entity->field_client[\'und\'][0][\'target_id\']]->field_first_name[\'und\'][0][\'value\'];
echo " ";
echo $client[$entity->field_client[\'und\'][0][\'target_id\']]->field_last_name[\'und\'][0][\'value\'];
?>';
  $export['auto_entitylabel_pattern_job_job'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_punch_punch';
  $strongarm->value = '<?php
$id = array();
$id = entity_extract_ids(\'punch\', $entity);
echo $id[0];
?>';
  $export['auto_entitylabel_pattern_punch_punch'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_client_client';
  $strongarm->value = 1;
  $export['auto_entitylabel_php_client_client'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_job_job';
  $strongarm->value = 1;
  $export['auto_entitylabel_php_job_job'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_punch_punch';
  $strongarm->value = 1;
  $export['auto_entitylabel_php_punch_punch'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_punch_punch';
  $strongarm->value = '1';
  $export['auto_entitylabel_punch_punch'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_client__client';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'uid' => array(
          'weight' => '0',
        ),
        'created' => array(
          'weight' => '1',
        ),
        'changed' => array(
          'weight' => '2',
        ),
        'revision_id' => array(
          'weight' => '9',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_client__client'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_job__job';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'revision_id' => array(
          'weight' => '13',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'uid' => array(
          'weight' => '0',
        ),
        'created' => array(
          'weight' => '2',
        ),
        'changed' => array(
          'weight' => '3',
        ),
      ),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
        'uid' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'created' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'changed' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'revision_id' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_job__job'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_punch__punch';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'flag' => array(
          'weight' => '10',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_punch__punch'] = $strongarm;

  return $export;
}
