<?php

/**
 * Template using twitter bootstrap for panels everywhere.
 * It assumes a modified version of bootstrap with 24 columns.
 *
 * Use only menus in the Navigation region.
 */

?>

  <section class="top">
    <?php if (!empty($content['listado-noticias-resumen'])): ?>
        <?php print render($content['listado-noticias-resumen']); ?>
    <?php endif; ?>
  </section>
  <section class="main-content">
    <?php if (!empty($content['listado-noticias-completo'])): ?>
        <?php print render($content['listado-noticias-completo']); ?>
    <?php endif; ?>
  </section>
