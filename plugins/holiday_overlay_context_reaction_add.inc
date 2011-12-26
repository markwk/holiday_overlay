<?php
// $Id:

/**
 * @file
 *   Adds a Context module reaction for the Holiday Overlay module.
 */

/**
 * Add Holiday Overlay code to the page.
 */
class holiday_overlay_context_reaction_add extends context_reaction {

  function options_form($context) {
    return array(
      'add' => array('#type' => 'value', '#value' => TRUE),
      'note' => array('#type' => 'markup', '#value' => t('Holiday Overlay will be added to the page.')),
    );
  }

  function options_form_submit($values) {
    return array('add' => 1);
  }

  function execute() {
    $contexts = $this->get_contexts();
    foreach ($contexts as $context) {
      if (!empty($context->reactions[$this->plugin])) {
        return TRUE;
      }
    }
  }
}
