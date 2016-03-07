<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('comunidad-one-column'),
  'category' => t('Comunidad resellers'),
  'icon' => 'comunidad-one-column.png',
  'theme' => 'comunidad-one-column',
  'regions' => array(
    'main-cont' => t('Main cont'),
  ),
);
