<?php
$url = "https://api.sky31.com/edu_idcode.php?role=201705550820&hash=1eaf6f7b7dfd4b2937949acbaeed0e39";
$debug_url = "https://debug.sky31.com/edu_idcode.php?role=201705550820&hash=1eaf6f7b7dfd4b2937949acbaeed0e39";
$couser_url = "https://api.sky31.com/edu-new/grade_details.php?role=201705550820&hash=1eaf6f7b7dfd4b2937949acbaeed0e39&sid=201705550820&password=qq1246009411";
$img = "/home/dhd/personal/Web/idcode/verifycode.jpeg";
// $fp = fopen( $img, "rb", 0 );
// $img = fread( $fp, filesize($img) );
// fclose( $fp );
// $base64=base64_encode( $img );
// $data = array("data"=>$base64);
$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $couser_url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($ch, CURLOPT_HEADER, 0);
// curl_setopt($ch, CURLOPT_POST, 1);
// curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
$response = curl_exec($ch);//接收返回信息
echo $response;//显示返回信息
$response = curl_exec($ch);//接收返回信息
echo $response;//显示返回信息
curl_close($ch); //关闭curl链接
