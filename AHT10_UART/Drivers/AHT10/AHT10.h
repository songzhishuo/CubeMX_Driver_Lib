/*
 * myiic.h
 *
 *  Created on: Sep 23, 2020
 *      Author: Argon
 */

#ifndef IIC_AHT10_H_
#define IIC_AHT10_H_

#include "i2c.h"

#define AHT10_ADDRESS 0x70										///<器件地址
#define AHT10_WRITE 0x70
#define AHT10_READ 0x71

#define u8 uint8_t
#define u32 uint32_t
/*****************函数声明******************/
extern void AHT10Init(void);									///<传感器初始化
extern u8 AHT10Check(void);										///<等待 【未实现】
extern void AHT10Reset(void);									///<重新连接传感器
extern u8 AHT10ReadData(float *temperature,float *humidity);	///<读取温湿度数据

#endif /* IIC_AHT10_H_ */
