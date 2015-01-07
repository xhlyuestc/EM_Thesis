void key_nvic_init(void)
{
 	NVIC_InitTypeDef NVIC_InitStructure;
  	//使能按键所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
  	//先占优先级4位,共16级
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
  	//先占优先级0位,从优先级4位
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
  	//使能外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	
  	NVIC_Init(&NVIC_InitStructure);
}
