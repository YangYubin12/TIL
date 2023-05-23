<?php

$gas = $_GET['gas'];
$cds = $_GET['cds'];

date_default_timezone_set('Asia/Seoul');
$date= date("Y-m-d H:i:s", time());

$conn = mysqli_connect('localhost', 'root', '','BSSM2_3');
$query = "insert into gas(gas, cds, date) values(".$gas.",".$cds.",'".$date."')";
$result = mysqli_query($conn, $query);
if($result){
   echo '성공';
}
else{
   echo '실패';
}
?>

