<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('comunidad-descargas-graficas'),
  'category' => t('Comunidad resellers'),
  'icon' => 'comunidad-descargas-graficas.png',
  'theme' => 'comunidad-descargas-graficas',
  'regions' => array(
    'texto' => t('Texto'),
    'title-listado-fondos-screen' => t('titulo listado fondos screen'),
    'title-logos-extra' => t('titulo listado logos extra'),
    'listado-logos' => t('Listado logos'),
    'listado-logos-extra' => t('Listado logos extra'),
    'listado-fondos' => t('Listado fondos'),
    'listado-screen-saver' => t('Lista de screen saver'),
  ),
);
