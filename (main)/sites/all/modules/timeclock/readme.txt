CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Installation
 * Configuration
 * Maintainers

 INTRODUCTION
 ------------

 The Timeclock module is a group of modules to allow for tracking employee's time and attendance. Allows for web and
 telephone based (DTMF) timeclock punches, as well as after the fact entry of times. Employees are Drupal users,
 timeclock punch entities relating to the user.

  * For a full description of the module, visit the project page:
    https://drupal.org/project/timeclock

  * To submit bug reports and feature suggestions, or to track changes:
    https://drupal.org/project/issues/timeclock

REQUIREMENTS
------------

This module requires the following modules:

 * User Pin (https://drupal.org/project/user_pin)
 * Views (https://drupal.org/project/views)
 * Date API (contrib)
 * Date Views (contrib)
 * Computed Field (contrib)
 * Custom Formatters (contrib)
 * Date(contrib)
 * Entity Construction Kit (contrib)
 * Entity API (contrib)
 * Entity Reference (contrib)
 * Features (contrib)
 * Strongarm (contrib)
 * Field Permissions (contrib)

INSTALLATION
------------

  * Install as you would normally install a contributed Drupal module. See:
    https://drupal.org/documentation/install/modules-themes/modules-7
    for further information.

CONFIGURATION
-------------

 * Configure user permissions in Administration » People » Permissions:
 * Create at least one "Department" in Administration » Structure » Taxonomy » Department.
 * Create at least one "Client" in Administration » Structure » Entity types » Client » Client
 * Create at least one "Job" which references existing "Client" and "Department"
    - in Administration » Structure » Entity types » Job » Job
 * Test clock in/out by supplying a Job ID in the Timeclock block while signed in as a user with
    - the "Submit Timeclock Punches" permission.

MAINTAINERS
-----------

Current maintainers:
 * Benjamin Townsend (benjaminarthurt) - https://www.drupal.org/user/2501220

This project has been sponsored by:
ARISE Child and Family Service Inc. - Sponsored the initial development of this project.
Townsend Consulting Services - Adapted project for Drupal community use.