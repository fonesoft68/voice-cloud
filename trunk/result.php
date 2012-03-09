<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
<html xmlns="http://www.w3.org/1999/xhtml"> 
<head> 
<title>用户上传文件列表</title> 
</head>
<body>
<?php 
	echo "<p>任务执行完毕，结果如下</p>";
	$dir=$_SERVER['DOCUMENT_ROOT'] . "/TaskResult/"."FinalResult/";
	session_start();
	$filename_result=$dir.$_SESSION["filename"].'_result.txt';
	if (!$handle = fopen ($filename_result,"r"))
	{
		echo "can not open $filename_result";
		exit;
	};
	echo "<p>任务执行成功信息：</p>";
	while (!feof($handle))
	{
		$file = fgets($handle,1024);
		if (strlen($file)!= 0)
		{
			echo "<p>$file</p>";
		}
	}
	fclose($handle);
	
	$filename_result_fail=$dir.$_SESSION["filename"].'_result_fail.txt';
	if (!$handle = fopen ($filename_result_fail,"r"))
	{
		echo "can not open $filename_result_fail";
		exit;
	};
	echo "<p>任务执行失败信息：</p>";
	$i=0;
	while (!feof($handle))
	{
		$file = fgets($handle,1024);
		$i++;
		if (strlen($file)!= 0)
		{
			echo "<p>$file</p>";
		}
	}
	if ($i!=0) {
		echo"<p>无</p>";
	}
	fclose($handle);
	
	
?>
</body>
</html>
