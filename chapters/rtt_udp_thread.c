static void udp1_thread_entry(void* parameter)
{
	//限于篇幅，这部分代码仅给出大致框架，不列举全部内容;
	//变量定义、声明和初始化;
	//初始化WIFI模块配置;
	//尝试通过WIFI连接到路由器;
	//创建UDP连接到服务器;
	//更新当前命令;
    while (1)
    {
		pt[1]=butn_cmd;
		switch(butn_cmd)
		{
			case BUTN_CMD_REPORT_RQST:
				//向服务器报告系统状态;
			break;
			case BUTN_CMD_VOICE_RQST:
				//向服务器发出语音呼叫请求;
			break;
			case BUTN_CMD_VOICE_DATA:
				//向服务器发送本机采集到的语音数据流;
			break;
			case BUTN_CMD_CONFIG_RQST:
				//向服务器发出系统参数配置请求;
			break;
			case BUTN_CMD_CONFIG_RPLY:
				//向服务器恢复已经收到参数配置信息;
			break;
			case BUTN_CMD_SET_ALARM:
				//向服务器发出语音呼叫请求;
			break;
			case BUTN_CMD_NONE:
				//空命令;
			break;
			case BUTN_CMD_UDP_RQST://UDP打洞请求
				//向服务器发出UDP打洞请求（用于系统与服务器不在同一网段的情况）;
			break;
			case BUTN_CMD_SYS_RESET:
				//系统出错时进行复位;
			break;
		}
    }
}