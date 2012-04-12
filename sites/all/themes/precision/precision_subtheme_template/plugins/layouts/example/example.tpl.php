<?php

/**
 * @file
 * This layout is intended to be used inside the page content pane. Thats why
 * there is not wrapper div by default.
 */
?>
<?php if (!empty($css_id)): ?>
  <div id="<?php print $css_id; ?>" class="clearfix">
<?php endif; ?>

<?php if (!empty($content['header_alpha'])): ?>
  <div class="page-header-alpha grid-48 alpha omega">
    <div class="sub-region page-header-alpha-inner clearfix">
      <?php print render($content['header_alpha']); ?>
    </div>
  </div>
<?php endif; ?>

<div class="page-main-wrapper grid-36 alpha">

  <?php if (!empty($content['header_beta'])): ?>
    <div class="page-header-beta grid-36 alpha omega">
      <div class="sub-region page-header-beta-inner clearfix">
        <?php print render($content['header_beta']); ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['main'])): ?>
    <div class="page-main grid-24 alpha">
      <div class="sub-region page-main-inner clearfix">
        <?php print render($content['main']); ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['aside_alpha'])): ?>
    <div class="page-aside-alpha grid-12 omega">
      <div class="sub-region page-aside-alpha-inner clearfix">
        <?php print render($content['aside_alpha']); ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['footer_alpha'])): ?>
    <div class="page-footer-alpha grid-36 alpha omega">
      <div class="sub-region page-footer-alpha-inner clearfix">
        <?php print render($content['footer_alpha']); ?>
      </div>
    </div>
  <?php endif; ?>

</div>

<?php if (!empty($content['aside_beta'])): ?>
  <div class="page-aside-beta grid-12 omega">
    <div class="sub-region page-aside-beta-inner clearfix">
      <?php print render($content['aside_beta']); ?>
    </div>
  </div>
<?php endif; ?>

<?php if (!empty($content['footer_beta'])): ?>
  <div class="page-footer-beta grid-48 alpha omega">
    <div class="sub-region page-footer-beta-inner clearfix">
      <?php print render($content['footer_beta']); ?>
    </div>
  </div>
<?php endif; ?>

<?php if (!empty($css_id)): ?>
  </div>
<?php endif; ?>
