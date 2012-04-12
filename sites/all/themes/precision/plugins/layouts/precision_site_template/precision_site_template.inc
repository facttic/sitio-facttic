<?php

$plugin = array(
  'title' => t('Precision site template'),
  'theme' => 'precision_site_template',
  'icon' => 'precision-site-template.png',
  'category' => 'Precision',
  'regions' => array(
    'branding' => t('Branding'),
    'nav' => t('Navigation'),
    'main' => t('Main'),
    'footer' => t('Footer'),
  ),
);

/**
 * Preprocess the site template layout.
 */
function precision_preprocess_precision_site_template(&$vars) {
  precision_check_layout_variables($vars);
}
