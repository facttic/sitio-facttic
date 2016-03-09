<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('Noticia'),
  'category' => t('Bootstrap facttic'),
  'icon' => 'bootstrap-facttic-noticia.png',
  'theme' => 'bootstrap_facttic_noticia',
  'regions' => array(
    'main' => t('Main'),
    'main_left' => t('Main Left'),
    'main_right' => t('Main Right')
  ),
);
