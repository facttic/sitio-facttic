<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('Cooperativa'),
  'category' => t('Bootstrap facttic'),
  'icon' => 'bootstrap-facttic-cooperativa.png',
  'theme' => 'bootstrap_facttic_cooperativa',
  'regions' => array(
    'main' => t('Main'),
    'main_first_left' => t('First Main Left'),
    'main_first_center' => t('First Main Center'),
    'main_first_right' => t('First Main Right'),
    'main_second_left' => t('Second Main Left'),
    'main_second_center' => t('Second Main Center'),
    'main_second_right' => t('Second Main Right')
  ),
);
