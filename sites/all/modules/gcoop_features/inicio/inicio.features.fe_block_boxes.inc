<?php
/**
 * @file
 * inicio.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function inicio_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Widget de twitter con las cuentas oficiales de las cooperativas.';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'feed_twitter_cooperativas';
  $fe_block_boxes->body = '<div id="t_coment">
<?php
drupal_add_js(\'sites/all/libraries/jquery.tweetsanywhere/jquery.jtweetsanywhere-1.2.1.min.js\');
drupal_add_css(\'sites/all/libraries/jquery.tweetsanywhere/jquery.jtweetsanywhere-1.2.1.css\');

$usernames = array();

// Usamos el nombre de usuario guardado en el campo twitter de las cooperativas
$result = db_query(
  "SELECT 
  t.field_twitter_value 
  FROM {node} n 
  INNER JOIN {field_revision_field_twitter} t 
  ON t.revision_id = n.vid 
  WHERE n.type = \'cooperativa\' 
  ORDER BY RAND()");

foreach ($result as $cuenta) {
  $usernames[] = $cuenta->field_twitter_value;
}

?><script type="text/javascript">
  jQuery(\'#t_coment\').jTweetsAnywhere({
    username: [\'<?php echo implode("\',\'", $usernames) ?>\'],
    count: 20,
      showTweetFeed: {
         autorefresh: {
           mode: \'auto-insert\',
           interval: 5
         },
         paging: {
           mode: \'endless-scroll\'
         }
      }
  });
</script>
</div>';

  $export['feed_twitter_cooperativas'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Presentación-home';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'presentacion_home';
  $fe_block_boxes->body = 'lalala';

  $export['presentacion_home'] = $fe_block_boxes;

  return $export;
}
