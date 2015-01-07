	result = rt_thread_init(&udp1_thread,
                            "udp1",
                            udp1_thread_entry, RT_NULL,
                            (rt_uint8_t*)&udp1_stack[0], sizeof(udp1_stack), 10, 20);
	if (result == RT_EOK)
	{
        rt_thread_startup(&udp1_thread);
	}