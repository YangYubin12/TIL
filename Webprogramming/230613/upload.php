<?php
   //ESP32에서 온습도센서값을 받아 데이터베이스에 저장하는 페이지
   $temp = $_GET['temp']; //ESP가 업로드하는 온도값의 key값
   $humi = $_GET['humi']; //ESP가 업로드하는 습도값의 key값

   //데이터베이스 접속
   $conn = mysqli_connect('localhost', 'root', '','test2_3'); //test2_3: DB이름
   $query = "insert into test(temp, humi) values(".$temp.",".$humi.");"; //test: table 이름, temp: 온도필드명, humi: 습도 필드명

   //SQL쿼리 실행
    $result = mysqli_query($conn, $query);
    //실행결과 확인
    if($result){
     echo "성공";
    }else{
     echo "실패";
    }
    
?>
