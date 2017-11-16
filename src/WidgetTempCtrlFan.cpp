

#include "WidgetTempCtrlFan.h"



WidgetTempCtrlFan::WidgetTempCtrlFan(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pCmdSwitchTopic,0,sizeof(pCmdSwitchTopic));
    memset(pDataSwitchStatusTopic,0,sizeof(pDataSwitchStatusTopic));  
    memset(pDataTemperatureTopic,0,sizeof(pDataTemperatureTopic));  

    sprintf(pCmdSwitchTopic,"channel/tempCtrlFan_%d/cmd/switch",_Item);   
    sprintf(pDataSwitchStatusTopic,"channel/tempCtrlFan_%d/data/status",_Item);  
	sprintf(pDataTemperatureTopic,"channel/tempCtrlFan_%d/data/temperature",_Item);  

}

WidgetTempCtrlFan::~WidgetTempCtrlFan()
{
    
}

void WidgetTempCtrlFan::begin(void (*UserCallBack)(void))
{
    _EventCb=UserCallBack;
    IntoRobot.subscribe(pCmdSwitchTopic, NULL, this);
}

char WidgetTempCtrlFan::getFanSwitch(void)
{
    return _switchKey;
}

void WidgetTempCtrlFan::displayFanStatus(uint8_t ucVal)
{
    IntoRobot.publish(pDataSwitchStatusTopic,ucVal);
}

void WidgetTempCtrlFan::displayTemperature(int temperature)
{
	IntoRobot.publish(pDataTemperatureTopic,temperature);
}


void WidgetTempCtrlFan::control(uint8_t ucPin, uint8_t ucVal)
{
    pinMode(ucPin,OUTPUT);
    digitalWrite(ucPin, ucVal);
    displayFanStatus(ucVal);
}

void WidgetTempCtrlFan::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
 	if(payload[0] == '1')
	{
        _switchKey = ON;
	}
	else 
	{
        _switchKey = OFF;
	} 
}

