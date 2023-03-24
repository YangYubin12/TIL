<?php
   // msyql에 접속한다
   $conn = mysqli_connect('localhost', 'root', '', 'example1');
   // SQL쿼리를 만든다
   $query = "delete from table1 where num=" . $_GET['num'];
   $result = mysqli_query($conn, $query);

   if($result) {
      echo "삭제 성공";
   } else {
      echo "삭제 실패";
   }
?>
<meta http-equiv="refresh" content="0; url=input.php">