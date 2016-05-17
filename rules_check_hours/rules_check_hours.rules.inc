<?php

/**
 * Implementation of hook_rules_condition_info()
 *
 * Rules conditions for checking the time.
 */
function rules_check_hours_rules_condition_info() {
  return array(
    'rules_check_hours_condition_hour_of_day' => array(
      'label' => t('Check the opening hours'),
      'arguments' => array(
        'hour check' => array('type' => 'text', 'label' => t('check hour')),
        'hour to compare' => array('type' => 'text', 'label' => t('hour of day'), 'options list' => 'rules_check_hours_hour_options', 'description' => t('24-hour format')), 
	    'op' => array('type' => 'text', 'label' => t('Operator'), 'options list' => 'rules_check_hours_time_comparison_options')
      ),
      'module' => 'rules_check_hours',
      'group' => 'Custom'
    )
  );
}


/**
 * Options list callback for condition hour_of_day.
 */
function rules_check_hours_hour_options() {
 return array('00','01','02','03','04','05','06','07','08','09','10','11','12','13','14','15','16','17','18','19','20','21','22','23');
}

/**
 * Options list callback for time comparison operators.
 */
function rules_check_hours_time_comparison_options() {
  return array(
    '==' => t('equals'),
    '<' => t('is before'),
    '>' => t('is after'),
  );
}

/**
 * condition options for rules_datecheck_date_format
 */
function rules_check_hours_date_format_options() {
  return array(
    'Y' => t('Year, yyyy'),
    'Y-m' => t('Month, yyyy-mm'),
    'Y-m-d' => t('Day, yyyy-mm-dd'),
    'Y-\WW' => t('Week, yyyy-ww'),
  );
}

/**
 * Condition rules_check_horaires_condition_hour_of_day
 */
function rules_check_hours_condition_hour_of_day($field, $hour, $op) {
  $field = date('H', strtotime($field));

  switch($op) {
    case '==':
      return $field == $hour;
    case '>':
      return $field > $hour;
    case '<':
      return $field < $hour;
  }
}

/**
 * condition: provide date as text in Y-m-d format
 */
function rules_check_hours_date_format($date, $format) {
  $date = date($format, $date);
  return array(
   'date_as_text' => $date,
  );
}
