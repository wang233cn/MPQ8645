#include "I2C.h"
#include "Delay.h"

 

//设置输出高低电平模式
#define SDA_OUT(X)   if(X) \
					 HAL_GPIO_WritePin(SDA_GPIO_Port, SDA_Pin, GPIO_PIN_SET); \
				     else  \
					 HAL_GPIO_WritePin(SDA_GPIO_Port, SDA_Pin, GPIO_PIN_RESET);
 
#define SCL_OUT(X)   if(X) \
					 HAL_GPIO_WritePin(SCL_GPIO_Port, SCL_Pin, GPIO_PIN_SET); \
				     else  \
					 HAL_GPIO_WritePin(SCL_GPIO_Port, SCL_Pin, GPIO_PIN_RESET);    
                                     
#define SDA_IN		 HAL_GPIO_ReadPin(SDA_GPIO_Port,SDA_Pin)  
 
 
 
//
void I2C_Start(void)
{
	SDA_OUT(1);
	SCL_OUT(1) ;
	SDA_OUT(0);
	SCL_OUT(0) ;
}
//IIC停止信号
void I2C_Stop(void)
{
	SDA_OUT(0);
	SCL_OUT(1);
	SDA_OUT(1);
}

void I2C_Ack(void)        //产生应答信号
{
	SCL_OUT(0);
	SDA_OUT(0);

	Delay_us(1);
	SCL_OUT(1);             //确保SCL为高时SDA为低

	Delay_us(1);
	SCL_OUT(0);
	SDA_OUT(1);
}

void I2C_NAck()     //不产生应答信号
{
	SCL_OUT(0);
	SDA_OUT(1);

	Delay_us(1);
	SCL_OUT(1);             //SCL高时SDA高

	Delay_us(1);
	SCL_OUT(0);
}

//
uint8_t I2C_Wait_Ack(void)
{	

	SDA_OUT(1);
	//delay
	SCL_OUT(0);
	//delay

	SCL_OUT(1);
	//I2C_delay();
	uint8_t ack_status=SDA_IN;
	SCL_OUT(0);
	//I2C_delay();
 
	return ack_status;
}

//
void I2C_Send8(uint8_t data)//主机发送8位数据给从机MSB 高位先发
{
//    uint8_t i = 0;
	SCL_OUT(0);
	for(int i=0;i<8;i++)
	{	
		if(data & 0x80)
			SDA_OUT(1)
		else
			SDA_OUT(0);
		SCL_OUT(1);//拉高时钟线，告诉对方你可以读了	
//		Delay_us(5);
		SCL_OUT(0);//拉低时钟线，告诉对方你暂时别读，我在准备数据
		data <<= 1;
//		Delay_us(5);
	}

}

//
uint8_t I2C_Read8(void)
{
	uint8_t data=0;
	SCL_OUT(0);
	for(int i=0;i<8;i++)
	{
		data<<=1;
		SCL_OUT(1);
//		I2C_delay();
//		Delay_us(5);
		if(SDA_IN) data|=0x01;
		SCL_OUT(0);
//		I2C_delay();
//				Delay_us(5);
	
	}
	return data;
}

I2C_StatusTypeDef I2C_Read(uint8_t DEVaddr,uint8_t REGaddr,uint8_t *dataRead,uint16_t LENGTH)
{
//	 uint8_t data;
	 I2C_Start();
	//先写入器件写地址
	 I2C_Send8((DEVaddr<<1));
	 if(I2C_Wait_Ack()) return I2C_BUSY;
	 //再写入要读取的寄存器地址
	 I2C_Send8(REGaddr);
	 if(I2C_Wait_Ack()) return I2C_ERROR;
	 I2C_Start();
	 //发送器件读地址
	 I2C_Send8((DEVaddr<<1)|0x01);
	 if(I2C_Wait_Ack()) return I2C_BUSY;
	 
	//读取相应寄存器
	 for(int i = 0;i<LENGTH;i++){
		 dataRead[i] = I2C_Read8();
		 if(i!=(LENGTH-1))        //最后一个字节要发送非应答信号		
		 	I2C_Ack();	
	   else		
			I2C_NAck();	
	}
	 I2C_Stop();
	return I2C_OK;
}

I2C_StatusTypeDef I2C_Write(uint8_t DEVaddr,uint8_t REGaddr,uint8_t *dataWrite,uint16_t LENGTH)
{
	 I2C_Start();
	//先写入器件写地址
	 I2C_Send8(DEVaddr<<1);
	 if(I2C_Wait_Ack()) return I2C_BUSY;
	 //再写入要读取的寄存器地址
	 I2C_Send8(REGaddr);
	 if(I2C_Wait_Ack()) return I2C_ERROR;
	//写取相应寄存器
	 for(int i = 0;i<LENGTH;i++){
		 I2C_Send8(dataWrite[i]);
     if(I2C_Wait_Ack()) return I2C_ERROR;
	}
	 I2C_Stop();
	return I2C_OK;
}


 