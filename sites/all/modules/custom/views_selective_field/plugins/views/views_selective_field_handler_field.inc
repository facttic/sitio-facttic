<?php

/**
 * Field handler to render one of the other fields in the view based on
 * conditions.
 */
class views_selective_field_handler_field extends views_handler_field {
  const NUMBER_OF_FIELDS = 3;

  /**
   * Implements views_object#option_definition().
   */
  function option_definition() {
    $options = parent::option_definition();
    for ($i = 1; $i <= self::NUMBER_OF_FIELDS; ++$i) {
      $options['selective_field']['selective_field_' . $i] = array('default' => '');
    }
    return $options;
  }

  /**
   * Implements views_handler#options_form().
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['selective_field'] = array(
      '#type' => 'fieldset',
      '#title' => t('Selective field'),
      '#description' => t('The first non-empty field selected below will be used as the output of this field. You cannot use fields that come after this field; if you need a field not listed here, rearrange your fields.'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $options = $this->get_previous_fields();
    for ($i = 1; $i <= self::NUMBER_OF_FIELDS; ++$i) {
      $field_name = 'selective_field_' . $i;
      $form['selective_field'][$field_name] = array(
        '#type' => 'select',
        '#title' => t('Field ' . $i),
        '#description' => t('Enter the replacement pattern for field number @number.', array('@number' => $i)),
        '#default_value' => $this->options['selective_field'][$field_name],
        '#options' => $options,
      );
    }
  }

  /**
   * Implements views_handler_field#query().
   *
   * @see views_php_views_pre_execute()
   */
  function query() {
    // Provide an field alias but don't actually alter the query.
    $this->field_alias = 'selective_field_' . $this->position;
  }

  /**
   * Implements views_handler_field#render().
   */
  function render($values) {
    $handlers = $this->view->display_handler->get_handlers('field');
    foreach ($this->options['selective_field'] as $field) {
      if (!empty($field)) {
        $value = $handlers[$field]->advanced_render($values);
        $clean_value = trim(strip_tags($value, '<img>'));
        if (!empty($clean_value)) {
          return $value;
        }
      }
    }
    return '';
  }

  /**
   * Returns a list of available fields to add to a form element.
   */
  function get_previous_fields() {
    $options = array('' => '- '. t('None') . ' -');
    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
      // We only use fields up to (not including) this one.
      if ($field == $this->options['id']) {
        break;
      }
      $options[$field] = $handler->ui_name();
    }
    return $options;
  }
}
