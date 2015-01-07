void EXTI15_10_IRQHandler(void)
{
	u8 event;
    /* enter interrupt */
    rt_interrupt_enter();//RT-Thread中断嵌套
	if(SET == EXTI_GetITStatus(EXTI_Line10)//OPEN_KEY &
	 ||SET == EXTI_GetITStatus(EXTI_Line11))// ALARM_KEY
	{
		event=get_key_event();
		if(event == EVENT_ALARM)//语音呼叫请求
			butn_cmd=BUTN_CMD_VOICE_RQST;
		else if(event == EVENT_OPEN)//防破坏拆除报警
			butn_cmd=BUTN_CMD_SET_ALARM;
		if(server_mode==SERVER_MODE_NAT)//打洞服务器
		{
			butn_cmd=BUTN_CMD_UDP_RQST;//先打洞
			next_cmd=butn_cmd;//后连接目标服务器
		}
		EXTI_ClearITPendingBit(EXTI_Line11|EXTI_Line10);
	}
    /* leave interrupt */
    rt_interrupt_leave();//RT-Thread中断嵌套
}
