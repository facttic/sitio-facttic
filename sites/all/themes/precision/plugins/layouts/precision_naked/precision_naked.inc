<?php

$plugin = array(
  'title' => t('Precision naked'),
  'theme' => 'precision_naked',
  'icon' => 'precision-naked.png',
  'category' => 'Precision',
  'regions' => array(
    'main' => t('Main'),
  ),
);

/**
 * Implementation of theme_preprocess_precision_naked().
 */
function precision_preprocess_precision_naked(&$vars) {
  precision_check_layout_variables($vars);
}
