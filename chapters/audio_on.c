void audio_on()
{
	audio_input_init();//语音输入初始化
	audio_output_init();//语音输出初始化
	GPIO_SetBits(GPIOB,AUDIO_PA);//开启音频功放
}