<?php

/**
 * Template using twitter bootstrap for panels everywhere.
 * It assumes a modified version of bootstrap with 24 columns.
 *
 * Use only menus in the Navigation region.
 */

?>


  <div class="row">
    <?php if (!empty($content['main'])): ?>
      <div>
        <?php print render($content['main']); ?>
      </div>
    <?php endif; ?>
  </div>
