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

<div id="skip-link">
  <a class="element-invisible element-focusable" href="#main-content"><?php print t('Jump to main content'); ?></a>
</div>

  <?php if (!empty($content['header'])): ?>
    <header class="header clearfix">
        <?php print render($content['header']); ?>
        <?php if (!empty($content['navbar'])): ?>
         <nav class="navbar navbar-default">
          <div class="container">
            <!-- Brand and toggle get grouped for better mobile display -->
            <div class="navbar-header">
              <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#main-menu-collapse">
                <!--<span class="sr-only">Toggle navigation</span>-->
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
              </button>
            </div>

            <!-- Collect the nav links, forms, and other content for toggling -->
            <div class="collapse navbar-collapse" id="main-menu-collapse">
                <?php print render($content['navbar']); ?>
            </div><!-- /.navbar-collapse -->
          </div><!-- /.container-fluid -->
        </nav>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php if (!empty($content['main'])): ?>
    <div class="row">
      <div class="col-md-4">
        <?php print render($content['main_left']); ?>
      </div>
      <div class="col-md-4">
        <?php print render($content['main_center']); ?>
      </div>
      <div class="col-md-4">
        <?php print render($content['main_right']); ?>
      </div>
    </div>
    <div class="row">
      <?php print render($content['main']); ?>
    </div>
    
  <?php endif; ?>    







