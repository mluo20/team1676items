<?php

include 'includes/templates/header.php';

$news = Article::getList();

$count = $news['count'];

$articles = $news['articles'];

?>

<div class="container offset">
<br><br>
<h1 class="page-header white text-center">Archive</h1>

<?php

foreach ($articles as $article) {

    $date = date("F j, Y", strtotime($article->date));
    $description = nl2br($article->description);
    $readmore = $article->link == "" ? "" : "<a class=\"btn btn-md\" target=\"_blank\">Read More</a>";

    echo <<<_END
    <div class="row">
      <div class="col-sm-6 col-sm-offset-3"> 
          <div class="panel panel-default">
            <div class="panel-heading">$date</div>
            <div class="panel-body">
              <h3>$article->title</h3>
              $description
              $readmore
            </div>
          </div>
      </div>
     </div>
_END;

}

?>

</div>

<?php

include 'includes/templates/footer.php';

?>