<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('comunidad-canje-credito'),
  'category' => t('Comunidad resellers'),
  'icon' => 'comunidad-canje-credito.png',
  'theme' => 'comunidad-canje-credito',
  'regions' => array(
    'informacion-usuario' => t('Informacion usuario'),
    'emision-cheque' => t('Emision cheque'),
    'categoria-usuario' => t('Categoria usuario'),
    'listado-cheques' => t('Listado cheques'),
    'listado-productos-comprados' => t('Listado productos comprados'),
    'banner' => t('Banner'),
    'cuenta-corriente' => t('Cuenta corriente'),
    'banner-contacto' => t('Banner contacto'),
    'disponibilidad-fondos' => t('Disponibilidad fondos'),
    'titulo-productos-comprados' => t('Titulo productos comprados'),
    'suma-total-productos-comprados' => t('Suma total productos comprados'),
  ),
);
