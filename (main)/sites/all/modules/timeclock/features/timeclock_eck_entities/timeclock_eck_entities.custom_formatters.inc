<?php
/**
 * @file
 * timeclock_eck_entities.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function timeclock_eck_entities_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'seconds_to_h_m_s';
  $formatter->label = 'seconds to H:M:S';
  $formatter->description = 'convert a number of seconds to Hours Minutes and Seconds for human readable display';
  $formatter->mode = 'php';
  $formatter->field_types = 'number_integer';
  $formatter->code = 'return sprintf("%02d%s%02d%s%02d", floor($variables[\'#items\'][0][\'value\']/3600), \':\', ($variables[\'#items\'][0][\'value\']/60)%60, \':\', $variables[\'#items\'][0][\'value\']%60);';
  $formatter->fapi = '';
  $export['seconds_to_h_m_s'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'ssn_mask';
  $formatter->label = 'SSN Mask';
  $formatter->description = 'Show only the last 4 digits of a SSN';
  $formatter->mode = 'php';
  $formatter->field_types = 'number_integer';
  $formatter->code = '$element = array();
foreach ($variables[\'#items\'] as $delta => $item) {
  $element[$delta] = array(
    \'#markup\' => \'###-##-\'.substr($item[\'value\'], -4),
  );
}
return $element;
';
  $formatter->fapi = '';
  $export['ssn_mask'] = $formatter;

  return $export;
}
