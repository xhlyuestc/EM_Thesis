void audio_off()
{
	GPIO_ResetBits(GPIOB,AUDIO_PA);//关闭音频功放
  	ADC_Cmd(ADC1, DISABLE);//关闭ADC1
  	ADC_DMACmd(ADC1, DISABLE);//关闭ADC1的DMA功能
	DMA_Cmd(DMA1_Channel1,DISABLE);//关闭DMA1第1通道
	DMA_Cmd(DMA2_Channel4,DISABLE);//关闭DMA2第4通道
	//DAC_Cmd(DAC_Channel_1,DISABLE);//关闭DAC第1通道
	DAC_Cmd(DAC_Channel_2,DISABLE);//关闭DAC第2通道
 	//DAC_DMACmd(DAC_Channel_1, DISABLE);//关闭DAC第1通道的DMA功能
 	DAC_DMACmd(DAC_Channel_2, DISABLE);//关闭DAC第2通道的DMA功能
	TIM_Cmd(TIM2,DISABLE);//关闭ADC触发时钟
	TIM_Cmd(TIM3,DISABLE);//关闭DAC触发时钟
}