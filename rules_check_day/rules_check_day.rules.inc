<?php
/**
 * Implements of hook_rules_condition_info().
 */

function rules_check_day_rules_condition_info() {
  return array(
    'rules_check_day_condition_day_of_week' => array(
      'label' => t('Check the opening days'),
      'arguments' => array(
        'day check' => array('type' => 'text', 'label' => t('check day')),
        'day to compare' => array('type' => 'text', 'label' => t('day of week'), 'options list' => 'rules_check_day_weekday_options'),
	    'op' => array('type' => 'text', 'label' => t('Operator'), 'description' => t('The comparison operator.  For comparison purposes, days are ordered 1 (for           Monday) through 7 (for Sunday).'), 'options list' => 'rules_check_day_time_comparison_options')
      ),
      'module' => 'rules_check_day',
      'group' => 'Custom'
    )
  );
}

/**
 * Options list callback for condition day_of_week.
 */
function rules_check_day_weekday_options() {
  return array(
    'Mon' => t('Monday'),
    'Tue' => t('Tuesday'),
    'Wed' => t('Wednesday'),
    'Thu' => t('Thursday'),
    'Fri' => t('Friday'),
    'Sat' => t('Saturday'),
    'Sun' => t('Sunday')
  );
}


/**
 * Options list callback for time comparison operators.
 */
function rules_check_day_time_comparison_options() {
  return array(
    '==' => t('equals'),
    '<' => t('is before'),
    '>' => t('is after')
  );
}

/**
 * condition options for rules_datecheck_date_format
 */
function rules_check_day_date_format_options() {
  return array(
    'Y' => t('Year, yyyy'),
    'Y-m' => t('Month, yyyy-mm'),
    'Y-m-d' => t('Day, yyyy-mm-dd'),
    'Y-\WW' => t('Week, yyyy-ww')
  );
}

/**
 * Condition rules_check_horaires_condition_day_of_week
 */
function rules_check_day_condition_day_of_week($field, $day, $op) {
  // Let date() get the number for the chosen day.
  $day = date('N', strtotime($day));
  $field = date('N', strtotime($field));
  // Return operation result.
  switch($op) {
    case '==':
      return $field == $day;
    case '>':
      return $field > $day;
    case '<':
      return $field < $day;
  }
}

/**
 * condition: provide date as text in Y-m-d format
 */

function rules_check_day_date_format($date, $format) {
  $date = date($format, $date);
  return array(
   'date_as_text' => $date,
  );
}
