여기는 html로 해석<br>
<?php
  /*
  //echo "여기는 php의 공간입니다.<br>";
  echo "<input type=text><br>";
  $num1  = 10;
  $num2 = "10";
  echo $num1*10 . "<br>";
  echo $num2*10
  */

  // 배열
  $num = [1,2,3,4,5,6];
  //echo count($num);
  $cnt = count($num);
  for($i=0;$i<$cnt;$i++){
    echo $num[$i] . "<br>"; //.->붙여서 출력
  }
?>

