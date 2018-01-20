<?php

/**
 * @file
 * Administration forms for the timeclock module.
 */

/**
 * Page callback for admin page form.
 *
 * Default values for each variable are set on hook_install().
 */
function timeclock_admin() {
  $form = array();
 timeclock_current_payperiod();
  $form['timeclock_payperiod_length'] = array(
    '#type' => 'select',
    '#title' => t('Pay period length'),
    '#description' => t("Enter the length that each pay period lasts."),
    '#options' => array(
      1 => t('Weekly'),
      2 => t('Bi-Weekly'),
      4 => t('Monthly'),
    ),
    '#default_value' => variable_get('timeclock_payperiod_length'),
    '#required' => TRUE,
  );
  $form['timeclock_payperiod_start'] = array(
    '#type' => 'select',
    '#title' => t('Day of the week the payperiod starts.'),
    '#options' => array(
      0 => t('Sunday'),
      1 => t('Monday'),
      2 => t('Tuesday'),
      3 => t('Wednesday'),
      4 => t('Thursday'),
      5 => t('Friday'),
      6 => t('Saturday'),
    ),
    '#default_value' => variable_get('timeclock_payperiod_start'),
    '#description' => t('Select the day of the week that your pay period begins on. This value will be used to calculate the pay periods in the system.'),
    '#required' => TRUE,
  );
  $form['timeclock_payperiod_knowndate'] = array(
    '#type' => 'date',
    '#title' => t('Current Payperiod Start Date'),
    '#default_value' => variable_get('timeclock_payperiod_knowndate', NULL),
    '#description' => t('Enter the current payperiod`s start date. This will be used as a reference to calcuate the next and previous dates.'),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}

/**
 * Validates admin form submissions.
 * @param $form
 * @param $form_state
 */
function timeclock_admin_validate($form, &$form_state) {
  if (!is_numeric($form_state['values']['timeclock_payperiod_length'])) {
    form_set_error('timeclock_payperiod_length', t('You must enter a number for payperiod length.'));
  }
  $d = date('l', strtotime($form_state['values']['timeclock_payperiod_knowndate']['day'] . '-' .  $form_state['values']['timeclock_payperiod_knowndate']['month'] . '-' . $form_state['values']['timeclock_payperiod_knowndate']['year']));
  $start = $form_state['values']['timeclock_payperiod_start'];
  switch($start) {
    case 0:
      $t = 'Sunday';
      break;
    case 1:
      $t = 'Monday';
      break;
    case 2:
      $t = 'Tuesday';
      break;
    case 3:
      $t  = 'Wednesday';
      break;
    case 4:
      $t = 'Thursday';
      break;
    case 5:
      $t = 'Friday';
      break;
    case 6:
      $t = 'Saturday';
      break;
  }
  if ($d != $t) {
    form_set_error('timeclock_payperiod_knowndate', t('The date you enter must match the day of the week selected.') . t('"Current Payperiod Start Date" is a') . ': ' . $d);
  }
}