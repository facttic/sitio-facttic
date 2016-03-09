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
    <div class="col-md-9">
    <!-- titulo-noticia-completa -->
    <!-- fecha-noticia-completa -->
    <!-- img-cuerpo-noticia -->
      <?php print render($content['main_left']); ?>
    </div>
    <div class="col-md-3">
    <!-- logocoop-noticias -->
      <?php print render($content['main_right']); ?>
    </div>
  </div>







