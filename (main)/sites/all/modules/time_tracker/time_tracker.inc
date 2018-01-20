<?php

/**
 * @file
 * Defines time_tracker entity types.
 */

/**
 * TimeTrackerEntryControllerInterface definition.
 *
 * We create an interface here because anyone could come along and
 * use hook_entity_info_alter() to change our controller class.
 * We want to let them know what methods our class needs in order
 * to function with the rest of the module, so here's a handy list.
 *
 * @see hook_entity_info_alter()
 */
interface TimeTrackerEntryControllerInterface
  extends DrupalEntityControllerInterface {

  /**
   * Create a new time tracker entry entity.
   *
   * @return Object
   *   The entity.
   */
  public function create();

  /**
   * Save a time tracker entry entity.
   *
   * @param Object $entity
   *   The entity we want to save.
   *
   * @return Object
   *   The entity we just saved.
   */
  public function save($entity);

  /**
   * Delete a time tracker entry entity.
   *
   * @param Object $entity
   *   The entity we want to delete.
   */
  public function delete($entity);
}

/**
 * TimeTrackerEntryController extends DrupalDefaultEntityController.
 *
 * Our subclass of DrupalDefaultEntityController lets us add a few
 * important create, update, and delete methods.
 */
class TimeTrackerEntryController
  extends DrupalDefaultEntityController
  implements TimeTrackerEntryControllerInterface {

  /**
   * {@inheritdoc}
   */
  public function create() {
    $entity = new stdClass();
    $entity->type = 'time_tracker_entry';

    $entity->bundle = 'time_tracker_entry';
    $entity->item_description = '';
    return $entity;
  }

  /**
   * {@inheritdoc}
   */
  public function save($entity) {
    // Invoke hook_entity_presave().
    module_invoke_all('entity_presave', $entity, 'time_tracker_entry');
    // The 'primary_keys' argument determines whether this will be an insert
    // or an update. So if the entity already has an ID, we'll specify
    // basic_id as the key.
    $primary_keys = isset($entity->teid) ? 'teid' : array();
    // Write out the entity record.
    drupal_write_record('time_tracker_entry', $entity, $primary_keys);
    // We're going to invoke either hook_entity_update() or
    // hook_entity_insert(), depending on whether or not this is a
    // new entity. We'll just store the name of hook_entity_insert()
    // and change it if we need to.
    $invocation = 'entity_insert';
    // Now we need to either insert or update the fields which are
    // attached to this entity. We use the same primary_keys logic
    // to determine whether to update or insert, and which hook we
    // need to invoke.
    if (empty($primary_keys)) {
      field_attach_insert('time_tracker_entry', $entity);
    }
    else {
      field_attach_update('time_tracker_entry', $entity);
      $invocation = 'entity_update';
    }
    // Invoke either hook_entity_update() or hook_entity_insert().
    module_invoke_all($invocation, $entity, 'time_tracker_entry');

    return $entity;
  }

  /**
   * {@inheritdoc}
   */
  public function delete($entity) {
    $this->delete_multiple(array($entity));
  }

  /**
   * Delete one or more time_tracker_entry entities.
   *
   * Deletion is unfortunately not supported in the base
   * DrupalDefaultEntityController class.
   *
   * @param array $entities
   *   An array of entities.
   *
   * @throws \Exception
   */
  public function delete_multiple($entities) {
    $teids = array();
    if (!empty($entities)) {
      $transaction = db_transaction();
      try {
        foreach ($entities as $entity) {
          module_invoke_all('time_tracker_entry_delete', $entity);
          // Invoke hook_entity_delete().
          module_invoke_all('entity_delete', $entity, 'time_tracker_entry');
          field_attach_delete('time_tracker_entry', $entity);
          $teids[] = $entity->teid;
        }
        db_delete('time_tracker_entry')
          ->condition('teid', $teids, 'IN')
          ->execute();
      }
      catch (Exception $e) {
        $transaction->rollback();
        watchdog_exception('time_tracker', $e);
        throw $e;
      }
    }
  }
}

/**
 * TimeTrackerActivityControllerInterface definition.
 *
 * We create an interface here because anyone could come along and
 * use hook_entity_info_alter() to change our controller class.
 * We want to let them know what methods our class needs in order
 * to function with the rest of the module, so here's a handy list.
 *
 * @see hook_entity_info_alter()
 */
interface TimeTrackerActivityControllerInterface
  extends DrupalEntityControllerInterface {

  /**
   * Create a new time tracker entry entity.
   *
   * @return Object
   *   The entity.
   */
  public function create();

  /**
   * Save a time tracker entry entity.
   *
   * @param Object $entity
   *   The entity we want to save.
   *
   * @return Object
   *   The entity we just saved.
   */
  public function save($entity);

  /**
   * Delete a time tracker entry entity.
   *
   * @param Object $entity
   *   The entity we want to delete.
   */
  public function delete($entity);
}

/**
 * TimeTrackerActivityController extends DrupalDefaultEntityController.
 *
 * Our subclass of DrupalDefaultEntityController lets us add a few
 * important create, update, and delete methods.
 */
class TimeTrackerActivityController
  extends DrupalDefaultEntityController
  implements TimeTrackerActivityControllerInterface {

  /**
   * {@inheritdoc}
   */
  public function create() {
    $entity = new stdClass();
    $entity->type = 'time_tracker_activity';

    $entity->bundle = 'activity';
    $entity->item_description = '';
    return $entity;
  }

  /**
   * {@inheritdoc}
   */
  public function save($entity) {
    // Invoke hook_entity_presave().
    module_invoke_all('entity_presave', $entity, 'time_tracker_activity');
    // The 'primary_keys' argument determines whether this will be an insert
    // or an update. So if the entity already has an ID, we'll specify
    // taid as the key.
    $primary_keys = isset($entity->taid) ? 'taid' : array();
    // Write out the entity record.
    drupal_write_record('time_tracker_activity', $entity, $primary_keys);
    // We're going to invoke either hook_entity_update() or
    // hook_entity_insert(), depending on whether or not this is a
    // new entity. We'll just store the name of hook_entity_insert()
    // and change it if we need to.
    $invocation = 'entity_insert';
    // Now we need to either insert or update the fields which are
    // attached to this entity. We use the same primary_keys logic
    // to determine whether to update or insert, and which hook we
    // need to invoke.
    if (empty($primary_keys)) {
      field_attach_insert('time_tracker_activity', $entity);
    }
    else {
      field_attach_update('time_tracker_activity', $entity);
      $invocation = 'entity_update';
    }
    // Invoke either hook_entity_update() or hook_entity_insert().
    module_invoke_all($invocation, $entity, 'time_tracker_activity');

    return $entity;
  }

  /**
   * {@inheritdoc}
   */
  public function delete($entity) {
    $this->delete_multiple(array($entity));
  }

  /**
   * Delete one or more time_tracker_activity entities.
   *
   * Deletion is unfortunately not supported in the base
   * DrupalDefaultEntityController class.
   *
   * @param array $entities
   *   An array of entities.
   *
   * @throws \Exception
   */
  public function delete_multiple($entities) {
    $taids = array();
    if (!empty($entities)) {
      $transaction = db_transaction();
      try {
        foreach ($entities as $entity) {
          module_invoke_all('time_tracker_activity_delete', $entity);
          // Invoke hook_entity_delete().
          module_invoke_all('entity_delete', $entity, 'time_tracker_activity');
          field_attach_delete('time_tracker_activity', $entity);
          $taids[] = $entity->taid;
        }
        db_delete('time_tracker_activity')
          ->condition('taid', $taids, '=')
          ->execute();

      }
      catch (Exception $e) {
        $transaction->rollback();
        watchdog_exception('time_tracker', $e);
        throw $e;
      }
    }
  }
}
