<?php
/**
 * @file
 * cooperativa.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cooperativa_ctools_plugin_api() {
  return array("version" => "1");
}

/**
 * Implements hook_node_info().
 */
function cooperativa_node_info() {
  $items = array(
    'cooperativa' => array(
      'name' => t('Cooperativa'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Nombre'),
      'help' => '',
    ),
  );
  return $items;
}
