<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('sdt'),
  'category' => t('Comunidad resellers'),
  'icon' => 'sdt.png',
  'theme' => 'sdt',
  'regions' => array(
    'header' => t('Header'),
    'navbar' => t('Navbar'),
    'main' => t('Main'),
    'footer' => t('Footer'),
  ),
);
