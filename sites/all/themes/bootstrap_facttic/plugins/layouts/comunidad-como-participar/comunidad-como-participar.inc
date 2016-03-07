<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('comunidad-como-participar'),
  'category' => t('Comunidad resellers'),
  'icon' => 'comunidad-como-participar.png',
  'theme' => 'comunidad-como-participar',
  'regions' => array(
    'informacion-subtitulo' => t('Informacion subtitulo'),
    'condicion-categoria-1' => t('Condicion categoria 1'),
    'condicion-categoria-2' => t('Condicion categoria 2'),
    'condicion-categoria-3' => t('Condicion categoria 3'),
    'condicion-categoria-4' => t('Condicion categoria 4'),
    'tabla-compensacion-pesos' => t('Tabla compensacion en pesos'),
    'tabla-planificacion' => t('Tabla planificacion'),
    'informacion-extra' => t('Informacion extra'),
  ),
);
