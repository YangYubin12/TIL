<!DOCTYPE html>
<html>
<head>
<title></title>
<script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.1.4/Chart.bundle.min.js"></script>
<script type="text/javascript" charset="utf-8" src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.7.1/Chart.min.js"></script>
</head>
<body>
<div style="width:900px;">
<canvas id="line1"></canvas>
</div>

<script>
var ctx = document.getElementById('line1').getContext('2d');
var chart = new Chart(ctx, {
   type: 'line',
   data: {
      labels: ['N-6', 'N-5', 'N-4', 'N-3', 'N-2', 'N-1', 'N'],
      datasets: [
            {
               label: 'Temperature',
               backgroundColor: 'transparent',
               borderColor: "red",
               data: [10, 0, 10, 0, 10, 0, 10]
            },{
               label: 'Temperature',
               backgroundColor: 'transparent',
               borderColor: "pink",
               data: [0, 10, 0, 10, 0, 10, 0]
            }
      ]
   },
   options: {}
});

function graph(){
   chart.data.datasets[0].data.shift();
   chart.data.datasets[0].data.push(temp);
   chart.data.datasets[1].data.shift();
   chart.data.datasets[1].data.push(humi);
   //chart.data.labels.shift();
   chart.update();
}
function graph(input){
   chart.data.datasets[0].data.shift();
   chart.data.datasets[0].data.push(input);
   //chart.data.labels.shift();
   chart.update();
}
</script>
<button onClick="graph(10,20)">그래프값1 입력</button>
<button onClick="graph(20,10)">그래프값2 입력</button>
</body>
</html>

<?php
include 'footer.php';
?>
