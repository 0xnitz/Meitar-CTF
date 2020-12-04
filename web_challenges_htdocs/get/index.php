<?php error_reporting(0) ?>
<!DOCTYPE html>
<html>
  <head>
    <title>My Super Awesome File Manager!</title>
    <link type="text/css" rel="stylesheet" href="style.css" />
  </head>
  <body>
    <header>
      <img src='/favicon.ico' />
      <h1><a href="/get">Best File Manager Ever</a></h1>
    </header>
    <div class="content">
      <? require_once('app.php.inc'); ?>
    </div>
  </body>
</html>