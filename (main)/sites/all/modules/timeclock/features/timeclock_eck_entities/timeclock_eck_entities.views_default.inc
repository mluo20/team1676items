<?php
/**
 * @file
 * timeclock_eck_entities.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function timeclock_eck_entities_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'clocked_in_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_punch';
  $view->human_name = 'Clocked In Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Clocked In Users';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
    7 => '7',
    4 => '4',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_employee' => 'field_employee',
    'field_department' => 'field_department',
    'field_in' => 'field_in',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Header: Broken/missing handler */
  $handler->display->display_options['header']['autorefresh']['id'] = 'autorefresh';
  $handler->display->display_options['header']['autorefresh']['table'] = 'views';
  $handler->display->display_options['header']['autorefresh']['field'] = 'autorefresh';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_job_target_id']['id'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['table'] = 'field_data_field_job';
  $handler->display->display_options['relationships']['field_job_target_id']['field'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['required'] = TRUE;
  /* Field: Punch: Employee */
  $handler->display->display_options['fields']['field_employee']['id'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['table'] = 'field_data_field_employee';
  $handler->display->display_options['fields']['field_employee']['field'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['label'] = '';
  $handler->display->display_options['fields']['field_employee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_employee']['settings'] = array(
    'link' => 1,
  );
  /* Field: Job: Department */
  $handler->display->display_options['fields']['field_department']['id'] = 'field_department';
  $handler->display->display_options['fields']['field_department']['table'] = 'field_data_field_department';
  $handler->display->display_options['fields']['field_department']['field'] = 'field_department';
  $handler->display->display_options['fields']['field_department']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['fields']['field_department']['exclude'] = TRUE;
  /* Field: Punch: In */
  $handler->display->display_options['fields']['field_in']['id'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['table'] = 'field_data_field_in';
  $handler->display->display_options['fields']['field_in']['field'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['label'] = '';
  $handler->display->display_options['fields']['field_in']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_in']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_in']['settings'] = array(
    'interval' => '4',
    'interval_display' => 'time ago',
  );
  /* Sort criterion: Punch: In (field_in) */
  $handler->display->display_options['sorts']['field_in_value']['id'] = 'field_in_value';
  $handler->display->display_options['sorts']['field_in_value']['table'] = 'field_data_field_in';
  $handler->display->display_options['sorts']['field_in_value']['field'] = 'field_in_value';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Punch: out (field_out) */
  $handler->display->display_options['filters']['field_out_value']['id'] = 'field_out_value';
  $handler->display->display_options['filters']['field_out_value']['table'] = 'field_data_field_out';
  $handler->display->display_options['filters']['field_out_value']['field'] = 'field_out_value';
  $handler->display->display_options['filters']['field_out_value']['operator'] = 'not between';
  $handler->display->display_options['filters']['field_out_value']['group'] = 1;
  $handler->display->display_options['filters']['field_out_value']['default_date'] = '-20 years';
  $handler->display->display_options['filters']['field_out_value']['default_to_date'] = '+20 years';
  /* Filter criterion: Job: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['filters']['field_department_tid']['value'] = '';
  $handler->display->display_options['filters']['field_department_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_department_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Department (field_department)';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Broken/missing handler */
  $handler->display->display_options['header']['autorefresh']['id'] = 'autorefresh';
  $handler->display->display_options['header']['autorefresh']['table'] = 'views';
  $handler->display->display_options['header']['autorefresh']['field'] = 'autorefresh';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total Clocked-in Users';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Punch: out (field_out) */
  $handler->display->display_options['filters']['field_out_value']['id'] = 'field_out_value';
  $handler->display->display_options['filters']['field_out_value']['table'] = 'field_data_field_out';
  $handler->display->display_options['filters']['field_out_value']['field'] = 'field_out_value';
  $handler->display->display_options['filters']['field_out_value']['operator'] = 'not between';
  $handler->display->display_options['filters']['field_out_value']['group'] = 1;
  $handler->display->display_options['filters']['field_out_value']['default_date'] = '-20 years';
  $handler->display->display_options['filters']['field_out_value']['default_to_date'] = '+20 years';
  /* Filter criterion: Job: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['filters']['field_department_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_department_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';
  $handler->display->display_options['path'] = 'clocked-in-users';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Clocked In Users';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Clocked In Users - My Department(s)';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Punch: out (field_out) */
  $handler->display->display_options['filters']['field_out_value']['id'] = 'field_out_value';
  $handler->display->display_options['filters']['field_out_value']['table'] = 'field_data_field_out';
  $handler->display->display_options['filters']['field_out_value']['field'] = 'field_out_value';
  $handler->display->display_options['filters']['field_out_value']['operator'] = 'not between';
  $handler->display->display_options['filters']['field_out_value']['group'] = 1;
  $handler->display->display_options['filters']['field_out_value']['default_date'] = '-20 years';
  $handler->display->display_options['filters']['field_out_value']['default_to_date'] = '+20 years';
  /* Filter criterion: Job: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['filters']['field_department_tid']['value'] = array(
    0 => '9',
  );
  $handler->display->display_options['filters']['field_department_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';
  $export['clocked_in_users'] = $view;

  $view = new view();
  $view->name = 'find_clients';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_client';
  $view->human_name = 'Find Clients';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find Clients';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    7 => '7',
    4 => '4',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['text_input_required'] = '';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_date_of_birth' => 'field_date_of_birth',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_ssn' => 'field_ssn',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Client: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_client';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Client: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_client';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'client/client/[id]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_date_of_birth']['id'] = 'field_date_of_birth';
  $handler->display->display_options['fields']['field_date_of_birth']['table'] = 'field_data_field_date_of_birth';
  $handler->display->display_options['fields']['field_date_of_birth']['field'] = 'field_date_of_birth';
  $handler->display->display_options['fields']['field_date_of_birth']['label'] = '';
  $handler->display->display_options['fields']['field_date_of_birth']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_ssn']['id'] = 'field_ssn';
  $handler->display->display_options['fields']['field_ssn']['table'] = 'field_data_field_ssn';
  $handler->display->display_options['fields']['field_ssn']['field'] = 'field_ssn';
  $handler->display->display_options['fields']['field_ssn']['label'] = '';
  $handler->display->display_options['fields']['field_ssn']['element_label_colon'] = FALSE;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['order'] = 'DESC';
  /* Sort criterion: Client: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'eck_client';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'day';
  /* Filter criterion: Client: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_client';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search Client Name:';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'find-clients';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Find Clients';
  $handler->display->display_options['menu']['name'] = 'menu-clients-and-jobs';
  $export['find_clients'] = $view;

  $view = new view();
  $view->name = 'find_employee';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Find Employee';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find Employee';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view timeclock punches';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['text_input_required'] = '';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user/[uid]/timesheet';
  $handler->display->display_options['fields']['name']['alter']['alt'] = '[name]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Sort criterion: User: Last login */
  $handler->display->display_options['sorts']['login']['id'] = 'login';
  $handler->display->display_options['sorts']['login']['table'] = 'users';
  $handler->display->display_options['sorts']['login']['field'] = 'login';
  $handler->display->display_options['sorts']['login']['order'] = 'DESC';
  $handler->display->display_options['sorts']['login']['granularity'] = 'day';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['realname']['id'] = 'realname';
  $handler->display->display_options['filters']['realname']['table'] = 'realname';
  $handler->display->display_options['filters']['realname']['field'] = 'realname';
  $handler->display->display_options['filters']['realname']['operator'] = 'contains';
  $handler->display->display_options['filters']['realname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['realname']['expose']['operator_id'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['realname']['expose']['operator'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['identifier'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['find_employee'] = $view;

  $view = new view();
  $view->name = 'find_jobs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_job';
  $view->human_name = 'Find Jobs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find Jobs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    7 => '7',
    4 => '4',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['text_input_required'] = '';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_client_target_id']['id'] = 'field_client_target_id';
  $handler->display->display_options['relationships']['field_client_target_id']['table'] = 'field_data_field_client';
  $handler->display->display_options['relationships']['field_client_target_id']['field'] = 'field_client_target_id';
  /* Relationship: Job: Department (field_department) */
  $handler->display->display_options['relationships']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['relationships']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['relationships']['field_department_tid']['field'] = 'field_department_tid';
  /* Field: Job: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_job';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Job: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_job';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'job/job/[id]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['relationship'] = 'field_client_target_id';
  /* Sort criterion: Job: Changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'eck_job';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['granularity'] = 'day';
  /* Filter criterion: Client: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_client';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_client_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Client Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  /* Filter criterion: Job: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'find-jobs';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Find Jobs';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'menu-clients-and-jobs';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['find_jobs'] = $view;

  $view = new view();
  $view->name = 'flagged_punches_per_employee';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_punch';
  $view->human_name = 'Flagged Punches Per employee';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Flagged Punches';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit own timeclock punches';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Contact [realname] to resolve the issue with the "flagged punches" listed below.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Relationship: Flags: flag */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'eck_punch';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'flag';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Flags: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'flagging';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'flag_content_rel';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_employee_target_id']['id'] = 'field_employee_target_id';
  $handler->display->display_options['relationships']['field_employee_target_id']['table'] = 'field_data_field_employee';
  $handler->display->display_options['relationships']['field_employee_target_id']['field'] = 'field_employee_target_id';
  /* Field: Punch: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Punch: Rendered Punch */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_punch';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = 'Punch';
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Flagging: Reason */
  $handler->display->display_options['fields']['field_reason']['id'] = 'field_reason';
  $handler->display->display_options['fields']['field_reason']['table'] = 'field_data_field_reason';
  $handler->display->display_options['fields']['field_reason']['field'] = 'field_reason';
  $handler->display->display_options['fields']['field_reason']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['field_reason']['type'] = 'text_plain';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'Flagged By';
  /* Field: Flags: Flagged time */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_employee_target_id';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Sort criterion: Punch: Id */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'eck_punch';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  /* Sort criterion: Flags: Flagged time */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['sorts']['timestamp']['granularity'] = 'day';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_employee_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['flagged_punches_per_employee'] = $view;

  $view = new view();
  $view->name = 'flags';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_punch';
  $view->human_name = 'Flags';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Flags';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view timeclock punches';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_reason' => 'field_reason',
    'field_full_name' => 'field_full_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reason' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_full_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Flags: flag */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'eck_punch';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'flag';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Flags: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'flagging';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Punch: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Flags: User uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'flagging';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: : field_full_name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_full_name']['label'] = 'Flagged By';
  $handler->display->display_options['fields']['field_full_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_full_name']['alter']['path'] = 'user/[uid]';
  /* Field: Flagging: Reason */
  $handler->display->display_options['fields']['field_reason']['id'] = 'field_reason';
  $handler->display->display_options['fields']['field_reason']['table'] = 'field_data_field_reason';
  $handler->display->display_options['fields']['field_reason']['field'] = 'field_reason';
  $handler->display->display_options['fields']['field_reason']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['field_reason']['type'] = 'text_plain';
  /* Contextual filter: Punch: Id */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'eck_punch';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['id']['validate']['type'] = 'numeric';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    7 => '7',
    4 => '4',
    6 => '6',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Punch: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Flags: User uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'flagging';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Punch: Rendered Punch */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_punch';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: : field_full_name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_full_name']['label'] = 'Flagged By';
  $handler->display->display_options['fields']['field_full_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_full_name']['alter']['path'] = 'user/[uid]';
  /* Field: Flagging: Reason */
  $handler->display->display_options['fields']['field_reason']['id'] = 'field_reason';
  $handler->display->display_options['fields']['field_reason']['table'] = 'field_data_field_reason';
  $handler->display->display_options['fields']['field_reason']['field'] = 'field_reason';
  $handler->display->display_options['fields']['field_reason']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['field_reason']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'punch/flagged';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'All Flagged Punches';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['flags'] = $view;

  $view = new view();
  $view->name = 'job_ids';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_job';
  $view->human_name = 'Job IDs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Job IDs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    7 => '7',
    4 => '4',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_client_target_id']['id'] = 'field_client_target_id';
  $handler->display->display_options['relationships']['field_client_target_id']['table'] = 'field_data_field_client';
  $handler->display->display_options['relationships']['field_client_target_id']['field'] = 'field_client_target_id';
  /* Field: Job: Department */
  $handler->display->display_options['fields']['field_department']['id'] = 'field_department';
  $handler->display->display_options['fields']['field_department']['table'] = 'field_data_field_department';
  $handler->display->display_options['fields']['field_department']['field'] = 'field_department';
  /* Field: Job: Client */
  $handler->display->display_options['fields']['field_client']['id'] = 'field_client';
  $handler->display->display_options['fields']['field_client']['table'] = 'field_data_field_client';
  $handler->display->display_options['fields']['field_client']['field'] = 'field_client';
  $handler->display->display_options['fields']['field_client']['settings'] = array(
    'link' => 1,
  );
  /* Field: Job: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_job';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Job Id';
  $handler->display->display_options['fields']['id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['path'] = 'job/job/[id]';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Job: Primary Office Staff */
  $handler->display->display_options['fields']['field_primary_office_staff']['id'] = 'field_primary_office_staff';
  $handler->display->display_options['fields']['field_primary_office_staff']['table'] = 'field_data_field_primary_office_staff';
  $handler->display->display_options['fields']['field_primary_office_staff']['field'] = 'field_primary_office_staff';
  $handler->display->display_options['fields']['field_primary_office_staff']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_primary_office_staff']['delta_offset'] = '0';
  /* Sort criterion: Job: Primary Office Staff (field_primary_office_staff) */
  $handler->display->display_options['sorts']['field_primary_office_staff_target_id']['id'] = 'field_primary_office_staff_target_id';
  $handler->display->display_options['sorts']['field_primary_office_staff_target_id']['table'] = 'field_data_field_primary_office_staff';
  $handler->display->display_options['sorts']['field_primary_office_staff_target_id']['field'] = 'field_primary_office_staff_target_id';
  /* Sort criterion: Job: Department (field_department) */
  $handler->display->display_options['sorts']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['sorts']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['sorts']['field_department_tid']['field'] = 'field_department_tid';
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['relationship'] = 'field_client_target_id';
  /* Filter criterion: Job: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => '2',
    5 => '5',
    4 => '4',
    7 => '7',
    6 => '6',
    3 => '3',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';
  /* Filter criterion: Job: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_job';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Client Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_primary_office_staff',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_department' => 'field_department',
    'field_client' => 'field_client',
    'id' => 'id',
    'field_primary_office_staff' => 'field_primary_office_staff',
    'edit_link' => 'edit_link',
    'field_description' => 'field_description',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_department' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_client' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_primary_office_staff' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Job */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_job';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  /* Field: Job: Department */
  $handler->display->display_options['fields']['field_department']['id'] = 'field_department';
  $handler->display->display_options['fields']['field_department']['table'] = 'field_data_field_department';
  $handler->display->display_options['fields']['field_department']['field'] = 'field_department';
  /* Field: Job: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Job: Client */
  $handler->display->display_options['fields']['field_client']['id'] = 'field_client';
  $handler->display->display_options['fields']['field_client']['table'] = 'field_data_field_client';
  $handler->display->display_options['fields']['field_client']['field'] = 'field_client';
  $handler->display->display_options['fields']['field_client']['settings'] = array(
    'link' => 1,
  );
  /* Field: Job: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_job';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Job Id';
  $handler->display->display_options['fields']['id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['path'] = 'job/job/[id]';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Job: Primary Office Staff */
  $handler->display->display_options['fields']['field_primary_office_staff']['id'] = 'field_primary_office_staff';
  $handler->display->display_options['fields']['field_primary_office_staff']['table'] = 'field_data_field_primary_office_staff';
  $handler->display->display_options['fields']['field_primary_office_staff']['field'] = 'field_primary_office_staff';
  $handler->display->display_options['fields']['field_primary_office_staff']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_primary_office_staff']['delta_offset'] = '0';
  /* Field: Job: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_job';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Job: Department (field_department) */
  $handler->display->display_options['arguments']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['arguments']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_options']['code'] = 'global $user;
$departments = timeclock_exceptions_get_user_supervised_departments($user->uid);
if (count($departments) > 0) {
return implode(\'+\',$departments);
} else {
return NULL;
}';
  $handler->display->display_options['arguments']['field_department_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_department_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_department_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_department_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_department_tid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['field_department_tid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Job: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => '2',
    5 => '5',
    4 => '4',
    7 => '7',
    6 => '6',
    3 => '3',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';
  /* Filter criterion: Job: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_job';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Client Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'job-ids';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Job ID list';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-clients-and-jobs';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'job-ids/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Job: Department */
  $handler->display->display_options['fields']['field_department']['id'] = 'field_department';
  $handler->display->display_options['fields']['field_department']['table'] = 'field_data_field_department';
  $handler->display->display_options['fields']['field_department']['field'] = 'field_department';
  /* Field: Job: Client */
  $handler->display->display_options['fields']['field_client']['id'] = 'field_client';
  $handler->display->display_options['fields']['field_client']['table'] = 'field_data_field_client';
  $handler->display->display_options['fields']['field_client']['field'] = 'field_client';
  $handler->display->display_options['fields']['field_client']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_client']['settings'] = array(
    'link' => 1,
  );
  /* Field: Job: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_job';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Job Id';
  $handler->display->display_options['fields']['id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['path'] = 'job/job/[id]';
  $handler->display->display_options['fields']['id']['separator'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Client: Id */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'eck_client';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['relationship'] = 'field_client_target_id';
  $handler->display->display_options['arguments']['id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['block_description'] = 'Job IDs per client';
  $export['job_ids'] = $view;

  $view = new view();
  $view->name = 'punch_revisions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_punch_revision';
  $view->human_name = 'punch revisions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'punch revision';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
    5 => '5',
    7 => '7',
    4 => '4',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '- No Results Found - ';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Punch Revisions: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'eck_punch_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Punch Revisions: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_punch_revision';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Punch (historical data): In */
  $handler->display->display_options['fields']['field_in-revision_id']['id'] = 'field_in-revision_id';
  $handler->display->display_options['fields']['field_in-revision_id']['table'] = 'field_revision_field_in';
  $handler->display->display_options['fields']['field_in-revision_id']['field'] = 'field_in-revision_id';
  /* Field: Punch (historical data): out */
  $handler->display->display_options['fields']['field_out-revision_id']['id'] = 'field_out-revision_id';
  $handler->display->display_options['fields']['field_out-revision_id']['table'] = 'field_revision_field_out';
  $handler->display->display_options['fields']['field_out-revision_id']['field'] = 'field_out-revision_id';
  /* Field: Punch (historical data): Length */
  $handler->display->display_options['fields']['field_length-revision_id']['id'] = 'field_length-revision_id';
  $handler->display->display_options['fields']['field_length-revision_id']['table'] = 'field_revision_field_length';
  $handler->display->display_options['fields']['field_length-revision_id']['field'] = 'field_length-revision_id';
  /* Field: Punch (historical data): Employee */
  $handler->display->display_options['fields']['field_employee-revision_id']['id'] = 'field_employee-revision_id';
  $handler->display->display_options['fields']['field_employee-revision_id']['table'] = 'field_revision_field_employee';
  $handler->display->display_options['fields']['field_employee-revision_id']['field'] = 'field_employee-revision_id';
  /* Field: Punch (historical data): Job */
  $handler->display->display_options['fields']['field_job-revision_id']['id'] = 'field_job-revision_id';
  $handler->display->display_options['fields']['field_job-revision_id']['table'] = 'field_revision_field_job';
  $handler->display->display_options['fields']['field_job-revision_id']['field'] = 'field_job-revision_id';
  /* Field: Punch Revisions: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'eck_punch_revision';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  /* Field: Punch Revisions: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_punch_revision';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  /* Field: Punch Revisions: Author */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'eck_punch_revision';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'User';
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['path'] = 'user/[uid]';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Contextual filter: Punch Revisions: Id */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'eck_punch_revision';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['id']['validate']['fail'] = 'empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'punch-revisions/%';
  $export['punch_revisions'] = $view;

  $view = new view();
  $view->name = 'recent_punches';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_punch';
  $view->human_name = 'recent punches';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'recent punches - job';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'mark punches approved';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear Filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_length' => 'field_length',
    'edit_link' => 'edit_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_length' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'edit_link' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '1';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_job_target_id']['id'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['table'] = 'field_data_field_job';
  $handler->display->display_options['relationships']['field_job_target_id']['field'] = 'field_job_target_id';
  /* Field: Punch: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Bulk operations: Punch */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_punch';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  /* Field: Punch: Employee */
  $handler->display->display_options['fields']['field_employee']['id'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['table'] = 'field_data_field_employee';
  $handler->display->display_options['fields']['field_employee']['field'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['settings'] = array(
    'link' => 1,
  );
  /* Field: Punch: In */
  $handler->display->display_options['fields']['field_in']['id'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['table'] = 'field_data_field_in';
  $handler->display->display_options['fields']['field_in']['field'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: out */
  $handler->display->display_options['fields']['field_out']['id'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['table'] = 'field_data_field_out';
  $handler->display->display_options['fields']['field_out']['field'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: Length */
  $handler->display->display_options['fields']['field_length']['id'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['table'] = 'field_data_field_length';
  $handler->display->display_options['fields']['field_length']['field'] = 'field_length';
  /* Field: Punch: Overtime Hours */
  $handler->display->display_options['fields']['field_overtime_hours']['id'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['table'] = 'field_data_field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['field'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['label'] = 'OT';
  $handler->display->display_options['fields']['field_overtime_hours']['type'] = 'custom_formatters_seconds_to_h_m_s';
  $handler->display->display_options['fields']['field_overtime_hours']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Punch: Job */
  $handler->display->display_options['fields']['field_job']['id'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['table'] = 'field_data_field_job';
  $handler->display->display_options['fields']['field_job']['field'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['settings'] = array(
    'link' => 1,
  );
  /* Field: Punch: Payroll Approval */
  $handler->display->display_options['fields']['field_payroll_approval']['id'] = 'field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['table'] = 'field_data_field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['field'] = 'field_payroll_approval';
  /* Field: Punch: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  /* Sort criterion: Punch: Id */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'eck_punch';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  /* Filter criterion: Punch: punch type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'punch' => 'punch',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date: Date (eck_punch) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['default_date'] = '-2 weeks';
  $handler->display->display_options['filters']['date_filter_1']['default_to_date'] = '+1 year';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+1';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'field_data_field_in.field_in_value' => 'field_data_field_in.field_in_value',
  );
  /* Filter criterion: Job: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['filters']['field_department_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_department_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    4 => '4',
    7 => '7',
    6 => '6',
    3 => '3',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_department_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';
  $handler->display->display_options['filters']['field_department_tid']['hierarchy'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Punches - My Department(s)';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_job_target_id']['id'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['table'] = 'field_data_field_job';
  $handler->display->display_options['relationships']['field_job_target_id']['field'] = 'field_job_target_id';
  /* Relationship: Job: Department (field_department) */
  $handler->display->display_options['relationships']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['relationships']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['relationships']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['relationships']['field_department_tid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Punch: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Bulk operations: Punch */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_punch';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['exclude'] = TRUE;
  /* Field: Punch: Employee */
  $handler->display->display_options['fields']['field_employee']['id'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['table'] = 'field_data_field_employee';
  $handler->display->display_options['fields']['field_employee']['field'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['settings'] = array(
    'link' => 1,
  );
  /* Field: Punch: In */
  $handler->display->display_options['fields']['field_in']['id'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['table'] = 'field_data_field_in';
  $handler->display->display_options['fields']['field_in']['field'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: out */
  $handler->display->display_options['fields']['field_out']['id'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['table'] = 'field_data_field_out';
  $handler->display->display_options['fields']['field_out']['field'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: Length */
  $handler->display->display_options['fields']['field_length']['id'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['table'] = 'field_data_field_length';
  $handler->display->display_options['fields']['field_length']['field'] = 'field_length';
  /* Field: Punch: Overtime Hours */
  $handler->display->display_options['fields']['field_overtime_hours']['id'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['table'] = 'field_data_field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['field'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['label'] = 'OT';
  $handler->display->display_options['fields']['field_overtime_hours']['type'] = 'custom_formatters_seconds_to_h_m_s';
  $handler->display->display_options['fields']['field_overtime_hours']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Punch: Job */
  $handler->display->display_options['fields']['field_job']['id'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['table'] = 'field_data_field_job';
  $handler->display->display_options['fields']['field_job']['field'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['settings'] = array(
    'link' => 1,
  );
  /* Field: Punch: Payroll Approval */
  $handler->display->display_options['fields']['field_payroll_approval']['id'] = 'field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['table'] = 'field_data_field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['field'] = 'field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['exclude'] = TRUE;
  /* Field: Punch: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Punch: punch type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'punch' => 'punch',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date: Date (eck_punch) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['default_date'] = '-2 weeks';
  $handler->display->display_options['filters']['date_filter_1']['default_to_date'] = '+1 year';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+1';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'field_data_field_in.field_in_value' => 'field_data_field_in.field_in_value',
  );

  /* Display: recent job punches */
  $handler = $view->new_display('block', 'recent job punches', 'block_1');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_employee' => 'field_employee',
    'field_in' => 'field_in',
    'field_out' => 'field_out',
    'field_length' => 'field_length',
    'field_units' => 'field_units',
  );
  $handler->display->display_options['style_options']['default'] = 'field_in';
  $handler->display->display_options['style_options']['info'] = array(
    'field_employee' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_in' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_out' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_length' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_units' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['group_aggregation']['grouping_field_class'] = 'table-bordered';
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_class'] = 'aggregated-row';
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '- No Results Found -';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Punch: Employee */
  $handler->display->display_options['fields']['field_employee']['id'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['table'] = 'field_data_field_employee';
  $handler->display->display_options['fields']['field_employee']['field'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_employee']['alter']['path'] = 'user/[field_employee-target_id]/timesheet';
  $handler->display->display_options['fields']['field_employee']['alter']['alt'] = '[field_employee]';
  $handler->display->display_options['fields']['field_employee']['settings'] = array(
    'link' => 0,
  );
  /* Field: Punch: In */
  $handler->display->display_options['fields']['field_in']['id'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['table'] = 'field_data_field_in';
  $handler->display->display_options['fields']['field_in']['field'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Punch: out */
  $handler->display->display_options['fields']['field_out']['id'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['table'] = 'field_data_field_out';
  $handler->display->display_options['fields']['field_out']['field'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Punch: Length */
  $handler->display->display_options['fields']['field_length']['id'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['table'] = 'field_data_field_length';
  $handler->display->display_options['fields']['field_length']['field'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_length']['click_sort_column'] = 'value';
  $handler->display->display_options['fields']['field_length']['group_column'] = 'value';
  /* Field: Punch: Units */
  $handler->display->display_options['fields']['field_units']['id'] = 'field_units';
  $handler->display->display_options['fields']['field_units']['table'] = 'field_data_field_units';
  $handler->display->display_options['fields']['field_units']['field'] = 'field_units';
  /* Field: Punch: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Punch: Job (field_job) */
  $handler->display->display_options['arguments']['field_job_target_id']['id'] = 'field_job_target_id';
  $handler->display->display_options['arguments']['field_job_target_id']['table'] = 'field_data_field_job';
  $handler->display->display_options['arguments']['field_job_target_id']['field'] = 'field_job_target_id';
  $handler->display->display_options['arguments']['field_job_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_job_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_job_target_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_job_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_job_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_job_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_job_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_job_target_id']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Punch: punch type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'punch' => 'punch',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Job: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['filters']['field_department_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_department_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    4 => '4',
    7 => '7',
    6 => '6',
    3 => '3',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_department_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';
  $handler->display->display_options['filters']['field_department_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'recent punches - jobs';

  /* Display: Paid Punches */
  $handler = $view->new_display('page', 'Paid Punches', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Paid Punches';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit approved punches';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Link to export file';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="/payroll/export/[field_date_paid_1]">Export to ADP</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Punch: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['path'] = '/punch/punch/[id]';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Punch: Author */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Punch: Employee */
  $handler->display->display_options['fields']['field_employee']['id'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['table'] = 'field_data_field_employee';
  $handler->display->display_options['fields']['field_employee']['field'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['settings'] = array(
    'link' => 1,
  );
  /* Field: Punch: In */
  $handler->display->display_options['fields']['field_in']['id'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['table'] = 'field_data_field_in';
  $handler->display->display_options['fields']['field_in']['field'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: out */
  $handler->display->display_options['fields']['field_out']['id'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['table'] = 'field_data_field_out';
  $handler->display->display_options['fields']['field_out']['field'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: Length */
  $handler->display->display_options['fields']['field_length_1']['id'] = 'field_length_1';
  $handler->display->display_options['fields']['field_length_1']['table'] = 'field_data_field_length';
  $handler->display->display_options['fields']['field_length_1']['field'] = 'field_length';
  /* Field: Punch: Job */
  $handler->display->display_options['fields']['field_job']['id'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['table'] = 'field_data_field_job';
  $handler->display->display_options['fields']['field_job']['field'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['settings'] = array(
    'link' => 1,
  );
  /* Field: Punch: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['exclude'] = TRUE;
  /* Field: Punch: Date Paid */
  $handler->display->display_options['fields']['field_date_paid']['id'] = 'field_date_paid';
  $handler->display->display_options['fields']['field_date_paid']['table'] = 'field_data_field_date_paid';
  $handler->display->display_options['fields']['field_date_paid']['field'] = 'field_date_paid';
  $handler->display->display_options['fields']['field_date_paid']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: Date Paid */
  $handler->display->display_options['fields']['field_date_paid_1']['id'] = 'field_date_paid_1';
  $handler->display->display_options['fields']['field_date_paid_1']['table'] = 'field_data_field_date_paid';
  $handler->display->display_options['fields']['field_date_paid_1']['field'] = 'field_date_paid';
  $handler->display->display_options['fields']['field_date_paid_1']['label'] = 'URL-Date';
  $handler->display->display_options['fields']['field_date_paid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_paid_1']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_date_paid_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date_paid_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_date_paid_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_paid_1']['settings'] = array(
    'format_type' => 'just_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: Overtime Hours */
  $handler->display->display_options['fields']['field_overtime_hours']['id'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['table'] = 'field_data_field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['field'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['label'] = 'OT';
  $handler->display->display_options['fields']['field_overtime_hours']['type'] = 'custom_formatters_seconds_to_h_m_s';
  $handler->display->display_options['fields']['field_overtime_hours']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Punch: punch type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'punch' => 'punch',
  );
  /* Filter criterion: Punch: Payroll Approval (field_payroll_approval) */
  $handler->display->display_options['filters']['field_payroll_approval_value']['id'] = 'field_payroll_approval_value';
  $handler->display->display_options['filters']['field_payroll_approval_value']['table'] = 'field_data_field_payroll_approval';
  $handler->display->display_options['filters']['field_payroll_approval_value']['field'] = 'field_payroll_approval_value';
  $handler->display->display_options['filters']['field_payroll_approval_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Punch: Date Paid (field_date_paid) */
  $handler->display->display_options['filters']['field_date_paid_value']['id'] = 'field_date_paid_value';
  $handler->display->display_options['filters']['field_date_paid_value']['table'] = 'field_data_field_date_paid';
  $handler->display->display_options['filters']['field_date_paid_value']['field'] = 'field_date_paid_value';
  $handler->display->display_options['filters']['field_date_paid_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_date_paid_value']['form_type'] = 'date_text';
  /* Filter criterion: Punch: Date Paid (field_date_paid) */
  $handler->display->display_options['filters']['field_date_paid_value_1']['id'] = 'field_date_paid_value_1';
  $handler->display->display_options['filters']['field_date_paid_value_1']['table'] = 'field_data_field_date_paid';
  $handler->display->display_options['filters']['field_date_paid_value_1']['field'] = 'field_date_paid_value';
  $handler->display->display_options['filters']['field_date_paid_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_paid_value_1']['expose']['operator_id'] = 'field_date_paid_value_1_op';
  $handler->display->display_options['filters']['field_date_paid_value_1']['expose']['label'] = 'Date Paid';
  $handler->display->display_options['filters']['field_date_paid_value_1']['expose']['operator'] = 'field_date_paid_value_1_op';
  $handler->display->display_options['filters']['field_date_paid_value_1']['expose']['identifier'] = 'field_date_paid_value_1';
  $handler->display->display_options['filters']['field_date_paid_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_date_paid_value_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_date_paid_value_1']['default_date'] = 'Today';
  $handler->display->display_options['filters']['field_date_paid_value_1']['year_range'] = '-3:+0';
  $handler->display->display_options['path'] = 'punches/paid';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Paid Punches';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: All Punches */
  $handler = $view->new_display('page', 'All Punches', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '50,100,200';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'nothing',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'id' => 'id',
    'field_in_1' => 'field_in_1',
    'field_employee' => 'field_employee',
    'field_in' => 'field_in',
    'field_out' => 'field_out',
    'field_length' => 'field_length',
    'field_overtime_hours' => 'field_overtime_hours',
    'field_job' => 'field_job',
    'field_payroll_approval' => 'field_payroll_approval',
    'nothing' => 'nothing',
    'php_2' => 'php_2',
    'field_has_been_edited' => 'field_has_been_edited',
    'php' => 'php',
    'php_1' => 'php_1',
    'edit_link' => 'edit_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_in_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_employee' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_in' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_out' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_length' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_overtime_hours' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_job' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_payroll_approval' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_2' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_has_been_edited' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_1' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'edit_link' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_job_target_id']['id'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['table'] = 'field_data_field_job';
  $handler->display->display_options['relationships']['field_job_target_id']['field'] = 'field_job_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_employee_target_id']['id'] = 'field_employee_target_id';
  $handler->display->display_options['relationships']['field_employee_target_id']['table'] = 'field_data_field_employee';
  $handler->display->display_options['relationships']['field_employee_target_id']['field'] = 'field_employee_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_client_target_id']['id'] = 'field_client_target_id';
  $handler->display->display_options['relationships']['field_client_target_id']['table'] = 'field_data_field_client';
  $handler->display->display_options['relationships']['field_client_target_id']['field'] = 'field_client_target_id';
  $handler->display->display_options['relationships']['field_client_target_id']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Punch */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_punch';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::timeclock_payroll_approval_approve' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Punch: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Punch ID';
  $handler->display->display_options['fields']['id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['text'] = '[id]';
  $handler->display->display_options['fields']['id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['path'] = 'punch/punch/[id]';
  $handler->display->display_options['fields']['id']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['preserve_tags'] = '<a>';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Punch: In */
  $handler->display->display_options['fields']['field_in_1']['id'] = 'field_in_1';
  $handler->display->display_options['fields']['field_in_1']['table'] = 'field_data_field_in';
  $handler->display->display_options['fields']['field_in_1']['field'] = 'field_in';
  $handler->display->display_options['fields']['field_in_1']['label'] = 'Date';
  $handler->display->display_options['fields']['field_in_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_in_1']['settings'] = array(
    'format_type' => 'just_date_common',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: Employee */
  $handler->display->display_options['fields']['field_employee']['id'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['table'] = 'field_data_field_employee';
  $handler->display->display_options['fields']['field_employee']['field'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_employee']['alter']['text'] = '[field_employee]';
  $handler->display->display_options['fields']['field_employee']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_employee']['alter']['path'] = 'punches?realname=[field_employee]';
  $handler->display->display_options['fields']['field_employee']['settings'] = array(
    'link' => 0,
  );
  /* Field: Punch: In */
  $handler->display->display_options['fields']['field_in']['id'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['table'] = 'field_data_field_in';
  $handler->display->display_options['fields']['field_in']['field'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['settings'] = array(
    'format_type' => 'just_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: out */
  $handler->display->display_options['fields']['field_out']['id'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['table'] = 'field_data_field_out';
  $handler->display->display_options['fields']['field_out']['field'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['settings'] = array(
    'format_type' => 'just_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: Length */
  $handler->display->display_options['fields']['field_length']['id'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['table'] = 'field_data_field_length';
  $handler->display->display_options['fields']['field_length']['field'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['element_type'] = 'strong';
  /* Field: Punch: Overtime Hours */
  $handler->display->display_options['fields']['field_overtime_hours']['id'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['table'] = 'field_data_field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['field'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['label'] = 'OT';
  $handler->display->display_options['fields']['field_overtime_hours']['type'] = 'custom_formatters_seconds_to_h_m_s';
  $handler->display->display_options['fields']['field_overtime_hours']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Punch: Job */
  $handler->display->display_options['fields']['field_job']['id'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['table'] = 'field_data_field_job';
  $handler->display->display_options['fields']['field_job']['field'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['settings'] = array(
    'link' => 1,
  );
  /* Field: Punch: Payroll Approval */
  $handler->display->display_options['fields']['field_payroll_approval']['id'] = 'field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['table'] = 'field_data_field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['field'] = 'field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['text'] = '<h2 class="green">&#x2714;</h2>';
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['path'] = '/punch/punch/[id]';
  $handler->display->display_options['fields']['field_payroll_approval']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['type'] = 'list_key';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Date';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_in_1]';
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Edited';
  $handler->display->display_options['fields']['php_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_2']['empty_zero'] = TRUE;
  /* Field: Punch: has been edited */
  $handler->display->display_options['fields']['field_has_been_edited']['id'] = 'field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['table'] = 'field_data_field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['field'] = 'field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['label'] = 'Edited';
  $handler->display->display_options['fields']['field_has_been_edited']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['text'] = '*';
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['path'] = 'punch/punch/[id]/revisions';
  $handler->display->display_options['fields']['field_has_been_edited']['element_type'] = '0';
  $handler->display->display_options['fields']['field_has_been_edited']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['type'] = 'list_key';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Open Exceptions';
  $handler->display->display_options['fields']['php']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php']['empty_zero'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Flagged';
  $handler->display->display_options['fields']['php_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = TRUE;
  /* Field: Punch: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Punch: Id */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'eck_punch';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  $handler->display->display_options['sorts']['id']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['id']['expose']['label'] = 'Punch ID';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Punch: punch type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'punch' => 'punch',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date: Date (eck_punch) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['default_date'] = '-2 weeks';
  $handler->display->display_options['filters']['date_filter_1']['default_to_date'] = '+1 year';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+1';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'field_data_field_in.field_in_value' => 'field_data_field_in.field_in_value',
  );
  /* Filter criterion: Job: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['filters']['field_department_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_department_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    4 => '4',
    7 => '7',
    6 => '6',
    3 => '3',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_department_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';
  $handler->display->display_options['filters']['field_department_tid']['hierarchy'] = 1;
  /* Filter criterion: Client: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_client';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_client_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Client';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  /* Filter criterion: Punch: Payroll Approval (field_payroll_approval) */
  $handler->display->display_options['filters']['field_payroll_approval_value']['id'] = 'field_payroll_approval_value';
  $handler->display->display_options['filters']['field_payroll_approval_value']['table'] = 'field_data_field_payroll_approval';
  $handler->display->display_options['filters']['field_payroll_approval_value']['field'] = 'field_payroll_approval_value';
  $handler->display->display_options['filters']['field_payroll_approval_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_payroll_approval_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['operator_id'] = 'field_payroll_approval_value_op';
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['label'] = 'Payroll Approval';
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['operator'] = 'field_payroll_approval_value_op';
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['identifier'] = 'field_payroll_approval_value';
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'punches/all';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'All Punches';
  $handler->display->display_options['menu']['weight'] = '8';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: My Departments Punches */
  $handler = $view->new_display('page', 'My Departments Punches', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Department';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '50,100,200';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'nothing',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'id' => 'id',
    'field_in_1' => 'field_in_1',
    'field_employee' => 'field_employee',
    'field_in' => 'field_in',
    'field_out' => 'field_out',
    'field_length' => 'field_length',
    'field_overtime_hours' => 'field_overtime_hours',
    'field_job' => 'field_job',
    'field_payroll_approval' => 'field_payroll_approval',
    'nothing' => 'nothing',
    'php_2' => 'php_2',
    'field_has_been_edited' => 'field_has_been_edited',
    'php' => 'php',
    'php_1' => 'php_1',
    'edit_link' => 'edit_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_in_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_employee' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_in' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_out' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_length' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_overtime_hours' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_job' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_payroll_approval' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_2' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_has_been_edited' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_1' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'edit_link' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_job_target_id']['id'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['table'] = 'field_data_field_job';
  $handler->display->display_options['relationships']['field_job_target_id']['field'] = 'field_job_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_employee_target_id']['id'] = 'field_employee_target_id';
  $handler->display->display_options['relationships']['field_employee_target_id']['table'] = 'field_data_field_employee';
  $handler->display->display_options['relationships']['field_employee_target_id']['field'] = 'field_employee_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_client_target_id']['id'] = 'field_client_target_id';
  $handler->display->display_options['relationships']['field_client_target_id']['table'] = 'field_data_field_client';
  $handler->display->display_options['relationships']['field_client_target_id']['field'] = 'field_client_target_id';
  $handler->display->display_options['relationships']['field_client_target_id']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Punch */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_punch';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::timeclock_payroll_approval_approve' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Punch: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Punch ID';
  $handler->display->display_options['fields']['id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['text'] = '[id]';
  $handler->display->display_options['fields']['id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['path'] = 'punch/punch/[id]';
  $handler->display->display_options['fields']['id']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['preserve_tags'] = '<a>';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Punch: In */
  $handler->display->display_options['fields']['field_in_1']['id'] = 'field_in_1';
  $handler->display->display_options['fields']['field_in_1']['table'] = 'field_data_field_in';
  $handler->display->display_options['fields']['field_in_1']['field'] = 'field_in';
  $handler->display->display_options['fields']['field_in_1']['label'] = 'Date';
  $handler->display->display_options['fields']['field_in_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_in_1']['settings'] = array(
    'format_type' => 'just_date_common',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: Employee */
  $handler->display->display_options['fields']['field_employee']['id'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['table'] = 'field_data_field_employee';
  $handler->display->display_options['fields']['field_employee']['field'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_employee']['alter']['text'] = '[field_employee]';
  $handler->display->display_options['fields']['field_employee']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_employee']['alter']['path'] = 'punches?realname=[field_employee]';
  $handler->display->display_options['fields']['field_employee']['settings'] = array(
    'link' => 0,
  );
  /* Field: Punch: In */
  $handler->display->display_options['fields']['field_in']['id'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['table'] = 'field_data_field_in';
  $handler->display->display_options['fields']['field_in']['field'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['settings'] = array(
    'format_type' => 'just_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: out */
  $handler->display->display_options['fields']['field_out']['id'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['table'] = 'field_data_field_out';
  $handler->display->display_options['fields']['field_out']['field'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['settings'] = array(
    'format_type' => 'just_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: Length */
  $handler->display->display_options['fields']['field_length']['id'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['table'] = 'field_data_field_length';
  $handler->display->display_options['fields']['field_length']['field'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['element_type'] = 'strong';
  /* Field: Punch: Overtime Hours */
  $handler->display->display_options['fields']['field_overtime_hours']['id'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['table'] = 'field_data_field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['field'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['label'] = 'OT';
  $handler->display->display_options['fields']['field_overtime_hours']['type'] = 'custom_formatters_seconds_to_h_m_s';
  $handler->display->display_options['fields']['field_overtime_hours']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Punch: Job */
  $handler->display->display_options['fields']['field_job']['id'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['table'] = 'field_data_field_job';
  $handler->display->display_options['fields']['field_job']['field'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['settings'] = array(
    'link' => 1,
  );
  /* Field: Punch: Payroll Approval */
  $handler->display->display_options['fields']['field_payroll_approval']['id'] = 'field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['table'] = 'field_data_field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['field'] = 'field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['text'] = '<h2 class="green">&#x2714;</h2>';
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['path'] = '/punch/punch/[id]';
  $handler->display->display_options['fields']['field_payroll_approval']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['type'] = 'list_key';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Date';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_in_1]';
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Edited';
  $handler->display->display_options['fields']['php_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_2']['empty_zero'] = TRUE;
  /* Field: Punch: has been edited */
  $handler->display->display_options['fields']['field_has_been_edited']['id'] = 'field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['table'] = 'field_data_field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['field'] = 'field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['label'] = 'Edited';
  $handler->display->display_options['fields']['field_has_been_edited']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['text'] = '*';
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['path'] = 'punch/punch/[id]/revisions';
  $handler->display->display_options['fields']['field_has_been_edited']['element_type'] = '0';
  $handler->display->display_options['fields']['field_has_been_edited']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['type'] = 'list_key';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Open Exceptions';
  $handler->display->display_options['fields']['php']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php']['empty_zero'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Flagged';
  $handler->display->display_options['fields']['php_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = TRUE;
  /* Field: Punch: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Punch: Id */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'eck_punch';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  $handler->display->display_options['sorts']['id']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['id']['expose']['label'] = 'Punch ID';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Job: Department (field_department) */
  $handler->display->display_options['arguments']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['arguments']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['arguments']['field_department_tid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['arguments']['field_department_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_department_tid']['default_argument_options']['code'] = 'global $user;
$departments = timeclock_get_user_supervised_departments($user->uid);
if (count($departments) > 0) {
return implode(\'+\',$departments);
} else {
return NULL;
}';
  $handler->display->display_options['arguments']['field_department_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_department_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_department_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_department_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_department_tid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['field_department_tid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Punch: punch type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'punch' => 'punch',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date: Date (eck_punch) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['default_date'] = '-2 weeks';
  $handler->display->display_options['filters']['date_filter_1']['default_to_date'] = '+1 year';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+1';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'field_data_field_in.field_in_value' => 'field_data_field_in.field_in_value',
  );
  /* Filter criterion: Job: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['filters']['field_department_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_department_tid']['value'] = array(
    9 => '9',
    10 => '10',
    11 => '11',
    8 => '8',
    7 => '7',
    2 => '2',
    3 => '3',
  );
  $handler->display->display_options['filters']['field_department_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    4 => '4',
    7 => '7',
    6 => '6',
    3 => '3',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_department_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';
  $handler->display->display_options['filters']['field_department_tid']['hierarchy'] = 1;
  /* Filter criterion: Client: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_client';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_client_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Client';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  /* Filter criterion: Punch: Payroll Approval (field_payroll_approval) */
  $handler->display->display_options['filters']['field_payroll_approval_value']['id'] = 'field_payroll_approval_value';
  $handler->display->display_options['filters']['field_payroll_approval_value']['table'] = 'field_data_field_payroll_approval';
  $handler->display->display_options['filters']['field_payroll_approval_value']['field'] = 'field_payroll_approval_value';
  $handler->display->display_options['filters']['field_payroll_approval_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_payroll_approval_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['operator_id'] = 'field_payroll_approval_value_op';
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['label'] = 'Payroll Approval';
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['operator'] = 'field_payroll_approval_value_op';
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['identifier'] = 'field_payroll_approval_value';
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'punches/department';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'My Department';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Punches';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: My Jobs' Punches */
  $handler = $view->new_display('page', 'My Jobs\' Punches', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Jobs\' Punches';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '50,100,200';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'nothing',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'id' => 'id',
    'field_in_1' => 'field_in_1',
    'field_employee' => 'field_employee',
    'field_in' => 'field_in',
    'field_out' => 'field_out',
    'field_length' => 'field_length',
    'field_overtime_hours' => 'field_overtime_hours',
    'field_job' => 'field_job',
    'field_payroll_approval' => 'field_payroll_approval',
    'nothing' => 'nothing',
    'php_2' => 'php_2',
    'field_has_been_edited' => 'field_has_been_edited',
    'php' => 'php',
    'php_1' => 'php_1',
    'edit_link' => 'edit_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_in_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_employee' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_in' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_out' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_length' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_overtime_hours' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_job' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_payroll_approval' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_2' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_has_been_edited' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_1' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'edit_link' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Notice';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'This default punches page shows only punches for which you are listed as the primary office staff for the listed job. Use the above tabs to view other pages.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_job_target_id']['id'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['table'] = 'field_data_field_job';
  $handler->display->display_options['relationships']['field_job_target_id']['field'] = 'field_job_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_employee_target_id']['id'] = 'field_employee_target_id';
  $handler->display->display_options['relationships']['field_employee_target_id']['table'] = 'field_data_field_employee';
  $handler->display->display_options['relationships']['field_employee_target_id']['field'] = 'field_employee_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_client_target_id']['id'] = 'field_client_target_id';
  $handler->display->display_options['relationships']['field_client_target_id']['table'] = 'field_data_field_client';
  $handler->display->display_options['relationships']['field_client_target_id']['field'] = 'field_client_target_id';
  $handler->display->display_options['relationships']['field_client_target_id']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Punch */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_punch';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::timeclock_payroll_approval_approve' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Punch: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Punch ID';
  $handler->display->display_options['fields']['id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['text'] = '[id]';
  $handler->display->display_options['fields']['id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['path'] = 'punch/punch/[id]';
  $handler->display->display_options['fields']['id']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['preserve_tags'] = '<a>';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Punch: In */
  $handler->display->display_options['fields']['field_in_1']['id'] = 'field_in_1';
  $handler->display->display_options['fields']['field_in_1']['table'] = 'field_data_field_in';
  $handler->display->display_options['fields']['field_in_1']['field'] = 'field_in';
  $handler->display->display_options['fields']['field_in_1']['label'] = 'Date';
  $handler->display->display_options['fields']['field_in_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_in_1']['settings'] = array(
    'format_type' => 'just_date_common',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: Employee */
  $handler->display->display_options['fields']['field_employee']['id'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['table'] = 'field_data_field_employee';
  $handler->display->display_options['fields']['field_employee']['field'] = 'field_employee';
  $handler->display->display_options['fields']['field_employee']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_employee']['alter']['text'] = '[field_employee]';
  $handler->display->display_options['fields']['field_employee']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_employee']['alter']['path'] = 'punches?realname=[field_employee]';
  $handler->display->display_options['fields']['field_employee']['settings'] = array(
    'link' => 0,
  );
  /* Field: Punch: In */
  $handler->display->display_options['fields']['field_in']['id'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['table'] = 'field_data_field_in';
  $handler->display->display_options['fields']['field_in']['field'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['settings'] = array(
    'format_type' => 'just_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: out */
  $handler->display->display_options['fields']['field_out']['id'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['table'] = 'field_data_field_out';
  $handler->display->display_options['fields']['field_out']['field'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['settings'] = array(
    'format_type' => 'just_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: Length */
  $handler->display->display_options['fields']['field_length']['id'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['table'] = 'field_data_field_length';
  $handler->display->display_options['fields']['field_length']['field'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['element_type'] = 'strong';
  /* Field: Punch: Overtime Hours */
  $handler->display->display_options['fields']['field_overtime_hours']['id'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['table'] = 'field_data_field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['field'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['label'] = 'OT';
  $handler->display->display_options['fields']['field_overtime_hours']['type'] = 'custom_formatters_seconds_to_h_m_s';
  $handler->display->display_options['fields']['field_overtime_hours']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Punch: Job */
  $handler->display->display_options['fields']['field_job']['id'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['table'] = 'field_data_field_job';
  $handler->display->display_options['fields']['field_job']['field'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['settings'] = array(
    'link' => 1,
  );
  /* Field: Punch: Payroll Approval */
  $handler->display->display_options['fields']['field_payroll_approval']['id'] = 'field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['table'] = 'field_data_field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['field'] = 'field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['text'] = '<h2 class="green">&#x2714;</h2>';
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['path'] = '/punch/punch/[id]';
  $handler->display->display_options['fields']['field_payroll_approval']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['type'] = 'list_key';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Date';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_in_1]';
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Edited';
  $handler->display->display_options['fields']['php_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_2']['empty_zero'] = TRUE;
  /* Field: Punch: has been edited */
  $handler->display->display_options['fields']['field_has_been_edited']['id'] = 'field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['table'] = 'field_data_field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['field'] = 'field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['label'] = 'Edited';
  $handler->display->display_options['fields']['field_has_been_edited']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['text'] = '*';
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['path'] = 'punch/punch/[id]/revisions';
  $handler->display->display_options['fields']['field_has_been_edited']['element_type'] = '0';
  $handler->display->display_options['fields']['field_has_been_edited']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['type'] = 'list_key';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Open Exceptions';
  $handler->display->display_options['fields']['php']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php']['empty_zero'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Flagged';
  $handler->display->display_options['fields']['php_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = TRUE;
  /* Field: Punch: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Punch: Id */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'eck_punch';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  $handler->display->display_options['sorts']['id']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['id']['expose']['label'] = 'Punch ID';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Job: Primary Office Staff (field_primary_office_staff) */
  $handler->display->display_options['arguments']['field_primary_office_staff_target_id']['id'] = 'field_primary_office_staff_target_id';
  $handler->display->display_options['arguments']['field_primary_office_staff_target_id']['table'] = 'field_data_field_primary_office_staff';
  $handler->display->display_options['arguments']['field_primary_office_staff_target_id']['field'] = 'field_primary_office_staff_target_id';
  $handler->display->display_options['arguments']['field_primary_office_staff_target_id']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['arguments']['field_primary_office_staff_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_primary_office_staff_target_id']['breadcrumb'] = 'My Jobs\' Punches';
  $handler->display->display_options['arguments']['field_primary_office_staff_target_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_primary_office_staff_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_primary_office_staff_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_primary_office_staff_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_primary_office_staff_target_id']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['field_primary_office_staff_target_id']['validate_options']['roles'] = array(
    3 => '3',
  );
  $handler->display->display_options['arguments']['field_primary_office_staff_target_id']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Punch: punch type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'punch' => 'punch',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date: Date (eck_punch) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['default_date'] = '-2 weeks';
  $handler->display->display_options['filters']['date_filter_1']['default_to_date'] = '+1 year';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+1';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'field_data_field_in.field_in_value' => 'field_data_field_in.field_in_value',
  );
  /* Filter criterion: Job: Department (field_department) */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['filters']['field_department_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_department_tid']['value'] = array(
    9 => '9',
    10 => '10',
    11 => '11',
    8 => '8',
    7 => '7',
    2 => '2',
    3 => '3',
  );
  $handler->display->display_options['filters']['field_department_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    4 => '4',
    7 => '7',
    6 => '6',
    3 => '3',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_department_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_department_tid']['vocabulary'] = 'department';
  $handler->display->display_options['filters']['field_department_tid']['hierarchy'] = 1;
  /* Filter criterion: Client: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_client';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_client_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Client';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  /* Filter criterion: Punch: Payroll Approval (field_payroll_approval) */
  $handler->display->display_options['filters']['field_payroll_approval_value']['id'] = 'field_payroll_approval_value';
  $handler->display->display_options['filters']['field_payroll_approval_value']['table'] = 'field_data_field_payroll_approval';
  $handler->display->display_options['filters']['field_payroll_approval_value']['field'] = 'field_payroll_approval_value';
  $handler->display->display_options['filters']['field_payroll_approval_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_payroll_approval_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['operator_id'] = 'field_payroll_approval_value_op';
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['label'] = 'Payroll Approval';
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['operator'] = 'field_payroll_approval_value_op';
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['identifier'] = 'field_payroll_approval_value';
  $handler->display->display_options['filters']['field_payroll_approval_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'punches';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Punches';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['recent_punches'] = $view;

  $view = new view();
  $view->name = 'timesheet';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_punch';
  $view->human_name = 'timesheet';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view timeclock punches';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'views_bulk_operations' => 'views_bulk_operations',
    'field_in' => 'field_in',
    'field_out' => 'field_out',
    'field_length' => 'field_length',
    'field_overtime_hours' => 'field_overtime_hours',
    'field_job' => 'field_job',
    'field_payroll_approval' => 'field_payroll_approval',
    'field_has_been_edited' => 'field_has_been_edited',
    'php_1' => 'php_1',
    'php' => 'php',
    'edit_link' => 'edit_link',
    'php_2' => 'php_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'views_bulk_operations' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_in' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_out' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_length' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_overtime_hours' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_job' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_payroll_approval' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_has_been_edited' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'php_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'edit_link' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'php_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '1';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  /* Field: Punch: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Punch: In */
  $handler->display->display_options['fields']['field_in']['id'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['table'] = 'field_data_field_in';
  $handler->display->display_options['fields']['field_in']['field'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: out */
  $handler->display->display_options['fields']['field_out']['id'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['table'] = 'field_data_field_out';
  $handler->display->display_options['fields']['field_out']['field'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: Length */
  $handler->display->display_options['fields']['field_length']['id'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['table'] = 'field_data_field_length';
  $handler->display->display_options['fields']['field_length']['field'] = 'field_length';
  /* Field: Punch: Overtime Hours */
  $handler->display->display_options['fields']['field_overtime_hours']['id'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['table'] = 'field_data_field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['field'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['type'] = 'custom_formatters_seconds_to_h_m_s';
  $handler->display->display_options['fields']['field_overtime_hours']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Punch: Job */
  $handler->display->display_options['fields']['field_job']['id'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['table'] = 'field_data_field_job';
  $handler->display->display_options['fields']['field_job']['field'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['settings'] = array(
    'link' => 1,
  );
  /* Field: Punch: Payroll Approval */
  $handler->display->display_options['fields']['field_payroll_approval']['id'] = 'field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['table'] = 'field_data_field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['field'] = 'field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['text'] = '<h2 class="green">&#x2714;</h2>';
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['path'] = '/punch/punch/[id]';
  $handler->display->display_options['fields']['field_payroll_approval']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['type'] = 'list_key';
  /* Field: Punch: has been edited */
  $handler->display->display_options['fields']['field_has_been_edited']['id'] = 'field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['table'] = 'field_data_field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['field'] = 'field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['label'] = 'Edited';
  $handler->display->display_options['fields']['field_has_been_edited']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['text'] = '*';
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['path'] = 'punch/punch/[id]/revisions';
  $handler->display->display_options['fields']['field_has_been_edited']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['type'] = 'list_key';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Flagged';
  $handler->display->display_options['fields']['php_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Edited';
  /* Field: Punch: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = '';
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  /* Sort criterion: Punch: In (field_in) */
  $handler->display->display_options['sorts']['field_in_value']['id'] = 'field_in_value';
  $handler->display->display_options['sorts']['field_in_value']['table'] = 'field_data_field_in';
  $handler->display->display_options['sorts']['field_in_value']['field'] = 'field_in_value';
  /* Contextual filter: Punch: Employee (field_employee) */
  $handler->display->display_options['arguments']['field_employee_target_id']['id'] = 'field_employee_target_id';
  $handler->display->display_options['arguments']['field_employee_target_id']['table'] = 'field_data_field_employee';
  $handler->display->display_options['arguments']['field_employee_target_id']['field'] = 'field_employee_target_id';
  $handler->display->display_options['arguments']['field_employee_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_employee_target_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['field_employee_target_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['field_employee_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_employee_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_employee_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Punch: punch type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'punch' => 'punch',
  );
  /* Filter criterion: Date: Date (eck_punch) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'eck_punch';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'current-pay-period-start';
  $handler->display->display_options['filters']['date_filter']['default_to_date'] = 'current-pay-period-end';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+1';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_in.field_in_value' => 'field_data_field_in.field_in_value',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Punch: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Bulk operations: Punch */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_punch';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  /* Field: Punch: In */
  $handler->display->display_options['fields']['field_in']['id'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['table'] = 'field_data_field_in';
  $handler->display->display_options['fields']['field_in']['field'] = 'field_in';
  $handler->display->display_options['fields']['field_in']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: out */
  $handler->display->display_options['fields']['field_out']['id'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['table'] = 'field_data_field_out';
  $handler->display->display_options['fields']['field_out']['field'] = 'field_out';
  $handler->display->display_options['fields']['field_out']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Punch: Length */
  $handler->display->display_options['fields']['field_length']['id'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['table'] = 'field_data_field_length';
  $handler->display->display_options['fields']['field_length']['field'] = 'field_length';
  /* Field: Punch: Overtime Hours */
  $handler->display->display_options['fields']['field_overtime_hours']['id'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['table'] = 'field_data_field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['field'] = 'field_overtime_hours';
  $handler->display->display_options['fields']['field_overtime_hours']['type'] = 'custom_formatters_seconds_to_h_m_s';
  $handler->display->display_options['fields']['field_overtime_hours']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Punch: Job */
  $handler->display->display_options['fields']['field_job']['id'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['table'] = 'field_data_field_job';
  $handler->display->display_options['fields']['field_job']['field'] = 'field_job';
  $handler->display->display_options['fields']['field_job']['settings'] = array(
    'link' => 1,
  );
  /* Field: Punch: Payroll Approval */
  $handler->display->display_options['fields']['field_payroll_approval']['id'] = 'field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['table'] = 'field_data_field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['field'] = 'field_payroll_approval';
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['text'] = '<h2 class="green">&#x2714;</h2>';
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['alter']['path'] = '/punch/punch/[id]';
  $handler->display->display_options['fields']['field_payroll_approval']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_payroll_approval']['type'] = 'list_key';
  /* Field: Punch: has been edited */
  $handler->display->display_options['fields']['field_has_been_edited']['id'] = 'field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['table'] = 'field_data_field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['field'] = 'field_has_been_edited';
  $handler->display->display_options['fields']['field_has_been_edited']['label'] = 'Edited';
  $handler->display->display_options['fields']['field_has_been_edited']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['text'] = '*';
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['alter']['path'] = 'punch/punch/[id]/revisions';
  $handler->display->display_options['fields']['field_has_been_edited']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_has_been_edited']['type'] = 'list_key';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Flagged';
  $handler->display->display_options['fields']['php_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Edited';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Open Exceptions';
  $handler->display->display_options['fields']['php_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_2']['empty_zero'] = TRUE;
  /* Field: Punch: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_punch';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = '';
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  $handler->display->display_options['path'] = 'user/%/timesheet/supervisor';
  $export['timesheet'] = $view;

  return $export;
}
