<?php
include 'header.php';

// mysql 연결
$conn = mysqli_connect('localhost', 'root', '', 'bssm2_3');
// 데이터 읽어오는 쿼리를 작성
$query = "select * from gas order by date desc limit 1";
// sql 쿼리 실행
$result = mysqli_query($conn, $query);
// 결과 출력

echo "<table border=1 width=500>";
echo "<tr>";
echo "<th>가스농도</th>";
echo "<th>조도센서</th>";
echo "</tr>" ;

$row = mysqli_fetch_assoc($result);

echo "<tr>";
echo "<td>".$row['gas']."</td>";
echo "<td>".$row['cds']."</td>";
echo "</tr>" ;

if($row['gas'] >= 10){
    echo "<td>위험</td>";
} else{
    echo "<td>정상</td>";
}

if($row['cds'] > 1000){
    echo "<td>밤</td>";
} else{
    echo "<td>낮</td>";
}
echo "</tr>";
echo "</table>";
?>

<?php
include 'footer.php';
?>