<?php

class timeclock_handler_filter_payperiods extends date_views_filter_handler {
  function operators() {
    $operators = parent::operators();
    //unset($operators['<']);
    //unset($operators['<=']);
    //unset($operators['=']);
    //unset($operators['!=']);
    //unset($operators['>=']);
    //unset($operators['>']);
    //unset($operators['not between']);
    //unset($operators['empty']);
    //unset($operators['not empty']);
    unset($operators['regular_expression']);
    unset($operators['contains']);
    return $operators;
  }
  function date_default_value($prefix, $options = NULL) {
    $default_date = '';
    if (empty($options)) {
      $options = $this->options;
    }
    // If this is a remembered value, use the value from the SESSION.
    if (!empty($this->options['expose']['remember'])) {
      $display_id = ($this->view->display_handler->is_defaulted('filters')) ? 'default' : $this->view->current_display;
      if (!empty($_SESSION['views'][$this->view->name][$display_id]['date_filter'][$prefix])) {
        return $_SESSION['views'][$this->view->name][$display_id]['date_filter'][$prefix];
      }
    }

    // This is a date that needs to be constructed from options like 'now' .
    $default_option = $prefix == 'max' ? $options['default_to_date'] : $options['default_date'];
    if (!empty($default_option)) {
      str_replace('now', 'today', $default_option);
      $dates = timeclock_current_payperiod();
      switch ($default_option){
        case 'current-pay-period-start':
          $start = gmdate('Y-m-d',$dates['current']);
          $default_option = $start;
          break;
        case 'current-pay-period-end':
          $start = gmdate('Y-m-d',$dates['current']);
          $endtime = strtotime("$start +13 days");
          $end = gmdate('Y-m-d', $endtime);
          $default_option = $end;
          break;
        case 'past-pay-period-start':
          $start = gmdate('Y-m-d',$dates['previous']);
          $default_option = $start;
          break;
        case 'past-pay-period-end':
          $start = gmdate('Y-m-d',$dates['previous']);
          $endtime = strtotime("$start +13 days");
          $end = gmdate('Y-m-d', $endtime);
          $default_option = $end;
          break;
        case 'current-or-user-start':
          if (isset($_SESSION['timeclock_default_date_start'])){
            $start = gmdate('Y-m-d',$_SESSION['timeclock_default_date_start']);
          } else {
            $start = gmdate('Y-m-d',$dates['current']);
          }
          $default_option = $start;
          break;
        case 'current-or-user-end':
          if (isset($_SESSION['timeclock_default_date_end'])){
            $end = gmdate('Y-m-d', $_SESSION['timeclock_default_date_end']);
          } else {
            $start = gmdate('Y-m-d', $dates['current']);
            $endtime = strtotime("$start +13 days");
            $end = gmdate('Y-m-d', $endtime);
          }
          $default_option = $end;
          break;
      }
      $date = date_create($default_option, date_default_timezone_object());
      $default_date = !empty($date) ? $date->format($this->format) : '';

      // The format for our filter is in ISO format, but the widget will need it in datetime format.
      $default_date = str_replace('T', ' ', $default_date);
    }
    // This a fixed date.
    else {
      $default_date = $options['value'][$prefix];
    }
    return $default_date;
  }

}