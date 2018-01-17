<?php

class Page {

	public $id = null;

	public $title = null;

	public $content = null;

	public $pageorder = null;

	public $category = null;

	public $label = null;

	public $showing = null;

	public function __construct($data = array()) {

		global $conn;

		if ( isset( $data['id'] ) ) $this->id = (int) $data['id'];
	    if ( isset( $data['title'] ) ) $this->title = $data['title'];
	    if ( isset( $data['content'] ) ) $this->content = $data['content'];
	    if ( isset( $data['pageorder'] ) ) $this->pageorder = $data['pageorder'];
	   	if ( isset( $data['category'] ) ) $this->category = $data['category'];
	    if ( isset( $data['label'] ) ) $this->label = $data['label'];
	    if ( isset( $data['showing'] ) ) $this->showing = $data['showing'];

	    $this->title = $conn->real_escape_string($this->title);
	    $this->label = $conn->real_escape_string($this->label);

	}

	public function storeFormValues($params) {
	    $this->__construct( $params );
  	}

  	public static function getById($id) {

  		global $conn;

	    $query = "SELECT * FROM pages WHERE id = $id";
	    $result = $conn->query($query);
	    if (!$result) echo "<p>Something went wrong<br>" . $conn->error . "</p>";
	    $result->data_seek(0);
	    $row = $result->fetch_array(MYSQL_ASSOC);
	    $page = new Page($row);
	    $page->title = stripslashes($page->title);
	    return $page;

  	}

  	public static function getList($catid) {

  		global $conn;

	    $query = "SELECT * FROM pages WHERE category = $catid ORDER BY category, pageorder";
	 
	    $result = $conn->query($query);
	    if (!$result) echo "<p>Something went wrong<br>" . $conn->error . "</p>";
	    $pages = array();
	    $rows = $result->num_rows;
	 
	    for ($i = 0; $i < $rows; $i++) {
	    	$result->data_seek($i);
	    	$row = $result->fetch_array(MYSQL_ASSOC);
	      	$page = new Page( $row );
	      	$pages[] = $page;
	    }
	 
	    // Now get the total number of pages that matched the criteria
	    $query = "SELECT COUNT(*) AS count FROM pages";
	    $result = $conn->query($query);
	    if (!$result) echo "<p>Something went wrong<br>" . $conn->error . "</p>";
	    $result->data_seek(0);
	    $row = $result->fetch_array(MYSQL_ASSOC);
	    $count = $row['count'];

	    $list = array('pages' => $pages, 'count' => $count);
	    return $list;

  	}

  	public function insert() {
 		global $conn;
	    // Does the page object already have an ID?
	    if ( !is_null( $this->id ) ) trigger_error ( "page::insert(): Attempt to insert an page object that already has its ID property set (to $this->id).", E_USER_ERROR );
	 
	    // Insert the page

	    $query = "INSERT INTO pages (title, content, pageorder, category, label, showing) VALUES ('$this->title', '$this->content', '$this->pageorder', '$this->category', '$this->label', '$this->showing')";
	    $result = $conn->query($query);
	    if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
	    $this->id = $conn->insert_id;
	}

	public function save() {
		global $conn;
		$query = "INSERT INTO pages (title, content, pageorder, category, label, showing) VALUES ('$this->title', '$this->content', '$this->pageorder', '$this->category', '$this->label', '0')";
	    $result = $conn->query($query);
	    if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
	    $this->id = $conn->insert_id;
	}

	public function update() {
 		global $conn;
	    $this->title = $conn->real_escape_string($this->title);
	    $query = "UPDATE pages SET title='$this->title', content='$this->content', pageorder = $this->pageorder, category = $this->category, label = '$this->label', showing = $this->showing WHERE id = $this->id";
	    $result = $conn->query($query);
	    if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";

	}
	 
	public function delete() {
	 	global $conn;
	    $query = "DELETE FROM pages WHERE id = $this->id";
	    $result = $conn->query($query);
	    if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";

	 }

}