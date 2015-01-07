private void myUdpClient_Load(object sender, EventArgs e)
{
	//程序启动时创建UDP接收线程
	thread1 = new Thread(new ThreadStart(ReceiveMessage));
	thread1.Start();
}

private void BtnSend_Click(object sender, EventArgs e)
{
	//单击按钮时创建UDP发送线程
	thread2 = new Thread(SendMessage);
	thread2.Start();
}