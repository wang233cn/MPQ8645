#include "I2C.h"
#include "MPQ8645.h"


//CMD
void MPQ8645_CLEAR_FAULTS(void){
	uint8_t dataWrite;
	I2C_Write(MPQ8645_ADDR,CLEAR_FAULTS,&dataWrite,0);
}
//CMD
void MPQ8645_WriteProtect(){
}

//CMD
void MPQ8645_STORE_USER_ALL(void){
}
//CMD
void MPQ8645_RESTORE_USER_ALL(void){
}


//设置输出电压，单位mV
void MPQ8645_VOUT_COMMAND(uint16_t Vout){
	uint8_t dataWriteArray[2] = {Vout/2,((Vout/2)>>8)&0xF};
	I2C_Write(MPQ8645_ADDR,VOUT_COMMAND,dataWriteArray,2);
}

//If an attempt is made to program the output voltage higher than the limit set by this command, the 
//device responds as follows: 
// The commanded output voltage is set to VOUT_MAX. 
// The NONE OF THE ABOVE bit is set in STATUS_BYTE. 
// The VOUT bit is set in STATUS_WORD. 
// The VOUT_MAX_MIN warning bit is set in the STATUS_VOUT register. 
// The device notifies the host.

//设定最大输出电压
void MPQ8645_VOUT_MAX(uint16_t Vout){
	uint8_t dataWriteArray[2] = {Vout/2,((Vout/2)>>8)&0xF};
	I2C_Write(MPQ8645_ADDR,VOUT_MAX,dataWriteArray,2);
}


void MPQ8645_VOUT_MARGIN_HIGH(uint16_t Vout){
	uint8_t dataWriteArray[2] = {Vout/2,((Vout/2)>>8)&0xF};
	I2C_Write(MPQ8645_ADDR,VOUT_MARGIN_HIGH,dataWriteArray,2);
}

void MPQ8645_VOUT_MARGIN_LOW(uint16_t Vout){
	uint8_t dataWriteArray[2] = {Vout/2,((Vout/2)>>8)&0xF};
	I2C_Write(MPQ8645_ADDR,VOUT_MARGIN_LOW,dataWriteArray,2);
}

//设定反馈电阻比例 
void MPQ8645_VOUT_SCALE_LOOP(float FBRatio){
	uint16_t dataWrite = FBRatio/0.001;
	dataWrite &= 0xFFF;
	uint8_t dataWriteArray[2] = {dataWrite,(dataWrite>>8)&0xF};
	I2C_Write(MPQ8645_ADDR,VOUT_SCALE_LOOP,dataWriteArray,2);
}

//设定最小输出电压，单位：mV
void MPQ8645_VOUT_MIN(uint16_t Vout){
	uint8_t dataWriteArray[2] = {Vout/2,((Vout/2)>>8)&0xF};
	I2C_Write(MPQ8645_ADDR,VOUT_MIN,dataWriteArray,2);
}   

//设定输入启动电压，单位：mV
void MPQ8645_VIN_ON(uint16_t Vin){
	uint8_t dataWriteArray[2] = {Vin/250,((Vin/250)>>8)&0xF};
	I2C_Write(MPQ8645_ADDR,VIN_ON,dataWriteArray,2);
}

//设定输入下限电压，单位：mV
void MPQ8645_VIN_OFF(uint16_t Vin){
	uint8_t dataWriteArray[2] = {Vin/250,((Vin/250)>>8)&0xF};
	I2C_Write(MPQ8645_ADDR,VIN_OFF,dataWriteArray,2);
}

//设定输出电流错误阈值，单位：mA
void MPQ8645_IOUT_OC_FAULT_LIMIT(uint16_t Iout){
	uint16_t dataWrite = Iout/242;
	dataWrite &= 0xFFF;
	uint8_t dataWriteArray[2] = {dataWrite,dataWrite>>8};
	I2C_Write(MPQ8645_ADDR,IOUT_OC_FAULT_LIMIT,dataWriteArray,2);
}

//设定输出电流警告阈值，单位：mA
void MPQ8645_IOUT_OC_WARN_LIMIT(uint16_t Iout){
	uint16_t dataWrite = Iout/242;
	dataWrite &= 0xFFF;
  uint8_t dataWriteArray[2] = {dataWrite,dataWrite>>8};
	I2C_Write(MPQ8645_ADDR,IOUT_OC_WARN_LIMIT,dataWriteArray,2);
}



//设定温度错误阈值，单位：摄氏度
void MPQ8645_OT_FAULT_LIMIT(uint16_t Temp){
	Temp &= 0xFFF;
	uint8_t dataWriteArray[2] = {Temp,Temp>>8};
	I2C_Write(MPQ8645_ADDR,OT_FAULT_LIMIT,dataWriteArray,2);
}

//设定温度警告阈值，单位：摄氏度
void MPQ8645_OT_WARN_LIMIT(uint16_t Temp){
	Temp &= 0xFFF;
	uint8_t dataWriteArray[2] = {Temp,Temp>>8};
	I2C_Write(MPQ8645_ADDR,OT_WARN_LIMIT,dataWriteArray,2);
}

//输入过压错误阈值
void MPQ8645_VIN_OV_FAULT_LIMIT(uint16_t Vin){
	uint16_t dataWrite = Vin/500;
	dataWrite &= 0xFFF;
	uint8_t dataWriteArray[2] = {dataWrite,dataWrite>>8};
	I2C_Write(MPQ8645_ADDR,VIN_OV_FAULT_LIMIT,dataWriteArray,2);
}

//输入过压警告阈值
void MPQ8645_VIN_OV_WARN_LIMIT(uint16_t Vin){
	uint16_t dataWrite = Vin/500;
	dataWrite &= 0xFFF;
	uint8_t dataWriteArray[2] = {dataWrite,dataWrite>>8};
	I2C_Write(MPQ8645_ADDR,VIN_OV_WARN_LIMIT,dataWriteArray,2);
}

//设定输入欠压警告阈值
void MPQ8645_VIN_UV_WARN_LIMIT(uint16_t Vin){
	uint16_t dataWrite = Vin/250;
	dataWrite &= 0xFFF;
	uint8_t dataWriteArray[2] = {dataWrite,dataWrite>>8};
	I2C_Write(MPQ8645_ADDR,VIN_UV_WARN_LIMIT,dataWriteArray,2);
}

//设定启动延时
void MPQ8645_TON_DELAY(uint16_t ms){
	uint16_t dataWrite = ms/4;
	dataWrite &= 0x7FF;
	uint8_t dataWriteArray[2] = {dataWrite,dataWrite>>8};
	I2C_Write(MPQ8645_ADDR,TON_DELAY,dataWriteArray,2);
}

//设置软启动时间1，2，4，8，16ms
void MPQ8645_TON_RISE(uint16_t ms){
	uint16_t dataWrite;
	if(ms == 1){
		dataWrite = 0x00;
	}else if(ms == 2){
		dataWrite = 0x01;
	}else if(ms == 4){
		dataWrite = 0x02;
	}else if(ms == 8){
		dataWrite = 0x03;
	}else if(ms == 16){
		dataWrite = 0x04;
	}
	dataWrite &= 0x7FF;
	uint8_t dataWriteArray[2] = {dataWrite,dataWrite>>8};
	I2C_Write(MPQ8645_ADDR,TON_RISE,dataWriteArray,2);
}





int16_t MPQ8645_GetTEMP(void){
	uint8_t tempdata[2];
	uint16_t temp;
	I2C_Read(MPQ8645_ADDR,READ_TEMPERATURE,tempdata,2);
	temp = ((tempdata[1]<<8)&0xF)|tempdata[0];
	return temp;
}


float MPQ8645_GetVout(void){
	uint8_t Voutdata[2];
	float Vout;
	I2C_Read(MPQ8645_ADDR,READ_VOUT,Voutdata,2);
	Vout = (((Voutdata[1]<<8)|Voutdata[0])&0x1FFF)*0.00125;
	return Vout;
}
float MPQ8645_GetVin(void){
	uint8_t dataarray[2];
	float dataout;
	I2C_Read(MPQ8645_ADDR,READ_VIN,dataarray,2);
	dataout = (((dataarray[1]<<8)|dataarray[0])&0x3FF)*0.025;
	return dataout;
}

float MPQ8645_GetIout(void){
	uint8_t dataarray[2];
	float dataout;
	I2C_Read(MPQ8645_ADDR,READ_IOUT,dataarray,2);
	dataout = (((dataarray[1]<<8)|dataarray[0])&0x3FFF)*0.0625;
	return dataout;
}

//设定启动延时
//Cf 0 : 20pf, 1 : 50pf
//RAMP
//0: Slave-phase fault detection is enabled 
//1: Slave-phase fault detection is disabled
void MPQ8645_MFR_CTRL_COMP(uint8_t Cff,float RAMP,uint8_t slave_fault_detection){
	uint8_t dataWrite = 0x00;
	dataWrite|= Cff<<4;
	
  if(RAMP == 8.6 && RAMP == 5.6){
		dataWrite|= 0x00;
	}else if(RAMP == 9.8 && RAMP == 15){
		dataWrite|= 0x02;
	}else if(RAMP == 18 && RAMP == 27){
		dataWrite|= 0x04;
	}else if(RAMP == 30 && RAMP == 45){
		dataWrite|= 0x06;
	}else if(RAMP == 8.5 && RAMP == 13){
		dataWrite|= 0x08;
	}else if(RAMP == 15.1 && RAMP == 23){
		dataWrite|= 0x0A;
	}else if(RAMP == 27 && RAMP == 41){
		dataWrite|= 0x0C;
	}else if(RAMP == 44 && RAMP == 68){
		dataWrite|= 0x0E;
	}
	
	dataWrite|= slave_fault_detection;
	dataWrite &= 0x1F;
	I2C_Write(MPQ8645_ADDR,MFR_CTRL_COMP,&dataWrite,1);
}


//设定分压网络
void MPQ8645_MFR_CTRL_VOUT(uint8_t discharge,uint8_t PG_delay,uint8_t VO_RANGE){
	uint8_t dataWrite = 0x00;
	dataWrite |= discharge <<6;
	dataWrite |= PG_delay <<2;
	dataWrite |= VO_RANGE;
	dataWrite &= 0x7F;
	I2C_Write(MPQ8645_ADDR,MFR_CTRL_VOUT,&dataWrite,1);
}
//
void MPQ8645_MFR_CTRL_OPS(uint16_t SWITCHING_FREQUENCY,uint8_t SKIP_CCM){
	uint8_t dataWrite = 0x00;
	if(SWITCHING_FREQUENCY == 400){
		dataWrite|= 0x00;
	}else if(SWITCHING_FREQUENCY == 600){
		dataWrite|= 0x02;
	}else if(SWITCHING_FREQUENCY == 800){
		dataWrite|= 0x04;
	}else if(SWITCHING_FREQUENCY == 1000){
		dataWrite|= 0x06;
	}

	dataWrite |= SKIP_CCM;
	dataWrite &= 0x7F;
	I2C_Write(MPQ8645_ADDR,MFR_CTRL_OPS,&dataWrite,1);
}


void MPQ8645_MFR_ADDR_PMBUS(void){
}

void MPQ8645_MFR_VOUT_OVP_FAULT_LIMIT(void){
}

void MPQ8645_MFR_OVP_NOCP_SET(void){
}

void MPQ8645_MFR_OT_OC_SET(void){
}


void MPQ8645_MFR_OC_PHASE_SET(void){
	
}
//void MPQ8645_MFR_OT_OC_SET(void){
//}
//void MPQ8645_MFR_OT_OC_SET(void){
//}
//void MPQ8645_MFR_VOUT_STEP(void){
//}
//void MPQ8645_MFR_LOW_POWER(void){
//}

void MPQ8645_MFR_CTRL(uint8_t total_oc_hiccup_interval,uint8_t osm,uint8_t phase_operation){
	uint16_t dataWrite = 0x0000;
	
	dataWrite |= (total_oc_hiccup_interval<<10);
	dataWrite |= (osm<<9);
	dataWrite |= (phase_operation<<3);
	uint8_t dataWriteArray[2] = {dataWrite,dataWrite>>8};
	I2C_Write(MPQ8645_ADDR,TON_RISE,dataWriteArray,2);
}

void MPQ8645_GetValue(MPQ8645_ValueTypeDef *Get_Value){
	Get_Value->Vin = MPQ8645_GetVin();
	Get_Value->Temp = MPQ8645_GetTEMP();
	Get_Value->Vout = MPQ8645_GetVout();
	Get_Value->Iout = MPQ8645_GetIout();
}

void MPQ8645_GetStatus(MPQ8645_StatusTypeDef *GetStatus){
	uint8_t STATUS_BYTE_data;
	I2C_Read(MPQ8645_ADDR,STATUS_BYTE,&STATUS_BYTE_data,1);
	uint8_t STATUS_VOUT_data;
	I2C_Read(MPQ8645_ADDR,STATUS_VOUT,&STATUS_VOUT_data,1);
	uint8_t STATUS_IOUT_data;
	I2C_Read(MPQ8645_ADDR,STATUS_IOUT,&STATUS_IOUT_data,1);
	uint8_t STATUS_INPUT_data;
	I2C_Read(MPQ8645_ADDR,STATUS_INPUT,&STATUS_INPUT_data,1);
	uint8_t STATUS_TEMPERATURE_data;
	I2C_Read(MPQ8645_ADDR,STATUS_TEMPERATURE,&STATUS_TEMPERATURE_data,1);
	
	
	GetStatus->COMM_ERROR = STATUS_BYTE_data & 0x02;
	
	GetStatus->VOUT_OV_FAULT = STATUS_VOUT_data & 0x80;
	GetStatus->VOUT_UV_FAULT = STATUS_VOUT_data & 0x10;
	GetStatus->VOUT_MAX_MIN = STATUS_VOUT_data & 0x08;
	
	GetStatus->IOUT_OC = STATUS_IOUT_data & 0x80;
	GetStatus->IOUT_OC_WARNING = STATUS_IOUT_data & 0x20;
	
	GetStatus->VIN_OV_FAULT = STATUS_INPUT_data & 0x80;
	GetStatus->VIN_OV_WARN = STATUS_INPUT_data & 0x40;
	GetStatus->VIN_UV_WARN = STATUS_INPUT_data & 0x20;
	GetStatus->VIN_UV_FAULT = STATUS_INPUT_data & 0x10;
	
	GetStatus->OT_FAULT = STATUS_TEMPERATURE_data & 0x80;
	GetStatus->OT_WARNING = STATUS_TEMPERATURE_data & 0x40;
}


void MPQ8645_Init(void){
	HAL_GPIO_WritePin(GPIOA, DC_EN2_Pin, GPIO_PIN_RESET);
  HAL_Delay(100);

	MPQ8645_CLEAR_FAULTS();
	
	MPQ8645_MFR_CTRL_VOUT(1,0,1);
	MPQ8645_VOUT_SCALE_LOOP(0.5);
  MPQ8645_VOUT_COMMAND(860);

	MPQ8645_VOUT_MAX(890);
	MPQ8645_VOUT_MIN(820);
	
	MPQ8645_VIN_ON(6000);
	MPQ8645_VIN_OFF(5000);
	
	MPQ8645_IOUT_OC_FAULT_LIMIT(60000);
	MPQ8645_IOUT_OC_WARN_LIMIT(55000);

	MPQ8645_OT_FAULT_LIMIT(100);
  MPQ8645_OT_WARN_LIMIT(85);

	MPQ8645_VIN_OV_FAULT_LIMIT(16000);
  MPQ8645_VIN_OV_WARN_LIMIT(15500);
	MPQ8645_VIN_UV_WARN_LIMIT(5500);

  MPQ8645_MFR_CTRL_OPS(600,1);
	MPQ8645_MFR_CTRL(0,0,1);
	
}