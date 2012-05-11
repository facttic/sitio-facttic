<?php
/**
 * @file
 * inicio.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function inicio_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function inicio_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function inicio_image_default_styles() {
  $styles = array();

  // Exported image style: logoslistado
  $styles['logoslistado'] = array(
    'name' => 'logoslistado',
    'effects' => array(
      1 => array(
        'label' => 'Escalar y recortar',
        'help' => 'Escalar y recortar mantendrán la relación de proporciones de la imagen original y se desechará lo que sobre por el lado mayor. Esto es especialmente útil para crear miniaturas perfectamente cuadradas sin deformar la imagen.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '37',
          'height' => '37',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
