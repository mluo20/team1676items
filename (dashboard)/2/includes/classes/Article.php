<?php

class Article {

  public $id = null;

  public $title = null;
  
  public $description = null;

  public $date = null;

  public $link = null;
 
  public function __construct($data = array()) {

    if ( isset( $data['id'] ) ) $this->id = (int) $data['id'];
    if ( isset( $data['title'] ) ) $this->title = $data['title'];
    if ( isset( $data['description'] ) ) $this->description = $data['description'];
    if ( isset( $data['date'] ) ) $this->date = $data['date'];
    if ( isset( $data['link'] ) ) $this->link = $data['link'];

  }
 
  public function storeFormValues($params) {

    global $conn;
  	$params['description'] = $conn->real_escape_string($params['description']);
    $this->__construct( $params );

  }
 
  /**
  * Returns an Article object matching the given article ID
  *
  * @param int The article ID
  * @return Article|false The article object, or false if the record was not found or there was a problem
  */
 
  public static function getById($id) {

    global $conn;

    $query = "SELECT * FROM news WHERE id = $id";
    $result = $conn->query($query);
    if (!$result) echo "<p>Something went wrong<br>" . $conn->error . "</p>";
    $result->data_seek(0);
    $row = $result->fetch_array(MYSQL_ASSOC);
    if ($row) return new Article($row);

  }
 
 
  /**
  * Returns all (or a range of) Article objects in the DB
  *
  * @param int Optional The number of rows to return (default=all)
  * @param string Optional column by which to order the articles (default="publicationDate DESC")
  * @return Array|false A two-element array : results => array, a list of Article objects; totalRows => Total number of articles
  */
 
  public static function getList( $numRows = 1000000, $order = "date DESC") {
  	//lol you should put the getting the count of articles back lololol
    global $conn;

    $query = "SELECT * FROM news ORDER BY $order LIMIT $numRows";
 
    $result = $conn->query($query);
    if (!$result) echo "<p>Something went wrong<br>" . $conn->error . "</p>";
    $articles = array();
    $rows = $result->num_rows;
 
    for ($i = 0; $i < $rows; $i++) {
    	$result->data_seek($i);
    	$row = $result->fetch_array(MYSQL_ASSOC);
      	$article = new Article( $row );
      	$articles[] = $article;
    }
 
    // Now get the total number of articles that matched the criteria
    $query = "SELECT COUNT(*) AS count FROM news";
    $result = $conn->query($query);
    if (!$result) echo "<p>Something went wrong<br>" . $conn->error . "</p>";
    $result->data_seek(0);
    $row = $result->fetch_array(MYSQL_ASSOC);
    $count = $row['count'];

    $list = array('articles' => $articles, 'count' => $count);
    return $list;
  }
 
 
  /**
  * Inserts the current Article object into the database, and sets its ID property.
  */
 
  public function insert() {
 
    // Does the Article object already have an ID?
    if ( !is_null( $this->id ) ) trigger_error ( "Article::insert(): Attempt to insert an Article object that already has its ID property set (to $this->id).", E_USER_ERROR );
 
    // Insert the Article
    global $conn;

    $query = "INSERT INTO articles (title, description, link) VALUES ('$this->title', '$this->description', '$this->link')";
    $result = $conn->query($query);
    if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
    $this->id = $conn->insert_id;

    $query = "SELECT `date` FROM articles WHERE `id` = {$this->id}";
    $result = $conn->query($query);
    if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
    $result->data_seek(0);
    $row = $result->fetch_array(MYSQL_ASSOC);
    $this->date = $row['date'];

  }

  // public function save($title) {
 
  //   // Insert the Article
  //   global $conn;

  //   $title = $conn->real_escape_string($title);
  //   $this->title = $title;

  //   $query = "INSERT INTO saved_articles (title, description) VALUES ('$this->title', NULL) ";
  //   $result = $conn->query($query);
  //   if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
  //   $this->id = $conn->insert_id;

  //   $query = "SELECT `date` FROM articles WHERE `id` = {$this->id}";
  //   $result = $conn->query($query);
  //   if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
  //   $result->data_seek(0);
  //   $row = $result->fetch_array(MYSQL_ASSOC);
  //   $this->date = $row['date'];
    
  // }
 
 
  /**
  * Updates the current Article object in the database.
  */
 
  public function update() {
 
    // Update the Article
    global $conn;
    $this->title = $conn->real_escape_string($this->title);
    $query = "UPDATE news SET title='$this->title', description='$this->description', link='$this->link' WHERE id = $this->id";
    $result = $conn->query($query);
    if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";

  }
 
 
  /**
  * Deletes the current Article object from the database.
  */
 
  public function delete() {
 
    // Delete the Article
    global $conn;
    $query = "DELETE FROM news WHERE id = $this->id";
    $result = $conn->query($query);
    if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";

  }

}