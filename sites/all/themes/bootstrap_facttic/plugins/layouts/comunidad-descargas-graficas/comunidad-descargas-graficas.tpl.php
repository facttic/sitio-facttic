<?php

/**
 * Template using twitter bootstrap for panels everywhere.
 * It assumes a modified version of bootstrap with 24 columns.
 *
 * Use only menus in the Navigation region.
 */

?>
<div class="row">
  <div class="col-md-12">
    <?php if (!empty($content['texto'])): ?>
        <?php print render($content['texto']); ?>
    <?php endif; ?>
  </div>
</div>
<div class="row">

  <div class="col-izquierda col-md-9">
    <div class="title-listado-fondos-screen sub-titulo">
        <?php if (!empty($content['title-listado-fondos-screen'])): ?>
            <?php print render($content['title-listado-fondos-screen']); ?>
        <?php endif; ?>
    </div>
    <div class="row">
      <div class="col-md-6">
      <section class="fondos">
        <?php if (!empty($content['listado-fondos'])): ?>
            <?php print render($content['listado-fondos']); ?>
        <?php endif; ?>
      </section>
      </div>
      <div class="col-md-6">
      <section class="screen-savers">
        <?php if (!empty($content['listado-screen-saver'])): ?>
            <?php print render($content['listado-screen-saver']); ?>
        <?php endif; ?>
      </section>
      </div>
    </div>
      <div class="titulo-logos-extra sub-titulo">
        <?php if (!empty($content['title-logos-extra'])): ?>
            <?php print render($content['title-logos-extra']); ?>
        <?php endif; ?>
      </div>
    <div class="row"> 
      <div class="col-md-12">

      <section class="logos-extra">
        <?php if (!empty($content['listado-logos-extra'])): ?>
            <?php print render($content['listado-logos-extra']); ?>
        <?php endif; ?>
      </section>
      </div>
    </div>

  </div>

  <div class="col-derecha col-md-3">
    <section class="logos">
      <?php if (!empty($content['listado-logos'])): ?>
          <?php print render($content['listado-logos']); ?>
      <?php endif; ?>
    </section>
  </div>

</div>
