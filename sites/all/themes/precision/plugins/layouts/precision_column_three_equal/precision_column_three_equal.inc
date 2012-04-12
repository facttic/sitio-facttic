<?php

$plugin = array(
  'title' => t('Precision three columns'),
  'theme' => 'precision_column_three_equal',
  'icon' => 'precision-column-three-equal.png',
  'category' => 'Precision',
  'regions' => array(
    'header_alpha' => t('Header alpha'),
    'main_alpha' => t('Main alpha'),
    'main_beta' => t('Main beta'),
    'main_gamma' => t('Main gamma'),
    'footer_alpha' => t('Footer alpha'),
  ),
);

/**
 * Implementation of theme_preprocess_precision_column_three_equal().
 */
function precision_preprocess_precision_column_three_equal(&$vars) {
  precision_check_layout_variables($vars);
}
