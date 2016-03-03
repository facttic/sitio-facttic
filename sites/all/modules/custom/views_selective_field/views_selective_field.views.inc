<?php

/**
 * @file
 * Provide field handler to select between two other fields.
 */

/**
 * Implements hook_views_data().
 */
function views_selective_field_views_data() {
  $data['views']['selective_field'] = array(
    'title' => t('Selective field'),
    'help' => t('Render fields selectively.'),
    'field' => array(
      'help' => t('Select the field to render based on conditions.'),
      'handler' => 'views_selective_field_handler_field',
    ),
  );
  return $data;
}
