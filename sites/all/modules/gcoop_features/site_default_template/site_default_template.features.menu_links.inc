<?php
/**
 * @file
 * site_default_template.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function site_default_template_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Inicio',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-enlaces-de-interes:<front>
  $menu_links['menu-enlaces-de-interes:<front>'] = array(
    'menu_name' => 'menu-enlaces-de-interes',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'unllink',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-enlaces-de-interes:http://www.fecootra.org.ar
  $menu_links['menu-enlaces-de-interes:http://www.fecootra.org.ar'] = array(
    'menu_name' => 'menu-enlaces-de-interes',
    'link_path' => 'http://www.fecootra.org.ar',
    'router_path' => '',
    'link_title' => 'FECOOTRA',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('FECOOTRA');
  t('Inicio');
  t('unllink');


  return $menu_links;
}
