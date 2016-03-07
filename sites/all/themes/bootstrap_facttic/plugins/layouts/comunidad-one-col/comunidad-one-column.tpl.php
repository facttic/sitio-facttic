<?php

/**
 * Template using twitter bootstrap for panels everywhere.
 * It assumes a modified version of bootstrap with 24 columns.
 *
 * Use only menus in the Navigation region.
 */

?>

  <div class="col-md-48">
    <?php if (!empty($content['main-cont'])): ?>
      <div>
        <?php print render($content['main-cont']); ?>
      </div>
    <?php endif; ?>
  </div>
