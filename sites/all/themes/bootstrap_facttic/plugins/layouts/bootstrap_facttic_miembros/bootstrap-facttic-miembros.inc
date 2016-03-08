<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('Miembros'),
  'category' => t('Bootstrap facttic'),
  'icon' => 'bootstrap-facttic-miembros.png',
  'theme' => 'bootstrap_facttic_miembros',
  'regions' => array(
    'main' => t('Main'),
    'main_left' => t('Main Left'),
    'main_right' => t('Main Right')
  ),
);
