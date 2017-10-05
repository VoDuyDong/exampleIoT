#include "readSensor.h"


	uint16_t humi_val=0, temp_val=0;
	uint8_t checksum =0;
	uint8_t humi_val_real; 
	uint8_t temp_val_real;
	char strhumi[5],strtemp[5];

void Read_Sensor_SHT75(void)
{
	SHT15_Measure(&temp_val, &checksum, TEMP);
	SHT15_Measure(&humi_val, &checksum, HUMI); 
	SHT15_Calculate(temp_val, humi_val, &temp_val_real, &humi_val_real);

	sprintf(strtemp,"%d",temp_val_real);
	sprintf(strhumi,"%d",humi_val_real);

	Guitext_text_72pts(580, 370,(signed char*)"1200",Black,Blue);//PPM
	FillRect(385, 215, 100,75, White); //temp
	Guitext_text_72pts(390, 215,strtemp,Black,Black);

	FillRect(596, 215, 100,75, White); //humidity
	Guitext_text_72pts(600, 215,strhumi,Black,Black);
		
}