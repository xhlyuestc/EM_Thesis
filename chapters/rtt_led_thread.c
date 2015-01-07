static void led_thread_entry(void* parameter)
{
	rt_uint32_t led_mode=*((rt_uint32_t)parameter);
    rt_hw_led_init();//LED对应IO初始化
	//限于篇幅，以下仅给出主要逻辑框架，不列举完整代码
    while (1)
    {
        switch(led_mode)
		{
			case LED_MODE_BOTH_ON:
				//红色LED亮;绿色LED亮;
			break;
			case LED_MODE_BOTH_OFF:
				//红色LED灭;绿色LED灭;
			break;
			case LED_MODE_RED_ON:
				//红色LED亮;绿色LED灭;
			break;
			case LED_MODE_GREEN_ON:
				//红色LED灭;绿色LED亮;
			break;
			case LED_MODE_RED_TOGGLE:
				//红色LED取反;绿色LED灭;
			break;
			case LED_MODE_GREEN_TOGGLE:
				//红色LED灭;绿色LED取反;
			break;
			case LED_MODE_BOTH_TOGGLE:
				//红色LED取反;绿色LED取反;
			break;
		}
		rt_thread_delay( RT_TICK_PER_SECOND/2 );
    }
}