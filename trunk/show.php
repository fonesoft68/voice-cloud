<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
<html xmlns="http://www.w3.org/1999/xhtml"> 
<head> 
<title>用户上传文件列表</title> 
</head>
<body>
<table border = 1 >	
	<tr>
		<th>序号</th>
		<th>文件名</th>
	</tr>
	<?php 
		/*  显示上传的文件列表   */
		$filename =$_SERVER['DOCUMENT_ROOT'] . "/UploadedInfo/" . $_SERVER["REMOTE_ADDR"] .'_'.date("Ymd"). ".txt";
		if (!$handle = fopen ($filename,"r"))
		{
				echo "can not open $filename";
				exit;
		};
		$i = 0;
		while (!feof($handle))
		{
			$file = fgets($handle,1024);
			$i++;
			if (strlen($file)!= 0)
			{
				echo "<tr><td>$i</td><td>$file</td></tr>";
			}
		}
		fclose($handle);
		//unlink($filename);
	?>
</table>
<p>请选择任务类型：</p>
<form method="post" action="tasklist.php" name="form1"> 
	<input type="checkbox" name="ch[]" value="测试">测试<br> 
	<input type="checkbox" name="ch[]" value=“同源分析">同源分析<br> 
	<input type="checkbox" name="ch[]" value="情感分析">情感分析<br> 
	<input type="checkbox" name="ch[]" value="声纹分析">声纹分析<br>
	<input type="checkbox" name="ch[]" value="关键词检索">关键词检索<br> 
	<input type="submit" value="提交任务"> </form> 
</body>
</html>
