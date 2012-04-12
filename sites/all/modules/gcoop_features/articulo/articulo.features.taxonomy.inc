<?php
/**
 * @file
 * articulo.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function articulo_taxonomy_default_vocabularies() {
  return array(
    'tags' => array(
      'name' => 'Etiquetas',
      'machine_name' => 'tags',
      'description' => 'Use etiquetas para agrupar artículos sobre temas similares en categorías.',
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
