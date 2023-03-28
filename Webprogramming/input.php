<?php
   // MYSQL에 접속한다
   $conn = mysqli_connect('localhost', 'root', '', 'example1');
   // SQL쿼리를 만든다
   $query = "select * from table1;";
   // 쿼리를 실행한다
   $result = mysqli_query($conn, $query);
   // 데이터를 출력한다
   echo "<table border=1 width=500>";
   echo "<tr>";
   echo "<td>번호</td>";
   echo "<td>이름</td>";
   echo "<td>나이</td>";
   echo "<td>성별</td>";
   echo "<td>키</td>";
   echo "<td>삭제</td>";
   echo "<td>수정</td>";
   echo "</tr>";
   while($row = mysqli_fetch_assoc($result)) {
      echo "<tr>";
         echo "<td>".$row['num']."</td>";
         echo "<td>".$row['name']."</td>";
         echo "<td>".$row['age']."</td>";
         echo "<td>".$row['gender']."</td>";
         echo "<td>".$row['height']."</td>";
         echo "<td><a href=delete.php?num=".$row['num'].">[삭제]</a></td>";
         echo "<td><a href=update.php?num=".$row['num'].">[수정]</a></td>";
      echo "</tr>";

   }
   echo "</table>";
?>

<form id=myform method=post action=process.php>
 이름:<input id=txt1 type=text name=myname><br>
 나이:<input id=txt2 type=text name=myage><br>
 성별:<input id=txt1 type=text name=mygender><br>
 키 : <input id=txt1 type=text name=myheight><br>
 <input id=mybtn1 type=submit value=확인>
</form>
