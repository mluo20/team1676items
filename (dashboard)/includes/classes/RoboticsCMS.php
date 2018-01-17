<?php

class RoboticsCMS {

	//add connection tools here?

	public function getEvents() {

		global $conn;

		$events = array();

		//get events
		$query = "SELECT * FROM events ORDER BY date";
		$result = $conn->query($query);
		if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
		$rows = $result->num_rows;
		if ($rows > 0) {
		    for ($i = 0; $i < $rows; $i++) {
		        $result->data_seek($i);
		        $row = $result->fetch_array(MYSQL_ASSOC);
		        $events[] = $row;
		    }
		}

		return $events;

	}

	public function delete($table, $id) {

		global $conn;

		$query = "DELETE FROM $table WHERE id = $id";
		$result = $conn->query($query);
		if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";

	}

	public function getById($table, $id) {

		global $conn;

		$query = "SELECT * FROM $table WHERE id = $id";
		$result = $conn->query($query);
		if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
	    $result->data_seek($i);
        $row = $result->fetch_array(MYSQL_ASSOC);
        return $row;

	}

	public function updateNews($values) {
		global $conn;
		extract($_POST);

		$query = "UPDATE news SET title = '$title', link = '$link', description = '<p>$description</p>' WHERE id = $id";
		$result = $conn->query($query);
		if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
	}

	public function addNews($values) {

		global $conn;

		extract($values);

		$description = nl2br($description);

		$query = "INSERT INTO news (title, description, link) VALUES ('$title', '<p>$description</p>', '$link')";
		$result = $conn->query($query);
		if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";

	}

	public function getNews() {

		global $conn;

		$news = array();
		$query = "SELECT * FROM news ORDER BY date DESC";
		$result = $conn->query($query);
		if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
		$rows = $result->num_rows;
	    for ($i = 0; $i < $rows; $i++) {
	        $result->data_seek($i);
	        $row = $result->fetch_array(MYSQL_ASSOC);
	        $row['title'] = stripslashes($row['title']);
	        $news[] = $row;
	    }
		return $news;

	}

	public function getCategories() {

		global $conn;

		$categories = array();
		$query = "SELECT * FROM categories ORDER BY catorder ASC";
		$result = $conn->query($query);
		if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
		$rows = $result->num_rows;
	    for ($i = 0; $i < $rows; $i++) {
	        $result->data_seek($i);
	        $row = $result->fetch_array(MYSQL_ASSOC);
	        $categories[] = $row;
	    }
		return $categories;
		
	}

	// public function getPages($id) {
	// 	return PagesgetList();
	// }

	public function display_articles() {

	}

	public function getSlider() {

		global $conn;

		$slider = array();
		$query = "SELECT * FROM slider_pics ORDER BY slider_order ASC";
		$result = $conn->query($query);
		if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
		$rows = $result->num_rows;
	    for ($i = 0; $i < $rows; $i++) {
	        $result->data_seek($i);
	        $row = $result->fetch_array(MYSQL_ASSOC);
	        $slider[] = $row;
	    }
		return $slider;

	}

	public function get_categories() {

		global $conn;

		$categories = array();
		$query = "SELECT * FROM categories ORDER BY catorder";
		$result = $conn->query($query);
		if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
		$rows = $result->num_rows;
	    for ($i = 0; $i < $rows; $i++) {
	        $result->data_seek($i);
	        $row = $result->fetch_array(MYSQL_ASSOC);
	        $categories[] = $row;
	    }

		return $categories;

	}

	public function add_cat() {

	}

}