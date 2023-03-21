<?php

	$name = $_POST['myname'];
	$age = $_POST['myage'];
	$gender = $_POST['mygender'];
	$height = $_POST['myheight'];

	//MYSQL연결
	$conn = mysqli_connect('localhost', 'root', '', 'example1');
	//데이터를 insert하는 SQL쿼리 작성
	$query = "insert into table1(name,age,gender,height) values('".$name."',".$age.",'".$gender."',".$height.");";
	//SQL쿼리를 실행
	$result = mysqli_query($conn, $query);
	//실행결과 확인
	if($result){
		echo "성공";
	}else{
		echo "실패";
	}
?>

<meta http-equiv="refresh" content="0; url=input.php">