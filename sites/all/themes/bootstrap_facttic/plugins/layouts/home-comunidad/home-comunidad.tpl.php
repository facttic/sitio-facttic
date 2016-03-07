  <section class="slider">

    <div class="row">
    <?php if (!empty($content['slider'])): ?>
      <div class="col-md-12">
        <?php print render($content['slider']); ?>
      </div>
    <?php endif; ?>
    </div>

  </section>
  <div class="banner-container">
  <section class="info-usuario">

    <div class="row">
    <?php if (!empty($content['datos-usuario'])): ?>
      <div class="col-md-4 col-sm-8">
        <?php print render($content['datos-usuario']); ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($content['categoria-usuario'])): ?>
      <div class="col-md-2 col-sm-3">
        <?php print render($content['categoria-usuario']); ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($content['banner1'])): ?>
      <div class="col-md-6 col-sm-12">
        <?php print render($content['banner1']); ?>
      </div>
    <?php endif; ?>
    </div>

  </section>
  <section class="banners-internos">

    <div class="row">
    <?php if (!empty($content['banner2'])): ?>
      <div class="col-md-12">
        <?php print render($content['banner2']); ?>
      </div>
    <?php endif; ?>
    </div>

    <div class="row">
    <?php if (!empty($content['banner3'])): ?>
      <div class="col-md-4">
        <?php print render($content['banner3']); ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($content['banner4'])): ?>
      <div class="col-md-4">
        <?php print render($content['banner4']); ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($content['banner5'])): ?>
      <div class="col-md-4">
        <?php print render($content['banner5']); ?>
      </div>
    <?php endif; ?>
    </div>

    <div class="row">
    <?php if (!empty($content['banner6'])): ?>
      <div class="col-md-4">
        <?php print render($content['banner6']); ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($content['banner7'])): ?>
      <div class="col-md-8">
        <?php print render($content['banner7']); ?>
      </div>
    <?php endif; ?>

    </div>
  </section>
  <section class="contacto">
    <div class="row">
    <?php if (!empty($content['contacto'])): ?>
      <div class="col-md-12">
        <?php print render($content['contacto']); ?>
      </div>
    <?php endif; ?>
    </div>
  </section>
  <section class="banners-terceros">

    <div class="row">
    <?php if (!empty($content['banner8'])): ?>
      <div class="col-md-4">
        <?php print render($content['banner8']); ?>
      </div>
      <?php endif; ?>
      <?php if (!empty($content['banner9'])): ?>
      <div class="col-md-4">
        <?php print render($content['banner9']); ?>
      </div>
      <?php endif; ?>
      <?php if (!empty($content['banner10'])): ?>
      <div class="col-md-4">
        <?php print render($content['banner10']); ?>
      </div>
    <?php endif; ?>

    </div>
  </section>
  </div>
