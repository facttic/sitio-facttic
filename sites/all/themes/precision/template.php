<?php

/**
 * Implementation of theme_panels_default_style_render_region().
 */
function precision_panels_default_style_render_region($vars) {
  return implode($vars['panes']);
}

/**
 * Generic function that modifies some variables in all Precision layouts.
 */
function precision_check_layout_variables(&$vars) {
  $vars['css_id'] = strtr($vars['css_id'], '_', '-');
}

/**
 * Implementation of template_process_html().
 */
function precision_process_html(&$variables, $hook) {
  // Check if overlay is activated.
  if (theme_get_setting('precision_show_overlay')) {
    // Extract and put back the body classes.
    $variables['classes_array'][] = 'show-grid';
    $variables['classes'] = implode(' ', $variables['classes_array']);
    // Add the overlay css to the page.
    $styles = (drupal_add_css(drupal_get_path('theme', 'precision') . '/debug/debug.css'));
    $variables['css'] = $styles;
    $variables['styles'] = drupal_get_css($variables['css']);
  }
  // Check if reset setting is active and throw in the reset.css
  if (theme_get_setting('precision_reset_css')) {
    $styles = drupal_add_css(drupal_get_path('theme', 'precision') . '/css/reset.css');
    $variables['css'] = $styles;
    $variables['styles'] = drupal_get_css($variables['css']);
  }
}

function precision_preprocess_panels_pane(&$vars){
  // Set variables for pane title element
  if(isset($vars['settings']['title_element']) && !empty($vars['settings']['title_element'])){
    $vars['title_element'] = $vars['settings']['title_element'];
  }
  else {
    $vars['title_element'] = 'h2';
  }
}
