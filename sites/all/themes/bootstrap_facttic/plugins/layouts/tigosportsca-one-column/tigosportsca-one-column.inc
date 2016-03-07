<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('tigosportsca-one-column'),
  'category' => t('TigoSports CA'),
  'icon' => 'tigosportsca-one-column.png',
  'theme' => 'tigosportsca-one-column',
  'regions' => array(
    'main' => t('Main'),
  ),
);
