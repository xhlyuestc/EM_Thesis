void audio_input_init(void)
{
  	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  	ADC_InitTypeDef ADC_InitStructure;
  	DMA_InitTypeDef DMA_InitStructure;
  	
  	/* Enable peripheral clocks */
  	/* Enable DMA clock */
  	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);  
  	/* Enable ADC1 and GPIOA clock */
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA, ENABLE);
  	RCC_ADCCLKConfig(RCC_PCLK2_Div8);//72M/8=9M,ADCCLK最大不超过14M

  	/* GPIO configuration */
  	//配置IO为模拟输入模式;
	/* Time base configuration */
  	//通过配置TIM时间基准来配置ADC采样率为8 KSPS;
  	//配置DMA1_CH1 NVIC优先级;
  	/* DMA channel1 configuration */
  	//DMA传输相关配置;
  	/* Enable DMA channel1 */
  	DMA_Cmd(DMA1_Channel1, ENABLE);     
  	/* ADC1 configuration */
  	//ADC相关配置：时钟、转换时间、分辨率、数据对齐方式等;
	//使能定时器、ADC和DMA
}