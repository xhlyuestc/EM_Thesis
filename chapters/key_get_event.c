u8 key_get_event()
{
	u32 open,alarm;
	open=GPIO_ReadInputDataBit(GPIOB,OPEN_KEY);
	alarm=GPIO_ReadInputDataBit(GPIOB,ALARM_KEY);
	if(!open)
		return EVENT_ALARM;//语音呼叫按键被按下
	else if(!alarm)
		return EVENT_OPEN;//硬件放破坏拆除按键被断开
	else//以上两种情况都不是，
		return EVENT_TIMER;//那么肯定是被定时唤醒的
}
