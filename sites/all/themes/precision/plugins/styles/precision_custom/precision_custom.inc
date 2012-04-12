<?php

$plugin = array(
  'title' => t('Precision custom style'),
  'description' => t('Wraps panels or panes in a custom style.'),
  'render panel' => 'precision_custom_render_panel',
  'render pane' => 'precision_custom_render_pane',
  'settings form' => 'precision_custom_settings_form',
  'settings form submit' => 'precision_custom_settings_form_submit',
  'pane settings form' => 'precision_custom_settings_form',
  'pane settings form submit' => 'precision_custom_settings_form_submit',
  'hook theme' => array(
    'precision_custom' => array(
      'arguments' => array('content' => NULL, 'settings' => array()),
    ),
  ),
  'default' => array(
    'prefix' => '',
    'prefix_filter' => filter_default_format(),
    'suffix' => '',
    'suffix_filter' => filter_default_format(),
  )
);

/**
 * Theme function for a grid.
 */
function theme_precision_custom($content, $settings) {
  if (!empty($content)) {
    return $settings['prefix'] . $content . $settings['suffix'];
  }
}

/**
 * Theme function for the panel style.
 */
function theme_precision_custom_render_panel($display, $panel_id, $panes, $settings) {
  $output = '';
  foreach ($panes as $pane_id => $pane) {
    $output .= panels_render_pane($pane, $display->content[$pane_id], $display);
  }
  return theme('precision_grid', $output, $settings);
}

/**
 * Theme function for the pane style.
 */
function theme_precision_custom_render_pane($content, $pane, $display) {
  $output = theme('panels_pane', $content, $pane, $display);
  return theme('precision_custom', $output, $pane->style['settings']);
}

/**
 * Helper function for the setting forms.
 */
function precision_custom_settings_form($settings) {
  $form = array();

  $form['prefix'] = array(
    '#type' => 'textarea',
    '#title' => t('Prefix'),
    '#default_value' => isset($settings['prefix']) ? $settings['prefix'] : '',
  );

  $form['suffix'] = array(
    '#type' => 'textarea',
    '#title' => t('Suffix'),
    '#default_value' => isset($settings['suffix']) ? $settings['suffix'] : '',
  );

  return $form;
}
