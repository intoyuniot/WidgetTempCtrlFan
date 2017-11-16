#ifndef WIDGET_TEMP_CTRL_FAN_H_
#define WIDGET_TEMP_CTRL_FAN_H_

#include "application.h"

class WidgetTempCtrlFan: public WidgetBaseClass
{
    public:
        WidgetTempCtrlFan(uint8_t ucItem = 0);
        ~WidgetTempCtrlFan();
        void begin(void (*UserCallBack)(void) = NULL);
        char getFanSwitch(void);
        void displayFanStatus(uint8_t ucVal);
        void control(uint8_t ucPin, uint8_t ucVal);
        void displayTemperature(int temperature);

    private:
        char pCmdSwitchTopic[64];
        char pDataSwitchStatusTopic[64];
        char pDataTemperatureTopic[64];
        char _switchKey = 0;
        uint8_t _Item = 0;
        void (*_EventCb)(void);
        void widgetBaseCallBack(uint8_t *payload, uint32_t len);
};

#endif

