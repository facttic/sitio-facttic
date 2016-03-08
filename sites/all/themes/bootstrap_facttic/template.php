<?php

/**
 * @file
 * template.php
 */

/**
 * Override or insert variables into the page template for HTML output.
 */
function bootstrap_comunidad_process_html(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($variables);
  }
}

/**
 * Override or insert variables into the page template.
 */
function bootstrap_comunidad_process_page(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($variables);
  }
}

function bootstrap_comunidad_preprocess_html(&$variables) {
  drupal_add_css('https://fonts.googleapis.com/css?family=Rambla:400,400italic,700', array('type' => 'external'));
}