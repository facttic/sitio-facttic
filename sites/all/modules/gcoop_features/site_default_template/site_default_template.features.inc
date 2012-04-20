<?php
/**
 * @file
 * site_default_template.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function site_default_template_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
