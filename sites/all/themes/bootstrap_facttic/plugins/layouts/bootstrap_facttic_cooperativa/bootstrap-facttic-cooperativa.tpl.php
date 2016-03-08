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

<div>
  <div class="row">
  <?php print render($content['main']); ?>
    <div class="col-md-4">
    <!-- "el nodo se esta viendo" logo-->
      <?php print render($content['main_first_left']); ?>
    </div>
    <div class="col-md-4">
    <!-- direccion_sede  -->
      <?php print render($content['main_first_center']); ?>
    </div>
    <div class="col-md-4">
    <!-- mapa_sede -->
      <?php print render($content['main_first_right']); ?>
    </div>
  </div>
  <div class="row">
    <div class="col-md-4">
    <!-- contenidos_cooperativas -->
      <?php print render($content['main_second_left']); ?>
    </div>
    <div class="col-md-4">
    <!-- listademiembros bloque-cooperativa -->
      <?php print render($content['main_second_center']); ?>
    </div>
    <div class="col-md-4">
    <!-- listademiembros bloque-cooperativa -->
      <?php print render($content['main_second_right']); ?>
    </div>
  </div>
</div>






