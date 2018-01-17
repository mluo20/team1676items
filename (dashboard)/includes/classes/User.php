<?php

class User {

  public $id = null;

  public $username = null;
  
 	public $password = null;

  public $email = null;

  public $website = null;

	public $description = null;

	public $join_date = null;

	public $ACL = null;

	public function __construct($data = array()) {
		if ( isset( $data['id'] ) ) $this->id = (int) $data['id'];
    if ( isset( $data['username'] ) ) $this->username = $data['username'];
    if ( isset( $data['password'] ) ) $this->password = $data['password'];
    if ( isset( $data['email'] ) ) $this->email = $data['email'];
    if ( isset( $data['website'] ) ) $this->website = $data['website'];
    if ( isset( $data['description'] ) ) $this->description = $data['description'];
    if ( isset( $data['join_date'] ) ) $this->join_date = $data['join_date'];
    if ( isset( $data['ACL'] ) ) $this->ACL = $data['ACL'];
	}

	public static function get_by_id($id) {
		
	}

	public static function get_list() {
		
	}

	public function add() {
		
	}

  public function update() {
    
  }

  public function delete() {

  }

}