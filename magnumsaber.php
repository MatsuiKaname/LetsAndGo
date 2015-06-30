<?php
  ini_set('display_errors', 1);
  error_reporting(E_ALL);
  define("MAGNUMSABER", "sudo /home/pi/magnumsaber");
  define("ADDERSS", "192.168.11.57");
  define("USER", "pi");
  define("PASSWORD", "Knm7749");

  if(!is_null($_GET["num"]) && !is_null($_GET["stat"])){
    //echo "ffff";
  	/* SSH2 module processes */
  	$sconnection = ssh2_connect(ADDERSS, 22);
  	ssh2_auth_password($sconnection, USER, PASSWORD);
  	/* execution command */

  	$command = MAGNUMSABER." ".$_GET["num"]." ".$_GET["stat"];
  	$stdio_stream = ssh2_exec($sconnection, $command);
  }
?>