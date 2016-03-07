<div class="contenedor-canje-credito">
<div class="row seccion">
  <div class="col-md-4 informacion-usuario">
    <?php if (!empty($content['informacion-usuario'])): ?>
      <div>
        <?php print render($content['informacion-usuario']); ?>
      </div>
    <?php endif; ?>
  </div>
  <div class="col-md-4 emision-cheque">
    <?php if (!empty($content['emision-cheque'])): ?>
      <div>
        <?php print render($content['emision-cheque']); ?>
      </div>
    <?php endif; ?>
  </div>    
  <div class="col-md-2 col-md-offset-1 categoria-usuario">
    <?php if (!empty($content['categoria-usuario'])): ?>
      <div>
        <?php print render($content['categoria-usuario']); ?>
      </div>
    <?php endif; ?>
  </div>    
</div>

<div class="row seccion">
  <div class="col-md-12 listado">
    <?php if (!empty($content['listado-cheques'])): ?>
      <div>
        <?php print render($content['listado-cheques']); ?>
      </div>
    <?php endif; ?>
  </div>
</div>

<div class="row seccion">
  <div class="col-md-12 titulo-productos-comprados">
    <?php if (!empty($content['titulo-productos-comprados'])): ?>
      <div>
        <?php print render($content['titulo-productos-comprados']); ?>
      </div>
    <?php endif; ?>
  </div>
  <div class="col-md-5 listado-productos-comprados">
    <?php if (!empty($content['listado-productos-comprados'])): ?>
      <div>
        <?php print render($content['listado-productos-comprados']); ?>
      </div>
    <?php endif; ?>
  </div>
  <div class="col-md-2 suma-total-productos-comprados">
    <?php if (!empty($content['suma-total-productos-comprados'])): ?>
      <div>
        <?php print render($content['suma-total-productos-comprados']); ?>
      </div>
    <?php endif; ?>
  </div>
  <div class="col-md-5 banner">
    <?php if (!empty($content['banner'])): ?>
      <div>
        <?php print render($content['banner']); ?>
      </div>
    <?php endif; ?>
  </div>
</div>

<div class="row seccion">
  <div class="col-md-12 cuenta-corriente">
    <?php if (!empty($content['cuenta-corriente'])): ?>
      <div>
        <?php print render($content['cuenta-corriente']); ?>
      </div>
    <?php endif; ?>
  </div>
</div>

<div class="row seccion">
  <div class="col-md-3 banner-contacto banner">
    <?php if (!empty($content['banner-contacto'])): ?>
      <div>
        <?php print render($content['banner-contacto']); ?>
      </div>
    <?php endif; ?>
  </div>
  <div class="col-md-9 disponibilidad-fondos">
    <?php if (!empty($content['disponibilidad-fondos'])): ?>
      <div>
        <?php print render($content['disponibilidad-fondos']); ?>
      </div>
    <?php endif; ?>
  </div>
</div>
</div>
