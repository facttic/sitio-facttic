<?php

$plugin = array(
  'title' => t('Example'),
  'theme' => 'example',
  'icon' => 'example.png',
  'category' => 'Precision subtheme example',
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
 * Implementation of theme_preprocess_precision_naked().
 */
function precision_preprocess_example(&$vars) {
  precision_check_layout_variables($vars);
}
