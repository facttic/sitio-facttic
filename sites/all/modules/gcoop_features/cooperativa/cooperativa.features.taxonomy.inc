<?php
/**
 * @file
 * cooperativa.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cooperativa_taxonomy_default_vocabularies() {
  return array(
    'etiquetas_cooperativa' => array(
      'name' => 'Etiquetas Cooperativa',
      'machine_name' => 'etiquetas_cooperativa',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
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
