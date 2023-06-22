<?php
   //ESP32에서 온습도센서값을 받아 데이터베이스에 저장하는 페이지
   $temp = $_GET['data_temp']; //ESP가 업로드하는 온도값의 key값
   $humi = $_GET['data_humi']; //ESP가 업로드하는 습도값의 key값

   //데이터베이스 접속
   $conn = mysqli_connect('localhost', 'root', '','bssm_db'); //DB명
   $query = "insert into bssm_data(temp, humi) values(".$temp.",".$humi.");"; //test: table 이름, temp: 온도필드명, humi: 습도 필드명

   //SQL쿼리 실행
    $result = mysqli_query($conn, $query);

    //실행결과 확인
    if($result){
     echo "성공";
    }else{
     echo "실패";
    }
    
?>
