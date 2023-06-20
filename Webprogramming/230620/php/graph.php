<!DOCTYPE html>
<html>
<head>
<title></title>
<script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.1.4/Chart.bundle.min.js"></script>

</head>
<body>
<div style="width:600px;">
<canvas id="line1"></canvas>
</div>


<script>
var ctx = document.getElementById('line1').getContext('2d');
var chart = new Chart(ctx, {
   type: 'line',
   data: {
      labels: <?php echo json_encode($mylabel); ?>,
      datasets: [
            {
               label: 'Temperature',
               backgroundColor: 'transparent',
               borderColor: "pink",
               data: <?php echo json_encode($mytemp); ?>
            },
            {
               label: 'humidity',
               backgroundColor: 'transparent',
               borderColor: "black",
               data: <?php echo json_encode($myhumi); ?>
            }
      ]
   },
   options: {}
});

function nockanda_forever(){
   var recv  = window.AppInventor.getWebViewString();
   chart.data.datasets[0].data.shift();
   chart.data.datasets[0].data.push(recv);
   //chart.data.labels.shift();
   chart.update();
}
</script>
</body>
</html>
