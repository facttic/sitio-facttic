<?php
/**
 * @file
 * site_default_template.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function site_default_template_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Menú principal',
    'description' => 'El menú <em>Principal</em> se usa en muchos sitios web para mostrar las secciones principales del sitio, generalmente en una barra de navegación superior.',
  );
  // Exported menu: menu-enlaces-de-interes
  $menus['menu-enlaces-de-interes'] = array(
    'menu_name' => 'menu-enlaces-de-interes',
    'title' => 'Enlaces de Interes',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('El menú <em>Principal</em> se usa en muchos sitios web para mostrar las secciones principales del sitio, generalmente en una barra de navegación superior.');
  t('Enlaces de Interes');
  t('Menú principal');


  return $menus;
}
