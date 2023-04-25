<?php include 'header.php';?>
<form method=post action=view.php>
   <select name="did" >
      <?php
         // device table에 있는 디바이스명으로 드롭다운 메뉴 생성
         $conn = mysqli_connect('localhost', 'root', '', 'bssm2_3');
         $query = "select * from device;";
         $result = mysqli_query($conn, $query);
         while($row = mysqli_fetch_assoc($result)) {
            echo "<option value='".$row['did']."'>".$row['did']."</option>";
         }
      ?>
   </select>
   
   <!-- 10개 20개 30개 중 선택, 기본값은 10 -->
   <br><input type=radio name=limit value=10 checked>10개</input><br>
   <input type=radio name=limit value=20>20개</input><br>
   <input type=radio name=limit value=30>30개</input><br>
   <br>정렬<br>
   <input type=radio name=order value=asc checked>오름차순</input><br>
   <input type=radio name=order value=desc>내림차순</input><br>
   <input type=submit value=확인>
</form>

<?php
   if(isset($_POST['did'])) {
      // 콤보박스에서 유저가 뭔가를 선택, submit
   } else {
      // view.php를 유저가 웹브라우저에서 단순히 open
      exit;
   }

   // MYSQL 접속
   $conn = mysqli_connect('localhost', 'root', '', 'bssm2_3');
   // SQL쿼리 생성
   $query = "select * from sensor where did='".$_POST['did']."' order by num ".$_POST['order']." limit ".$_POST['limit'].";";
   // 쿼리 실행
   $result = mysqli_query($conn, $query);
   // 데이터 출력
   //echo mysql_num_rows($result);
   echo "<table border=1 width=500>";
   echo "<tr>";
   echo "<td>번호</td>";
   echo "<td>디바이스아이디</td>";
   echo "<td>온도</td>";
   echo "<td>습도</td>";
   echo "<td>업로드시간</td>";
   echo "</tr>";

   $i=0;
   while($row = mysqli_fetch_assoc($result)) {
      $mylabel[$i]=$row['date'];
      $mytemp[$i]=$row['temp'];
      $myhumi[$i]=$row['humi'];
      if($i == 0){
         $mytemp2 = $row['temp'];
         $myhumi2 = $row['humi']; 
      }
      $i++;
      echo "<tr>";
         echo "<td>".$row['num']."</td>";
         echo "<td>".$row['did']."</td>";
         echo "<td>".$row['temp']."</td>";
         echo "<td>".$row['humi']."</td>";
         echo "<td>".$row['date']."</td>";
         echo "</tr>";
   }
   echo "</table>";

   //그래프 출력
   echo "<table border=1 width=600>";
   echo "<tr align=center><td>";
   include 'temp.php';
   echo "</td><td>";
   include 'humi.php';
   echo "</td><tr>";
   echo "<tr><td colspan=2>";
   include 'linegraph.php';
   echo "</td></tr>";
   echo "</table>";
   include 'footer.php';
?>
