<?php
  //get방식
  //http://localhost/example3.php?age=20&name=%22%EB%85%B9%EC%B9%B8%EB%8B%A4%22
  if(isset($_GET['name'])){
    echo $_GET['name'];
  }else{
    echo "존재하지않습니다";
    echo "<br>";
  }
  if(isset($_GET['age'])){
    echo $_GET['age'];
  }else{
    echo "존재하지않습니다";
    echo "<br>";
  }
?>
