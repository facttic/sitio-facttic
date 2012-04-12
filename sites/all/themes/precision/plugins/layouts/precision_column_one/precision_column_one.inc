<?php

$plugin = array(
  'title' => t('Precision one column'),
  'theme' => 'precision_column_one',
  'icon' => 'precision-column-one.png',
  'category' => 'Precision',
  'regions' => array(
    'main' => t('Main'),
  ),
);

/**
 * Implementation of theme_preprocess_precision_column_one().
 */
function precision_preprocess_precision_column_one(&$vars) {
  precision_check_layout_variables($vars);
}
