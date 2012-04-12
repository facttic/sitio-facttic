<?php
/**
 * @file
 * inicio.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function inicio_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Presentación-home';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'presentacion_home';
  $fe_block_boxes->body = 'lalala';

  $export['presentacion_home'] = $fe_block_boxes;

  return $export;
}
