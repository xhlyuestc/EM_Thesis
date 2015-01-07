private void button1_Click(object sender, EventArgs e)
{
	if (button1.Text == "开始监听")
	{
		udpReceive = new UdpClient(60000);
		thread1 = new Thread(new ThreadStart(ReceiveMessage));
		thread1.Start();
		button1.Text = "停止监听";
	}
	else if (button1.Text == "停止监听")
	{
		//关闭UDP连接
		udpReceive.Close();
		//终止UDP接收线程
		thread1.Abort();
		button1.Text = "开始监听";
	}
}