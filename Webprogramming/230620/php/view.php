<form method=post action=view.php>
   <input type=radio name=order value=asc checked>오름차순</input><br>
   <input type=radio name=order value=desc>내림차순</input><br>
   <input type=submit value=확인>
</form>
<?php
//데이터베이스에 있는 내용을 테이블로 출력
//mysql 연결
$conn = mysqli_connect('localhost', 'root', '', 'bssm_db');
//데이터 읽어오는 쿼리 작성
$query = "select * from bssm_data order by data_num ".$_POST['order']." limit 15;"; //출력 수
//sql 쿼리 실행
$result = mysqli_query($conn, $query);
//결과 출력
echo "<table border=1 width=500>";
   echo "<tr><td>순번</td><td>온도('C)</td><td>습도(%)</td></tr>";
    $i = 0;
   while($row = mysqli_fetch_assoc($result)) {
      $mylabel[$i] = $row['data_num'];
      $mytemp[$i] = $row['data_temp'];
      $myhumi[$i] = $row['data_humi'];
      if($i == 0){
         $mytemp2 = $row['data_temp'];
         $myhumi2 = $row['data_humi']; 
      }
      $i++;
        echo "<tr><td>".$row['data_num'] ."</td><td>".$row['data_temp'] ."</td><td>".$row['data_humi'] ."</td></tr>"; // *
    }
echo "</table>";
echo "<table border=1 width=600>";
   echo "<tr><td colspan=2>";
   include 'graph.php';
   echo "</td></tr>";
   echo "</table>";
?>
