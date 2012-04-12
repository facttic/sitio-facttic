<?php

$plugin = array(
  'title' => t('Precision three columns'),
  'theme' => 'precision_column_three',
  'icon' => 'precision-column-three.png',
  'category' => 'Precision',
  'regions' => array(
    'header_alpha' => t('Header alpha'),
    'header_beta' => t('Header beta'),
    'main' => t('Main'),
    'aside_alpha' => t('Aside alpha'),
    'aside_beta' => t('Aside beta'),
    'footer_alpha' => t('Footer alpha'),
    'footer_beta' => t('Footer beta'),
  ),
);

/**
 * Implementation of theme_preprocess_precision_column_three().
 */
function precision_preprocess_precision_column_three(&$vars) {
  precision_check_layout_variables($vars);
}
