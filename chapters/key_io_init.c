void key_io_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;	
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);
    //以下为按键输入引脚，用于判断外部事件
    GPIO_InitStructure.GPIO_Pin = OPEN_KEY|ALARM_KEY;//OPEN_KEY:PB11 & ALARM_KEY:PB10
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource10);
}