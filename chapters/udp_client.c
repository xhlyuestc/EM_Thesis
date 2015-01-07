public partial class myUdpClient : Form
{
	//创建一个Thread实例
	private Thread thread1;
	private Thread thread2;
	//创建一个UdpClient实例
	private UdpClient udpReceive;
	private byte[] receive_bytes;
	private byte[] send_bytes;
	int trys;
	//private DialogResult result;

	public myUdpClient()
	{
		int i;
		InitializeComponent();
		CheckForIllegalCrossThreadCalls = false;
		comboBox2.SelectedIndex = 0;
		comboBox3.SelectedIndex = 0;
		udpReceive = new UdpClient(60000);//新建UDP连接，端口60000
		thread1 = new Thread(new ThreadStart(ReceiveMessage));
		thread1.Start();//新建并启动UDP接收线程
		button1.Text = "停止监听";
		send_bytes = null;
		comboBox1.Text = "没有待配置设备";
		comboBox4.SelectedIndex = 0;
		comboBox5.SelectedIndex = 0 ;
	}
}