<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
<html xmlns="http://www.w3.org/1999/xhtml"> 
<head> 
<title>用户上传文件列表</title> 
</head>
<body>
<?php 
/*  
 将用户提交的任务信息生成一个tasklist
 */
	echo "任务正在处理中，请稍候……";
	$temp =$_SERVER['DOCUMENT_ROOT'] . "/TaskList/" . $_SERVER["REMOTE_ADDR"] .'_'. date("Ymd_His").'_';
	$msg=$_SERVER["REMOTE_ADDR"] .'_'. date("Ymd_His").'_';
	$filename_r = $_SERVER['DOCUMENT_ROOT'] . "/UploadedInfo/" . $_SERVER["REMOTE_ADDR"] .'_'.date("Ymd"). ".txt";
	$ch = $_POST["ch"];
	if(!empty($ch))
	{
		//打开消息队列
		$message_queue_key = ftok(".", 'a');
		
		$message_queue = msg_get_queue($message_queue_key, 0777);
		//echo $message_queue;
		//根据task类型建立相应的tasklist文件,注意：用户一次只能选一个任务任务类型
		switch ($ch[0])
		{
			case "测试":
				$buf = '0';
				break;
			case "同源分析":
				$buf = '1';
				break;
			case "情感分析":
				$buf = '2';
				break;
			case "声纹分析":
				$buf = '3';
				break;
			case "关键词检索":
				$buf = '4';
				break;
		}	
		$filename_w=$temp.$buf.".txt";
		if (copy($filename_r,$filename_w)==FALSE)
			echo "Creating tasklist failed.";
		if (!msg_send ($message_queue, 1, $msg.$buf, true, true, $msg_err))
			echo "Msg not sent because $msg_err\n";
		unlink($filename_r);
		
		//重新开一个消息队列，防止出现php接受错误的消息
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
