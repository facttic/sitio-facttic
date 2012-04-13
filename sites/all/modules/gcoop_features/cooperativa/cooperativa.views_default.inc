<?php
/**
 * @file
 * cooperativa.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cooperativa_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'descripcion_actividad';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'descripcion_actividad';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Contenido: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 1;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Campo: Contenido: Actividad  */
  $handler->display->display_options['fields']['field_actividad']['id'] = 'field_actividad';
  $handler->display->display_options['fields']['field_actividad']['table'] = 'field_data_field_actividad';
  $handler->display->display_options['fields']['field_actividad']['field'] = 'field_actividad';
  $handler->display->display_options['fields']['field_actividad']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_actividad']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_actividad']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_actividad']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_actividad']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_actividad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_actividad']['alter']['nl2br'] = 1;
  $handler->display->display_options['fields']['field_actividad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_actividad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_actividad']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_actividad']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_actividad']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_actividad']['element_class'] = 'actividad';
  $handler->display->display_options['fields']['field_actividad']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_actividad']['element_label_class'] = 'tituloactividad';
  $handler->display->display_options['fields']['field_actividad']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_actividad']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_actividad']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_actividad']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_actividad']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_actividad']['field_api_classes'] = 0;
  /* Criterio de ordenación: Contenido: Fecha del envío */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contextual: Contenido: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Criterios de filtrado: Contenido: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterios de filtrado: Contenido: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperativa' => 'cooperativa',
  );
  $translatables['descripcion_actividad'] = array(
    t('Master'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Ascendente'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('Actividad '),
    t('Todo(s)'),
  );
  $export['descripcion_actividad'] = $view;

  $view = new view;
  $view->name = 'direccion_sede';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'direccion_sede';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Contenido: Sede */
  $handler->display->display_options['fields']['field_sede']['id'] = 'field_sede';
  $handler->display->display_options['fields']['field_sede']['table'] = 'field_data_field_sede';
  $handler->display->display_options['fields']['field_sede']['field'] = 'field_sede';
  $handler->display->display_options['fields']['field_sede']['label'] = '';
  $handler->display->display_options['fields']['field_sede']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_sede']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_sede']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_sede']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sede']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_sede']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_sede']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_sede']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_sede']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_sede']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_sede']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sede']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_sede']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_sede']['field_api_classes'] = 0;
  /* Campo: Contenido: Correo Electrónico */
  $handler->display->display_options['fields']['field_correoelectronico']['id'] = 'field_correoelectronico';
  $handler->display->display_options['fields']['field_correoelectronico']['table'] = 'field_data_field_correoelectronico';
  $handler->display->display_options['fields']['field_correoelectronico']['field'] = 'field_correoelectronico';
  $handler->display->display_options['fields']['field_correoelectronico']['label'] = '';
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['path'] = 'mailto:[field_correoelectronico]';
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_correoelectronico']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_correoelectronico']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_correoelectronico']['field_api_classes'] = 0;
  /* Criterio de ordenación: Contenido: Fecha del envío */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contextual: Contenido: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Criterios de filtrado: Contenido: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterios de filtrado: Contenido: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperativa' => 'cooperativa',
  );
  $translatables['direccion_sede'] = array(
    t('Master'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Ascendente'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('mailto:[field_correoelectronico]'),
    t('Todo(s)'),
  );
  $export['direccion_sede'] = $view;

  $view = new view;
  $view->name = 'mapa_miembros';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'mapa_miembros';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['style_plugin'] = 'gmap';
  $handler->display->display_options['style_options']['macro'] = '[gmap zoom=4 |center=-40.647303562522495,-65.126953125 |width=280px |height=510px |control=Micro |type=Map]';
  $handler->display->display_options['style_options']['markertype'] = 'small orange';
  $handler->display->display_options['style_options']['latfield'] = 'title';
  $handler->display->display_options['style_options']['lonfield'] = 'title';
  $handler->display->display_options['style_options']['markerfield'] = 'title';
  $handler->display->display_options['style_options']['enablermt'] = 0;
  $handler->display->display_options['style_options']['rmtfield'] = 'title';
  $handler->display->display_options['style_options']['tooltipenabled'] = 1;
  $handler->display->display_options['style_options']['tooltipfield'] = 'title';
  $handler->display->display_options['style_options']['bubbletextfield'] = 'nothing';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Campo: Contenido: Sede */
  $handler->display->display_options['fields']['field_sede']['id'] = 'field_sede';
  $handler->display->display_options['fields']['field_sede']['table'] = 'field_data_field_sede';
  $handler->display->display_options['fields']['field_sede']['field'] = 'field_sede';
  $handler->display->display_options['fields']['field_sede']['label'] = '';
  $handler->display->display_options['fields']['field_sede']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_sede']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_sede']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_sede']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sede']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_sede']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_sede']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_sede']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_sede']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_sede']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sede']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_sede']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_sede']['field_api_classes'] = 0;
  /* Campo: Nombre + sede */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Nombre + sede';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title]
[field_sede]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Criterios de filtrado: Contenido: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterios de filtrado: Contenido: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperativa' => 'cooperativa',
  );
  $translatables['mapa_miembros'] = array(
    t('Master'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Ascendente'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('[title]
[field_sede]'),
  );
  $export['mapa_miembros'] = $view;

  $view = new view;
  $view->name = 'mapa_sede';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'mapa_sede';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'gmap';
  $handler->display->display_options['style_options']['macro'] = '[gmap width=310px | height=220px]';
  $handler->display->display_options['style_options']['markertype'] = 'small orange';
  $handler->display->display_options['style_options']['latfield'] = 'latitude';
  $handler->display->display_options['style_options']['lonfield'] = 'latitude';
  $handler->display->display_options['style_options']['markerfield'] = 'latitude';
  $handler->display->display_options['style_options']['enablermt'] = 0;
  $handler->display->display_options['style_options']['rmtfield'] = 'latitude';
  $handler->display->display_options['style_options']['center_on_nodearg'] = 1;
  $handler->display->display_options['style_options']['center_on_nodearg_arg'] = 'nid';
  $handler->display->display_options['style_options']['highlight_nodearg_arg'] = 'nid';
  $handler->display->display_options['style_options']['tooltipfield'] = 'latitude';
  $handler->display->display_options['style_options']['bubbletextfield'] = 'latitude';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Ubicación: Latitude */
  $handler->display->display_options['fields']['latitude']['id'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['table'] = 'location';
  $handler->display->display_options['fields']['latitude']['field'] = 'latitude';
  $handler->display->display_options['fields']['latitude']['exclude'] = TRUE;
  $handler->display->display_options['fields']['latitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['external'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['latitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['latitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['latitude']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['latitude']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['latitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['latitude']['empty_zero'] = 0;
  $handler->display->display_options['fields']['latitude']['hide_alter_empty'] = 1;
  /* Campo: Ubicación: Longitude */
  $handler->display->display_options['fields']['longitude']['id'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['table'] = 'location';
  $handler->display->display_options['fields']['longitude']['field'] = 'longitude';
  $handler->display->display_options['fields']['longitude']['exclude'] = TRUE;
  $handler->display->display_options['fields']['longitude']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['external'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['longitude']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['longitude']['alter']['html'] = 0;
  $handler->display->display_options['fields']['longitude']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['longitude']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['longitude']['hide_empty'] = 0;
  $handler->display->display_options['fields']['longitude']['empty_zero'] = 0;
  $handler->display->display_options['fields']['longitude']['hide_alter_empty'] = 1;
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Criterio de ordenación: Contenido: Fecha del envío */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contextual: Contenido: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Criterios de filtrado: Contenido: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterios de filtrado: Contenido: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperativa' => 'cooperativa',
  );
  $translatables['mapa_sede'] = array(
    t('Master'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Ascendente'),
    t('Desc'),
    t('Latitude'),
    t('Longitude'),
    t('Título'),
    t('Todo(s)'),
  );
  $export['mapa_sede'] = $view;

  $view = new view;
  $view->name = 'miembros';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'miembros';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Contenido: Logo Cuadrado */
  $handler->display->display_options['fields']['field_logocuadrado']['id'] = 'field_logocuadrado';
  $handler->display->display_options['fields']['field_logocuadrado']['table'] = 'field_data_field_logocuadrado';
  $handler->display->display_options['fields']['field_logocuadrado']['field'] = 'field_logocuadrado';
  $handler->display->display_options['fields']['field_logocuadrado']['label'] = '';
  $handler->display->display_options['fields']['field_logocuadrado']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_logocuadrado']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_logocuadrado']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_logocuadrado']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_logocuadrado']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_logocuadrado']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_logocuadrado']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_logocuadrado']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_logocuadrado']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_logocuadrado']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_logocuadrado']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_logocuadrado']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_logocuadrado']['element_class'] = 'logolistamiembros';
  $handler->display->display_options['fields']['field_logocuadrado']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logocuadrado']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_logocuadrado']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_logocuadrado']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_logocuadrado']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_logocuadrado']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logocuadrado']['settings'] = array(
    'image_style' => 'logoslistado',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_logocuadrado']['field_api_classes'] = 0;
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Campo: Contenido: Sede */
  $handler->display->display_options['fields']['field_sede']['id'] = 'field_sede';
  $handler->display->display_options['fields']['field_sede']['table'] = 'field_data_field_sede';
  $handler->display->display_options['fields']['field_sede']['field'] = 'field_sede';
  $handler->display->display_options['fields']['field_sede']['label'] = '';
  $handler->display->display_options['fields']['field_sede']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_sede']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_sede']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_sede']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_sede']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sede']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_sede']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_sede']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_sede']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_sede']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_sede']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_sede']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sede']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_sede']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_sede']['field_api_classes'] = 0;
  /* Criterio de ordenación: Contenido: Título */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Criterios de filtrado: Contenido: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterios de filtrado: Contenido: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperativa' => 'cooperativa',
  );
  $translatables['miembros'] = array(
    t('Master'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Ascendente'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
  );
  $export['miembros'] = $view;

  $view = new view;
  $view->name = 'redes_sociales_cooperativas';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'redes_sociales_cooperativas';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Campo: Contenido: RSS */
  $handler->display->display_options['fields']['field_rss']['id'] = 'field_rss';
  $handler->display->display_options['fields']['field_rss']['table'] = 'field_data_field_rss';
  $handler->display->display_options['fields']['field_rss']['field'] = 'field_rss';
  $handler->display->display_options['fields']['field_rss']['label'] = '';
  $handler->display->display_options['fields']['field_rss']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_rss']['alter']['text'] = '<a class="logorss logosrs" title="RSS [title]" href="[field_rss-value]"></a>';
  $handler->display->display_options['fields']['field_rss']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_rss']['alter']['path'] = '[field_rss]';
  $handler->display->display_options['fields']['field_rss']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_rss']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_rss']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_rss']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_rss']['alter']['alt'] = 'RSS [title]';
  $handler->display->display_options['fields']['field_rss']['alter']['link_class'] = 'logosredes logorss';
  $handler->display->display_options['fields']['field_rss']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_rss']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_rss']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_rss']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_rss']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_rss']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_rss']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rss']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_rss']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_rss']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_rss']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_rss']['field_api_classes'] = 0;
  /* Campo: Contenido: Facebook */
  $handler->display->display_options['fields']['field_facebook']['id'] = 'field_facebook';
  $handler->display->display_options['fields']['field_facebook']['table'] = 'field_data_field_facebook';
  $handler->display->display_options['fields']['field_facebook']['field'] = 'field_facebook';
  $handler->display->display_options['fields']['field_facebook']['label'] = '';
  $handler->display->display_options['fields']['field_facebook']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_facebook']['alter']['text'] = '<a class="logofacebook logosrs" title="Facebook [title]" href="[field_facebook-value]"></a>';
  $handler->display->display_options['fields']['field_facebook']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_facebook']['alter']['path'] = '[field_facebook]';
  $handler->display->display_options['fields']['field_facebook']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_facebook']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_facebook']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_facebook']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_facebook']['alter']['alt'] = 'Facebook [title]';
  $handler->display->display_options['fields']['field_facebook']['alter']['link_class'] = 'logosredes logofacebook';
  $handler->display->display_options['fields']['field_facebook']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_facebook']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_facebook']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_facebook']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_facebook']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_facebook']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_facebook']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_facebook']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_facebook']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_facebook']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_facebook']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_facebook']['field_api_classes'] = 0;
  /* Campo: Contenido: Identi.ca */
  $handler->display->display_options['fields']['field_identica']['id'] = 'field_identica';
  $handler->display->display_options['fields']['field_identica']['table'] = 'field_data_field_identica';
  $handler->display->display_options['fields']['field_identica']['field'] = 'field_identica';
  $handler->display->display_options['fields']['field_identica']['label'] = '';
  $handler->display->display_options['fields']['field_identica']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_identica']['alter']['text'] = '<a class="logoidentica logosrs" title="Identi.ca [title]" href="[field_identica-value]"></a>';
  $handler->display->display_options['fields']['field_identica']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_identica']['alter']['path'] = '[field_identica]';
  $handler->display->display_options['fields']['field_identica']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_identica']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_identica']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_identica']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_identica']['alter']['alt'] = 'Identi.ca [title]';
  $handler->display->display_options['fields']['field_identica']['alter']['link_class'] = 'logosredes logoidentica';
  $handler->display->display_options['fields']['field_identica']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_identica']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_identica']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_identica']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_identica']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_identica']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_identica']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_identica']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_identica']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_identica']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_identica']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_identica']['field_api_classes'] = 0;
  /* Campo: Contenido: Twitter */
  $handler->display->display_options['fields']['field_twitter']['id'] = 'field_twitter';
  $handler->display->display_options['fields']['field_twitter']['table'] = 'field_data_field_twitter';
  $handler->display->display_options['fields']['field_twitter']['field'] = 'field_twitter';
  $handler->display->display_options['fields']['field_twitter']['label'] = '';
  $handler->display->display_options['fields']['field_twitter']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_twitter']['alter']['text'] = '<a class="logotwitter logosrs" title="Twitter [title]" href="[field_twitter-value]"></a>';
  $handler->display->display_options['fields']['field_twitter']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_twitter']['alter']['path'] = '[field_twitter]';
  $handler->display->display_options['fields']['field_twitter']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_twitter']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_twitter']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_twitter']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_twitter']['alter']['alt'] = 'Twitter [title]';
  $handler->display->display_options['fields']['field_twitter']['alter']['link_class'] = 'logosredes logotwitter';
  $handler->display->display_options['fields']['field_twitter']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_twitter']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_twitter']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_twitter']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_twitter']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_twitter']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_twitter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_twitter']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_twitter']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_twitter']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_twitter']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_twitter']['field_api_classes'] = 0;
  /* Campo: Contenido: YouTube */
  $handler->display->display_options['fields']['field_youtube']['id'] = 'field_youtube';
  $handler->display->display_options['fields']['field_youtube']['table'] = 'field_data_field_youtube';
  $handler->display->display_options['fields']['field_youtube']['field'] = 'field_youtube';
  $handler->display->display_options['fields']['field_youtube']['label'] = '';
  $handler->display->display_options['fields']['field_youtube']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_youtube']['alter']['text'] = '<a class="logoyoutube logosrs" title="YouTube [title]" href="[field_youtube-value]"></a>';
  $handler->display->display_options['fields']['field_youtube']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_youtube']['alter']['path'] = '[field_youtube]';
  $handler->display->display_options['fields']['field_youtube']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_youtube']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_youtube']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_youtube']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_youtube']['alter']['alt'] = 'YouTube [title] ';
  $handler->display->display_options['fields']['field_youtube']['alter']['link_class'] = 'logosredes logoyoutube';
  $handler->display->display_options['fields']['field_youtube']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_youtube']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_youtube']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_youtube']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_youtube']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_youtube']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_youtube']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_youtube']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_youtube']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_youtube']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_youtube']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_youtube']['field_api_classes'] = 0;
  /* Campo: Contenido: Correo Electrónico */
  $handler->display->display_options['fields']['field_correoelectronico']['id'] = 'field_correoelectronico';
  $handler->display->display_options['fields']['field_correoelectronico']['table'] = 'field_data_field_correoelectronico';
  $handler->display->display_options['fields']['field_correoelectronico']['field'] = 'field_correoelectronico';
  $handler->display->display_options['fields']['field_correoelectronico']['label'] = '';
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['text'] = '<a class="logocorreo logosrs" title="Correo Electrónico [title]" href="mailto:[field_correoelectronico-value]"></a>';
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['path'] = 'mailto:[field_correoelectronico]';
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['alt'] = 'Correo Electrónico [title]';
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['link_class'] = 'logosredes logocorreo';
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_correoelectronico']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_correoelectronico']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_correoelectronico']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_correoelectronico']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_correoelectronico']['field_api_classes'] = 0;
  /* Criterio de ordenación: Contenido: Fecha del envío */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contextual: Contenido: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Criterios de filtrado: Contenido: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterios de filtrado: Contenido: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cooperativa' => 'cooperativa',
  );
  $translatables['redes_sociales_cooperativas'] = array(
    t('Master'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Ascendente'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('<a class="logorss logosrs" title="RSS [title]" href="[field_rss-value]"></a>'),
    t('[field_rss]'),
    t('RSS [title]'),
    t('<a class="logofacebook logosrs" title="Facebook [title]" href="[field_facebook-value]"></a>'),
    t('[field_facebook]'),
    t('Facebook [title]'),
    t('<a class="logoidentica logosrs" title="Identi.ca [title]" href="[field_identica-value]"></a>'),
    t('[field_identica]'),
    t('Identi.ca [title]'),
    t('<a class="logotwitter logosrs" title="Twitter [title]" href="[field_twitter-value]"></a>'),
    t('[field_twitter]'),
    t('Twitter [title]'),
    t('<a class="logoyoutube logosrs" title="YouTube [title]" href="[field_youtube-value]"></a>'),
    t('[field_youtube]'),
    t('YouTube [title] '),
    t('<a class="logocorreo logosrs" title="Correo Electrónico [title]" href="mailto:[field_correoelectronico-value]"></a>'),
    t('mailto:[field_correoelectronico]'),
    t('Correo Electrónico [title]'),
    t('Todo(s)'),
  );
  $export['redes_sociales_cooperativas'] = $view;

  return $export;
}
