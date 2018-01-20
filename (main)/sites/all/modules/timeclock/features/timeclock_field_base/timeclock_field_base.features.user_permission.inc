<?php
/**
 * @file
 * timeclock_field_base.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function timeclock_field_base_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_active'.
  $permissions['create field_active'] = array(
    'name' => 'create field_active',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_authorized_weekly_hours'.
  $permissions['create field_authorized_weekly_hours'] = array(
    'name' => 'create field_authorized_weekly_hours',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_auths_documents'.
  $permissions['create field_auths_documents'] = array(
    'name' => 'create field_auths_documents',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_cleared_date'.
  $permissions['create field_cleared_date'] = array(
    'name' => 'create field_cleared_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_cleared_message'.
  $permissions['create field_cleared_message'] = array(
    'name' => 'create field_cleared_message',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_date_paid'.
  $permissions['create field_date_paid'] = array(
    'name' => 'create field_date_paid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_escalation_mail_sent'.
  $permissions['create field_escalation_mail_sent'] = array(
    'name' => 'create field_escalation_mail_sent',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_full_name'.
  $permissions['create field_full_name'] = array(
    'name' => 'create field_full_name',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_has_been_edited'.
  $permissions['create field_has_been_edited'] = array(
    'name' => 'create field_has_been_edited',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_hire_date'.
  $permissions['create field_hire_date'] = array(
    'name' => 'create field_hire_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_mail_sent'.
  $permissions['create field_mail_sent'] = array(
    'name' => 'create field_mail_sent',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_max_expected_shift_length'.
  $permissions['create field_max_expected_shift_length'] = array(
    'name' => 'create field_max_expected_shift_length',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_overtime_hours'.
  $permissions['create field_overtime_hours'] = array(
    'name' => 'create field_overtime_hours',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_payroll_approval'.
  $permissions['create field_payroll_approval'] = array(
    'name' => 'create field_payroll_approval',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_payroll_eid'.
  $permissions['create field_payroll_eid'] = array(
    'name' => 'create field_payroll_eid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create timeclock_exceptions_supervise'.
  $permissions['create timeclock_exceptions_supervise'] = array(
    'name' => 'create timeclock_exceptions_supervise',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_active'.
  $permissions['edit field_active'] = array(
    'name' => 'edit field_active',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_authorized_weekly_hours'.
  $permissions['edit field_authorized_weekly_hours'] = array(
    'name' => 'edit field_authorized_weekly_hours',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_auths_documents'.
  $permissions['edit field_auths_documents'] = array(
    'name' => 'edit field_auths_documents',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_cleared_date'.
  $permissions['edit field_cleared_date'] = array(
    'name' => 'edit field_cleared_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_cleared_message'.
  $permissions['edit field_cleared_message'] = array(
    'name' => 'edit field_cleared_message',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_date_paid'.
  $permissions['edit field_date_paid'] = array(
    'name' => 'edit field_date_paid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_escalation_mail_sent'.
  $permissions['edit field_escalation_mail_sent'] = array(
    'name' => 'edit field_escalation_mail_sent',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_full_name'.
  $permissions['edit field_full_name'] = array(
    'name' => 'edit field_full_name',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_has_been_edited'.
  $permissions['edit field_has_been_edited'] = array(
    'name' => 'edit field_has_been_edited',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_hire_date'.
  $permissions['edit field_hire_date'] = array(
    'name' => 'edit field_hire_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_mail_sent'.
  $permissions['edit field_mail_sent'] = array(
    'name' => 'edit field_mail_sent',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_max_expected_shift_length'.
  $permissions['edit field_max_expected_shift_length'] = array(
    'name' => 'edit field_max_expected_shift_length',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_overtime_hours'.
  $permissions['edit field_overtime_hours'] = array(
    'name' => 'edit field_overtime_hours',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_payroll_approval'.
  $permissions['edit field_payroll_approval'] = array(
    'name' => 'edit field_payroll_approval',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_payroll_eid'.
  $permissions['edit field_payroll_eid'] = array(
    'name' => 'edit field_payroll_eid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_active'.
  $permissions['edit own field_active'] = array(
    'name' => 'edit own field_active',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_authorized_weekly_hours'.
  $permissions['edit own field_authorized_weekly_hours'] = array(
    'name' => 'edit own field_authorized_weekly_hours',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_auths_documents'.
  $permissions['edit own field_auths_documents'] = array(
    'name' => 'edit own field_auths_documents',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_cleared_date'.
  $permissions['edit own field_cleared_date'] = array(
    'name' => 'edit own field_cleared_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_cleared_message'.
  $permissions['edit own field_cleared_message'] = array(
    'name' => 'edit own field_cleared_message',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_date_paid'.
  $permissions['edit own field_date_paid'] = array(
    'name' => 'edit own field_date_paid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_escalation_mail_sent'.
  $permissions['edit own field_escalation_mail_sent'] = array(
    'name' => 'edit own field_escalation_mail_sent',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_full_name'.
  $permissions['edit own field_full_name'] = array(
    'name' => 'edit own field_full_name',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_has_been_edited'.
  $permissions['edit own field_has_been_edited'] = array(
    'name' => 'edit own field_has_been_edited',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_hire_date'.
  $permissions['edit own field_hire_date'] = array(
    'name' => 'edit own field_hire_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_mail_sent'.
  $permissions['edit own field_mail_sent'] = array(
    'name' => 'edit own field_mail_sent',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_max_expected_shift_length'.
  $permissions['edit own field_max_expected_shift_length'] = array(
    'name' => 'edit own field_max_expected_shift_length',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_overtime_hours'.
  $permissions['edit own field_overtime_hours'] = array(
    'name' => 'edit own field_overtime_hours',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_payroll_approval'.
  $permissions['edit own field_payroll_approval'] = array(
    'name' => 'edit own field_payroll_approval',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_payroll_eid'.
  $permissions['edit own field_payroll_eid'] = array(
    'name' => 'edit own field_payroll_eid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own timeclock_exceptions_supervise'.
  $permissions['edit own timeclock_exceptions_supervise'] = array(
    'name' => 'edit own timeclock_exceptions_supervise',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit timeclock_exceptions_supervise'.
  $permissions['edit timeclock_exceptions_supervise'] = array(
    'name' => 'edit timeclock_exceptions_supervise',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_active'.
  $permissions['view field_active'] = array(
    'name' => 'view field_active',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_authorized_weekly_hours'.
  $permissions['view field_authorized_weekly_hours'] = array(
    'name' => 'view field_authorized_weekly_hours',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_auths_documents'.
  $permissions['view field_auths_documents'] = array(
    'name' => 'view field_auths_documents',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_cleared_date'.
  $permissions['view field_cleared_date'] = array(
    'name' => 'view field_cleared_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_cleared_message'.
  $permissions['view field_cleared_message'] = array(
    'name' => 'view field_cleared_message',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_date_paid'.
  $permissions['view field_date_paid'] = array(
    'name' => 'view field_date_paid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_escalation_mail_sent'.
  $permissions['view field_escalation_mail_sent'] = array(
    'name' => 'view field_escalation_mail_sent',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_full_name'.
  $permissions['view field_full_name'] = array(
    'name' => 'view field_full_name',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_has_been_edited'.
  $permissions['view field_has_been_edited'] = array(
    'name' => 'view field_has_been_edited',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_hire_date'.
  $permissions['view field_hire_date'] = array(
    'name' => 'view field_hire_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_mail_sent'.
  $permissions['view field_mail_sent'] = array(
    'name' => 'view field_mail_sent',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_max_expected_shift_length'.
  $permissions['view field_max_expected_shift_length'] = array(
    'name' => 'view field_max_expected_shift_length',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_overtime_hours'.
  $permissions['view field_overtime_hours'] = array(
    'name' => 'view field_overtime_hours',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_payroll_approval'.
  $permissions['view field_payroll_approval'] = array(
    'name' => 'view field_payroll_approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_payroll_eid'.
  $permissions['view field_payroll_eid'] = array(
    'name' => 'view field_payroll_eid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_active'.
  $permissions['view own field_active'] = array(
    'name' => 'view own field_active',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_authorized_weekly_hours'.
  $permissions['view own field_authorized_weekly_hours'] = array(
    'name' => 'view own field_authorized_weekly_hours',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_auths_documents'.
  $permissions['view own field_auths_documents'] = array(
    'name' => 'view own field_auths_documents',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_cleared_date'.
  $permissions['view own field_cleared_date'] = array(
    'name' => 'view own field_cleared_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_cleared_message'.
  $permissions['view own field_cleared_message'] = array(
    'name' => 'view own field_cleared_message',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_date_paid'.
  $permissions['view own field_date_paid'] = array(
    'name' => 'view own field_date_paid',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_escalation_mail_sent'.
  $permissions['view own field_escalation_mail_sent'] = array(
    'name' => 'view own field_escalation_mail_sent',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_full_name'.
  $permissions['view own field_full_name'] = array(
    'name' => 'view own field_full_name',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_has_been_edited'.
  $permissions['view own field_has_been_edited'] = array(
    'name' => 'view own field_has_been_edited',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_hire_date'.
  $permissions['view own field_hire_date'] = array(
    'name' => 'view own field_hire_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_mail_sent'.
  $permissions['view own field_mail_sent'] = array(
    'name' => 'view own field_mail_sent',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_max_expected_shift_length'.
  $permissions['view own field_max_expected_shift_length'] = array(
    'name' => 'view own field_max_expected_shift_length',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_overtime_hours'.
  $permissions['view own field_overtime_hours'] = array(
    'name' => 'view own field_overtime_hours',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_payroll_approval'.
  $permissions['view own field_payroll_approval'] = array(
    'name' => 'view own field_payroll_approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_payroll_eid'.
  $permissions['view own field_payroll_eid'] = array(
    'name' => 'view own field_payroll_eid',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own timeclock_exceptions_supervise'.
  $permissions['view own timeclock_exceptions_supervise'] = array(
    'name' => 'view own timeclock_exceptions_supervise',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view timeclock_exceptions_supervise'.
  $permissions['view timeclock_exceptions_supervise'] = array(
    'name' => 'view timeclock_exceptions_supervise',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
