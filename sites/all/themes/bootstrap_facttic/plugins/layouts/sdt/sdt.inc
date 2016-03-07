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
    'main_left' => t('Main Left'),
    'main_center' => t('Main Center'),
    'main_right' => t('Main Right'),
    'footer' => t('Footer'),
  ),
);
