<?php

/**
 * Template using twitter bootstrap for panels everywhere.
 * It assumes a modified version of bootstrap with 24 columns.
 *
 * Use only menus in the Navigation region.
 */

?>

<?php

/**
 * @file
 * This layout is intended to be used inside the page content pane. Thats why
 * there is not wrapper div by default.
 */
?>


  <div class="row">
  <?php print render($content['main']); ?>
    <div class="col-md-4">
    <!-- mapa-miembros  bloque-cooperativa -->
      <?php print render($content['main_left']); ?>
    </div>
    <div class="col-md-8">
    <!-- listademiembros bloque-cooperativa -->
      <?php print render($content['main_right']); ?>
    </div>
  </div>







