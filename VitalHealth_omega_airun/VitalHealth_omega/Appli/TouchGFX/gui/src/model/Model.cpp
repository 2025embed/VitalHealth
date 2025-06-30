#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cstdint>


extern "C"
{
extern float CO2;
extern float Temp;
extern float RH;
extern uint32_t Light;
extern uint8_t TOF;
extern float Fatigue;
extern void process_light_data(void);
extern float Modbus_Parse_Float(uint8_t *data);
extern void Modbus_Read_Sensor(void);
extern void Modbus_Soft_Reset(void);
extern void Start_Continuous_Trigger(void);
extern void UPLOAD_DATA();
extern void L610_INIT();
extern void Debug_and_Uart();
extern void TOF_RUN();
extern void TOF_INIT();
extern void TOF_DESTROY();
extern void CAMERA_INIT();
extern void CAMERA_RUN();
extern void CAMERA_DESTROY();
extern void FATIGUE_INIT();
extern void FATIGUE_RUN();
extern void FATIGUE_DESTROY();
extern void PRECLOS();
extern void SNOPSHOT();
}

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	tickCounter++;
	if((tickCounter%10)==0)
	{
		if(modelListener!=0)
		{
			switch(tag)
			{
			case L610:
				L610Init();
				tag=READ;
				break;
			case READ:
				SensorRead();
				tag=TEMP;
				break;
			case TEMP:
				modelListener->newjunctiontemp(getTempvalue());
				tag=HUMIDITY;
				break;
			case HUMIDITY:
				modelListener->newjunctionHumi(getHumivalue());
				tag=CARBON;
				break;
			case CARBON:
				modelListener->newjunctionCO2(getCO2value());
				tag=LUXLIGHT;
				break;
			case LUXLIGHT:
				LightRead();
				modelListener->newjunctionLight(getLightvalue());
				tag=UPLOADSENSOR;
				break;
			case UPLOADSENSOR:
				upload();
				tag=TOFINIT;
				break;
			case TOFINIT:
				tofinit();
				tag=TOFDIS;
				break;
			case TOFDIS:
				tofdis();
				modelListener->newjunctionTOF(getTofvalue());
				tag=TOFDESTROY;
				break;
			case TOFDESTROY:
				tofdestroy();
				tag = SHOOTPIC;
				break;
			case SHOOTPIC:
				shootapicture();
				tag=CAMERAINIT;
				break;
			case CAMERAINIT:
				camerainit();
				tag = CAMERADIS;
				break;
			case CAMERADIS:
				cameradis();
				tag = CAMERADESTROY;
				break;
			case CAMERADESTROY:
				cameradestroy();
				tag = FATIGUEINIT;
				break;
			case FATIGUEINIT:
				fatigueinit();
				tag = FATIGUEDIS;
				break;
			case FATIGUEDIS:
				fatiguedis();
				tag = FATIGUEDESTROY;
				break;
			case FATIGUEDESTROY:
				fatiguedestroy();
				tag = RUNPRECLOS;
				break;
			case RUNPRECLOS:
				runpreclos();
				modelListener->newjunctionFatigue(getFatiguevalue());
				tag = DEBUGDIS;
				break;
			case DEBUGDIS:
				debugdis();
				tag=L610;
				break;
			}
		}
	}

}

void Model::shootapicture()
{
	SNOPSHOT();
}
void Model::tofinit()
{
	TOF_INIT();
}
void Model::tofdis()
{
	TOF_RUN();
}
void Model::tofdestroy()
{
	TOF_DESTROY();
}
void Model::camerainit()
{
	CAMERA_INIT();
}
void Model::cameradis()
{
	CAMERA_RUN();
}
void Model::cameradestroy()
{
	CAMERA_DESTROY();
}
void Model::fatigueinit()
{
	FATIGUE_INIT();
}
void Model::fatiguedis()
{
	FATIGUE_RUN();
}
void Model::fatiguedestroy()
{
	FATIGUE_DESTROY();
}
void Model::runpreclos()
{
	PRECLOS();
}
void Model::debugdis()
{
	Debug_and_Uart();
}
void Model::L610Init()
{
	L610_INIT();
}
void Model::SensorRead()
{
	Modbus_Read_Sensor();
}
void Model::LightRead()
{
	process_light_data();
}
void Model::upload()
{
	UPLOAD_DATA();
}
float Model::getTempvalue()
{
	return Temp;
}
float Model::getHumivalue()
{
	return RH;
}
float Model::getCO2value()
{
	return CO2;
}
int Model::getLightvalue()
{
	return Light;
}
int Model::getTofvalue()
{
	return TOF;
}
float Model::getFatiguevalue()
{
	return Fatigue;
}

