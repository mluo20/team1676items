<?php
/**
 * @file
 * timeclock_eck_entities.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function timeclock_eck_entities_taxonomy_default_vocabularies() {
  return array(
    'non_client_job_types' => array(
      'name' => 'Non-Client Job Types',
      'machine_name' => 'non_client_job_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
