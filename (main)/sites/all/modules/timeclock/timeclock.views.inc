<?php

/**
 * Implements hook_views_data_alter().
 * @param $data
 */
function timeclock_views_data_alter(&$data) {
  $data['eck_punch']['date_filter']['filter']['handler'] = 'timeclock_handler_filter_payperiods';    
}

