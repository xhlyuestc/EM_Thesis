int rt_application_init()
{
	rt_thread_t init_thread;
	rt_err_t    result;

    /* init led thread */
	result = rt_thread_init(&led_thread,
                            "led",
                            led_thread_entry, RT_NULL,
                            (rt_uint8_t*)&led_stack[0], sizeof(led_stack), 30, 1);
	if (result == RT_EOK)
	{
        rt_thread_startup(&led_thread);
	}
	/*创建一个用于初始化其他线程的线程"init"*/	
	init_thread = rt_thread_create("init",
                                   rt_init_thread_entry, RT_NULL,
                                   2048, 8, 20);

	if (init_thread != RT_NULL)
		rt_thread_startup(init_thread);

	return 0;	
}