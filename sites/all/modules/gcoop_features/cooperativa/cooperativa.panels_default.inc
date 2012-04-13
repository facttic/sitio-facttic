<?php
/**
 * @file
 * cooperativa.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function cooperativa_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'encabezado_cooperativas';
  $mini->category = '';
  $mini->admin_title = 'contenidos_cooperativas';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'precision_naked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8';
    $pane->panel = 'main';
    $pane->type = 'views';
    $pane->subtype = 'descripcion_actividad';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 1,
      'link_to_view' => 0,
      'args' => '%0',
      'url' => '',
      'display' => 'default',
      'override_title' => 1,
      'override_title_text' => '<span class="titulosbloques">[Quiénes somos, Qué hacemos]</span>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title_element' => '',
        'id' => '',
        'class' => 'bloque-cooperativa',
        'grid' => '16',
        'prefix' => '',
        'suffix' => '',
        'pad' => '',
        'push' => '',
        'pull' => '',
        'alpha' => 1,
        'omega' => 0,
      ),
      'style' => 'precision_grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-8'] = $pane;
    $display->panels['main'][0] = 'new-8';
    $pane = new stdClass();
    $pane->pid = 'new-9';
    $pane->panel = 'main';
    $pane->type = 'views';
    $pane->subtype = 'noticias_home';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '4',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 1,
      'link_to_view' => 0,
      'args' => '%0',
      'url' => '',
      'display' => 'default',
      'override_title' => 1,
      'override_title_text' => '<span class="titulosbloques">[Noticias]</span>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title_element' => '',
        'id' => '',
        'class' => 'bloque-cooperativa listadodenoticias',
        'grid' => '16',
        'prefix' => '',
        'suffix' => '',
        'pad' => '',
        'push' => '',
        'pull' => '',
        'alpha' => 0,
        'omega' => 0,
      ),
      'style' => 'precision_grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-9'] = $pane;
    $display->panels['main'][1] = 'new-9';
    $pane = new stdClass();
    $pane->pid = 'new-10';
    $pane->panel = 'main';
    $pane->type = 'panels_mini';
    $pane->subtype = 'seguinos_cooperativas';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<span class="titulosbloques">[Seguinos]</span>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title_element' => '',
        'id' => '',
        'class' => 'bloque-cooperativa seguinos',
        'grid' => '16',
        'prefix' => '',
        'suffix' => '',
        'pad' => '',
        'push' => '',
        'pull' => '',
        'alpha' => 0,
        'omega' => 1,
      ),
      'style' => 'precision_grid',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-10'] = $pane;
    $display->panels['main'][2] = 'new-10';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-8';
  $mini->display = $display;
  $export['encabezado_cooperativas'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'seguinos_cooperativas';
  $mini->category = '';
  $mini->admin_title = 'seguinos_cooperativas';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'precision_naked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-11';
    $pane->panel = 'main';
    $pane->type = 'views';
    $pane->subtype = 'redes_sociales_cooperativas';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 1,
      'link_to_view' => 0,
      'args' => '%0',
      'url' => '',
      'display' => 'default',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-11'] = $pane;
    $display->panels['main'][0] = 'new-11';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-11';
  $mini->display = $display;
  $export['seguinos_cooperativas'] = $mini;

  return $export;
}
