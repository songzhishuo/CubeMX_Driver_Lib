#include "AHT10.h"
/*
 * myiic.c
 *
 *  Created on: Sep 23, 2020
 *      Author: Argon
 */
void AHT10Init(void)
{
	uint8_t cmd_buffer[3] = {0};
	cmd_buffer[0] = 0xe1;
	cmd_buffer[1] = 0x08;
	cmd_buffer[2] = 0x00;

	HAL_I2C_Master_Transmit(&hi2c1, AHT10_ADDRESS, (uint8_t*)cmd_buffer, 3, 0xFFFF);
}

u8 AHT10Check(void)
{
	uint8_t cmd_buffer = 0xba;
	//HAL_I2C_Master_Transmit(&hi2c1, AHT10_ADDRESS, (uint8_t*), 0, 0xFFFF);
}

void AHT10Reset(void)
{
	uint8_t cmd_buffer[1];
	cmd_buffer[0] = 0xba;
	HAL_I2C_Master_Transmit(&hi2c1, AHT10_ADDRESS, (uint8_t*)cmd_buffer, 1, 0xFFFF);
}

u8 AHT10ReadData(float *temperature,float *humidity)
{
	uint8_t cmd_buffer[3] = {0};
	uint8_t dat_buffer[6] = {0};

	u32 h1 = 0 ,t1 = 0;
	cmd_buffer[0] = 0xac;
	cmd_buffer[1] = 0x33;
	cmd_buffer[2] = 0x00;

	int ret = HAL_I2C_Master_Transmit(&hi2c1, AHT10_WRITE, (uint8_t*)cmd_buffer, 3, 0xFFFF);
	HAL_Delay(80);

	printf("ret = %d %d\r\n",ret,HAL_ERROR);
	//HAL_I2C_Master_Receive(&hi2c1, AHT10_READ, dat, 1, 0xFFFF);
	HAL_I2C_Master_Receive(&hi2c1, AHT10_READ, dat_buffer, 6, 0xFFFF);
	printf("dat = %x\r\n",dat_buffer);
	if((dat_buffer[0]&0x68) == 0x08 )
	{
		//HAL_I2C_Master_Receive(&hi2c1, AHT10_READ, dat_buffer, 6, 0xFFFF);
		printf("[%d][%d][%d][%d][%d][%d]\r\n",dat_buffer[0],dat_buffer[1],dat_buffer[2],dat_buffer[3],dat_buffer[4],dat_buffer[5]);
		//HAL_I2C_Master_Receive(&hi2c1, AHT10_READ, (uint8_t*)dat_buffer, 5, 0xFFFF);
#if 0
		srh=(dat_buffer[0]<<12)+(dat_buffer[1]<<4)+(dat_buffer[2]>>4);
		stemp=((dat_buffer[2]&0x0f)<<16)+(dat_buffer[3]<<8)+(dat_buffer[4]);
		*humidity=(int)(srh*100.0/1024/1024+0.5);
		*temperature=((int)(stemp*2000.0/1024/1024+0.5))/10.0-50;
#endif
#if 0
		SRH=(dat_buffer[1]<<12)+(dat_buffer[2]<<4)+(dat_buffer[3]>>4);
		ST=((dat_buffer[3]&0X0f)<<16)+(dat_buffer[4]<<8)+(dat_buffer[5]);
		*humidity=(int)(SRH*100.0/1024/1024+0.5);
		*temperature=((int)(ST*2000.0/1024/1024+0.5))/10.0-50;
#endif
		h1 = dat_buffer[1];
		h1 = (h1<<8) | dat_buffer[2];
		h1 = (h1<<8) | dat_buffer[3];
		h1 = h1>>4;

		h1 = (h1*1000)/1024/1024;

		t1 = dat_buffer[3];
		t1 = t1 & 0x0000000F;
		t1 = (t1<<8) | dat_buffer[4];
		t1 = (t1<<8) | dat_buffer[5];

		t1 = (t1*2000)/1024/1024 - 500;
		//printf("温度:%d%d.%d",t1/100,(t1/10)%10,t1%10);
		//printf("湿度:%d%d.%d\r\n",h1/100,(h1/10)%10,h1%10);
		*temperature 	= (float)t1/10;
		*humidity		= (float)h1/10;
		return 0;
	}
	return 1;
}



