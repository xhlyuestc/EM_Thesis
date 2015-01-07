void audio_output_init(void)
{
  	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;
    DAC_InitTypeDef	DAC_InitStructure;

	//使能相关外设的时钟：GPIO/TIM/DAC/DMA;
	//配置音频输出对应IO引脚为模拟输出模式;
  	//通过配置TIM配置DAC的转换速率为8 KSPS;
	//DAC初始化：转换时间、分辨率、数据对齐方式等;	  
  	//配置DMA2_CH4 NVIC中断优先级;
  	//为DAC配置DMA传输条件：源地址、目的地址、位宽等;
	//使能TIM、DAC、DMA;
}