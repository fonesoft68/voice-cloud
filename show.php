<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
<html xmlns="http://www.w3.org/1999/xhtml"> 
<head> 
<title>�û��ϴ��ļ��б�</title> 
</head>
<body>
<table border = 1 >	
	<tr>
		<th>���</th>
		<th>�ļ���</th>
	</tr>
	<?php 
		/*  ��ʾ�ϴ����ļ��б�   */
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
<p>��ѡ���������ͣ�</p>
<form method="post" action="tasklist.php" name="form1"> 
	<input type="checkbox" name="ch[]" value="����">����<br> 
	<input type="checkbox" name="ch[]" value=��ͬԴ����">ͬԴ����<br> 
	<input type="checkbox" name="ch[]" value="��з���">��з���<br> 
	<input type="checkbox" name="ch[]" value="���Ʒ���">���Ʒ���<br>
	<input type="checkbox" name="ch[]" value="�ؼ��ʼ���">�ؼ��ʼ���<br> 
	<input type="submit" value="�ύ����"> </form> 
</body>
</html>
