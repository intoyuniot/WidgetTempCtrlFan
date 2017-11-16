/*
 ************************************************************************
 * 作者:  IntoRobot Team
 * 版本:  V1.0.0
 * 日期:  03-30-15
 ************************************************************************
 功能描述：
 智能温控风扇：具有温湿度检测的智能风扇，可根据温度控制风扇

 所需器件:
 1.DHT11 温湿度传感器模块
 2.风扇
 3.继电器模块

 接线说明:
 DH11                         核心板
 1.VCC                        +3.3V
 2.GND                        GND
 3.DATA                       D1
 继电器模块
 1.DC+：                      +5V
 2.DC-：                      GND
 3.IN：                       D0
 4.NO：                       风扇的正极
 5.COM：                      +5V
 6.NC：                       悬空
 7.触发选择端：选择跳线与high短接, 即高电平触发。
 */

#include <IntoRobot_DHT.h>
#include <WidgetTempCtrlFan.h>

#define FAN_SWITCH_PIN    D0 //定义风扇开关控制引脚
#define DHT11_PIN    D1
#define DHT_TYPE     DHT11

WidgetTempCtrlFan tempCtrlFan = WidgetTempCtrlFan();
IntoRobot_DHT dht11(DHT11_PIN,DHT_TYPE);

void fanSwitchCb(void)
{
    if(tempCtrlFan.getFanSwitch())
    {
        tempCtrlFan.control(FAN_SWITCH_PIN, 1);	//打开风扇
    }
    else
    {
        tempCtrlFan.control(FAN_SWITCH_PIN, 0);	//关闭风扇
    }
}

void setup()
{
    //初始化
    dht11.begin();
    //接收风扇开关控制
    tempCtrlFan.begin(fanSwitchCb);
}

void loop()
{
    tempCtrlFan.displayTemperature(dht11.getTempCelcius()); //上送温度
    delay(3000);
}
