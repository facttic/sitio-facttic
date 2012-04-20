<?php
/**
 * @file
 * site_default_template.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function site_default_template_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'footer';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer';
  $fe_block_boxes->body = '<div class="uso">
    <div class="navegador">
	Este sitio se ve mejor con <a class="firefox" target="_blank" href="http://www.gcoop.coop/" title="Firefox"><span>Firefox</span>
	</a>
    </div>
</div>';

  $export['footer'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'logos-miembros';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'logos_miembros';
  $fe_block_boxes->body = '<?php $baseurl = url(\'sites/all/themes/precision/images\', array(\'absolute\' => true)); ?>
<div class="miembros">
     <div class="logoscoops">
	<a class="logoc" target="_blank" href="http://www.gcoop.coop/" title="GCOOP">
		<img src="<?php print $baseurl; ?>/gcoop.png"/>
		<span></span>
	</a>
        <a class="logoc" target="_blank" href="http://devecoop.com/" title="DEVECOOP">
		<img src="<?php print $baseurl; ?>/devecoop.png"/>
		<span></span>
	</a>	
        <a class="logoc" target="_blank" href="http://www.fiqus.com/" title="FIQUS">
		<img src="<?php print $baseurl; ?>/fiqus.png"/>
		<span></span>
	</a>	
       <a class="logoc" target="_blank" href="http://www.colectivolibre.com.ar/" title="COLECTIVO LIBRE">
		<img src="<?php print $baseurl; ?>/colectivolibre.png"/>
		<span></span>
	</a>	
	<a class="logoc" target="_blank" href="http://unixono.com.ar/" title="UNIXONO">
		<img src="<?php print $baseurl; ?>/unixono.png"/>
		<span></span>
	</a>
        <a class="logoc" target="_blank" href="http://www.tecso.coop/" title="TECSO">
		<img src="<?php print $baseurl; ?>/tecso.png"/>
		<span></span>
	</a>
       <a class="logoc" target="_blank" href="http://www.elvex.org.ar/" title="ELVEX">
		<img src="<?php print $baseurl; ?>/elvex.png"/>
		<span></span>
	</a> 
        <a class="logoc" target="_blank" href="http://www.hego.com.ar/" title="HEGO">
		<img src="<?php print $baseurl; ?>/hego.png"/>
       <span></span>
     </a>
          <a class="logoc" target="_blank" href="http://infracoop.com.ar/" title="INFRACOOP">
       <img src="<?php print $baseurl; ?>/infracoop.png"/>
		<span></span>
	</a>
        <a class="logoc" target="_blank" href="https://sites.google.com/a/it10coop.com.ar/it10/" title="IT10">
		<img src="<?php print $baseurl; ?>/it10.png"/>
		<span></span>
	</a>
     </div>
   </div>';

  $export['logos_miembros'] = $fe_block_boxes;

  return $export;
}
