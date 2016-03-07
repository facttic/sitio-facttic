<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('comunidad-noticias'),
  'category' => t('Comunidad resellers'),
  'icon' => 'comunidad-noticias.png',
  'theme' => 'comunidad-noticias',
  'regions' => array(
    'listado-noticias-resumen' => t('Listado noticias resumen'),
    'listado-noticias-completo' => t('Listado noticias completo'),
  ),
);
