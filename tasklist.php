<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
<html xmlns="http://www.w3.org/1999/xhtml"> 
<head> 
<title>�û��ϴ��ļ��б�</title> 
</head>
<body>
<?php 
/*  
 ���û��ύ��������Ϣ����һ��tasklist
 */
	echo "�������ڴ����У����Ժ򡭡�";
	$temp =$_SERVER['DOCUMENT_ROOT'] . "/TaskList/" . $_SERVER["REMOTE_ADDR"] .'_'. date("Ymd_His").'_';
	$msg=$_SERVER["REMOTE_ADDR"] .'_'. date("Ymd_His").'_';
	$filename_r = $_SERVER['DOCUMENT_ROOT'] . "/UploadedInfo/" . $_SERVER["REMOTE_ADDR"] .'_'.date("Ymd"). ".txt";
	$ch = $_POST["ch"];
	if(!empty($ch))
	{
		//����Ϣ����
		$message_queue_key = ftok(".", 'a');
		
		$message_queue = msg_get_queue($message_queue_key, 0777);
		//echo $message_queue;
		//����task���ͽ�����Ӧ��tasklist�ļ�,ע�⣺�û�һ��ֻ��ѡһ��������������
		switch ($ch[0])
		{
			case "����":
				$buf = '0';
				break;
			case "ͬԴ����":
				$buf = '1';
				break;
			case "��з���":
				$buf = '2';
				break;
			case "���Ʒ���":
				$buf = '3';
				break;
			case "�ؼ��ʼ���":
				$buf = '4';
				break;
		}	
		$filename_w=$temp.$buf.".txt";
		if (copy($filename_r,$filename_w)==FALSE)
			echo "Creating tasklist failed.";
		if (!msg_send ($message_queue, 1, $msg.$buf, true, true, $msg_err))
			echo "Msg not sent because $msg_err\n";
		unlink($filename_r);
		
		//���¿�һ����Ϣ���У���ֹ����php���ܴ������Ϣ
		$message_queue_key=ftok($filename_w,'a');
		$message_queue = msg_get_queue($message_queue_key, 0777);
		
		if (msg_receive ($message_queue, 2, $msg_type, 1024, $msg_result, true, 0, $msg_error))
		{
			
		} else
		{
			echo "Received $msg_error fetching message\n";
		}
		msg_remove_queue($message_queue);
		session_start();
		$_SESSION["filename"]=$msg.$buf;
		header("Location: result.php");
		
	}else
	{
		echo "Please choose a task type";
	}
	
?>
</body>
</html>
