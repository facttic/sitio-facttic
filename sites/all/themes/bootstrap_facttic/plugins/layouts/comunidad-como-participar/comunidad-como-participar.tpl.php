<div class="contenedor-como-participar">
  <div class="row seccion">
    <div class="col-md-12 informacion-subtitulo">
      <?php if (!empty($content['informacion-subtitulo'])): ?>
        <div>
          <?php print render($content['informacion-subtitulo']); ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
  <section class="row seccion condiciones-categorias">
      <div class="col-md-3 categoria-1">
        <?php if (!empty($content['condicion-categoria-1'])): ?>
          <div class="categoria">
            <?php print render($content['condicion-categoria-1']); ?>
          </div>
        <?php endif; ?>
      </div>
      <div class="col-md-3 categoria-2">
        <?php if (!empty($content['condicion-categoria-2'])): ?>
          <div class="categoria">
            <?php print render($content['condicion-categoria-2']); ?>
          </div>
        <?php endif; ?>
      </div>
      <div class="col-md-3 categoria-3">
        <?php if (!empty($content['condicion-categoria-3'])): ?>
          <div class="categoria">
            <?php print render($content['condicion-categoria-3']); ?>
          </div>
        <?php endif; ?>
      </div>
      <div class="col-md-3 categoria-4">
        <?php if (!empty($content['condicion-categoria-4'])): ?>
          <div class="categoria">
            <?php print render($content['condicion-categoria-4']); ?>
          </div>
        <?php endif; ?>
      </div>
  </section>
  <section class="seccion compensacion-pesos">
    <div class="row">
      <div class="col-md-12 tabla-compensacion-pesos">
        <?php if (!empty($content['tabla-compensacion-pesos'])): ?>
          <div>
            <?php print render($content['tabla-compensacion-pesos']); ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </section>
  <section class="seccion planificacion">
    <div class="row">
      <div class="col-md-12 tabla-planificacion">
        <?php if (!empty($content['tabla-planificacion'])): ?>
          <div>
            <?php print render($content['tabla-planificacion']); ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </section>
  <div class="row seccion importante">
    <div class="col-md-12 informacion-extra">
      <?php if (!empty($content['informacion-extra'])): ?>
        <div>
          <?php print render($content['informacion-extra']); ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
</div>
