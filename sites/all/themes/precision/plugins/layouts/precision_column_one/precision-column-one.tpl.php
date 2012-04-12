<?php
?>

<?php if (!empty($css_id)): ?>
  <div id="<?php print $css_id; ?>" class="clearfix">
<?php endif; ?>

<?php if (!empty($content['main'])): ?>
  <div class="page-main grid-48 alpha omega">
    <div class="sub-region page-main-inner clearfix">
      <?php print render($content['main']); ?>
    </div>
  </div>
<?php endif; ?>

<?php if (!empty($css_id)): ?>
  </div>
<?php endif; ?>
