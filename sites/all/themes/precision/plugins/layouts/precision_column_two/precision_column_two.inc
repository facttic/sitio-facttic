<?php

$plugin = array(
  'title' => t('Precision two columns'),
  'theme' => 'precision_column_two',
  'icon' => 'precision-column-two.png',
  'category' => 'Precision',
  'regions' => array(
    'header_alpha' => t('Header alpha'),
    'main' => t('Main'),
    'aside_beta' => t('Aside beta'),
    'footer_alpha' => t('Footer alpha'),
  ),
);

/**
 * Implementation of theme_preprocess_precision_column_two().
 */
function precision_preprocess_precision_column_two(&$vars) {
  precision_check_layout_variables($vars);
}
