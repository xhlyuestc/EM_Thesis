void wifi_init()
{
	wifi_power_on();//使能WIFI模块
    timerbase_config();//SDIO接口时基配置
    sysflag.status=on_connect;
	sysflag.waittime=160;
    load_netcfg();//加载网络参数配置信息
	mem_init();//LWIP内存初始化
	//初始化marvell模块驱动,包括SDIO设备枚举，加载设备固件等操作
	priv = init_marvell_driver();
	//扫描wifi网，结果存放在priv->network数据域中，使用bss_descriptor结构体描述
	lbs_scan_worker(priv);
	//rt_kprintf("scanning finish...\r\n");
	psk_out = mem_malloc(32);//为结构体申请内存
	marvel_assoc_network(priv,marvel_ssid,marvel_key,marvel_mode);//关联WIFI网络
	mem_free(psk_out);//释放内存
}