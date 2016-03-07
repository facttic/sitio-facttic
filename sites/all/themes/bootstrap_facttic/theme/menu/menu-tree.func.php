<?php
/**
 * @file
 * menu-tree.func.php
 */

/**
 * Overrides theme_menu_tree().
 */
function bootstrap_facttic_menu_tree(&$variables) {
  return '<ul class="menu"> holis' . $variables['tree'] . '</ul>';
}