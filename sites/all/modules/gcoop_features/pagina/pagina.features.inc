<?php
/**
 * @file
 * pagina.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pagina_ctools_plugin_api() {
  return array("version" => "1");
}

/**
 * Implements hook_node_info().
 */
function pagina_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Página básica'),
      'base' => 'node_content',
      'description' => t('Use las <em>páginas básicas</em> para su contenido estático, como una página "Acerca de...".'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
