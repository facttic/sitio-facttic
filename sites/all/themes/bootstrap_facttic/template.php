<?php

/**
 * @file
 * template.php
 */


function bootstrap_facttic_preprocess_page(&$variables) {
	//Se agrega el script de migracion de drupal para que no haya conflictos con el mise
	drupal_add_js('http://code.jquery.com/jquery-migrate-1.2.1.js', 'external');
}

/**
 * Override or insert variables into the page template for HTML output.
 */
function bootstrap_facttic_process_html(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($variables);
  }
}

/**
 * Override or insert variables into the page template.
 */
function bootstrap_facttic_process_page(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($variables);
  }
}

function bootstrap_facttic_preprocess_html(&$variables) {
  drupal_add_css('https://fonts.googleapis.com/css?family=Rambla:400,400italic,700', array('type' => 'external'));
}
