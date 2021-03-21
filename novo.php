<?php

//**** Teste 01

  $servername = "localhost";
  $dbname = "*************"; // Nome do banco de dados
  $username = "***********"; // Nome do usuario
  $password = "***********"; // Senah do banco de dados

$conn = new mysqli($servername, $username, $password, $dbname);

$status = filter_input(INPUT_POST,'status');
$outros=0;// controle GPIO

$saida ="UPDATE teste SET status=$status, outros=$outros WHERE id=1";
$result_saida = mysqli_query($conn,$saida);
$result_saida2 = mysqli_query($conn, "SELECT * FROM teste") or die("Erro");


    while($dado = $result_saida2->fetch_array()){
        $x = $dado["status"];
        $y = $dado["outros"];
    }

$dado = array('status' => $x,'outros' =>$y); // A parte mais importante do programa 
echo json_encode($dado);

mysqli_close($conn);

echo "<script>window.location.href='http://helloesp.cf/inicial.php'</script>";
?>