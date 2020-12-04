<?php

$filesDir = 'files';
$fileIconPath = '/file-icon.png';

if (!isset($_GET['file'])) {
  echo '<ul>';
  foreach (scandir('files') as $file) {
    if ($file !== '.' && $file !== '..') {
      $attr = $file === 'flag.txt'
        ? 'onclick="alert(\'You really think this is going to be this easy? :)\')" class="forbidden"'
        : "onclick=\"document.location = '?file=$file'\"";
      echo "
      <li $attr>
        <img src=\"$fileIconPath\" />
        <span>$file</span>
      </li>";
    }
  }
  echo '</ul>';
} else {
  echo '<pre>';
  $filename = substr($_GET['file'], strrpos($_GET['file'], '/'));
  include("$filesDir/$filename");
  echo '</pre>';
}
