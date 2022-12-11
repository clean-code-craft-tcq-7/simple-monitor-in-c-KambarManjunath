#ifndef BMS_H
#define BMS_H
#include <stdbool.h>
#define MAX_CAPACITY_BATTERY 25


#define MIN_LOWSOCBREACH         0
#define MIN_LOWSOCWARNING        20
#define MIN_SOCNORMAL		 24
#define MIN_HIGHSOCWARNING 	 75
#define MIN_HIGHSOCBREACH        80
#define MAX_HIGHOCBREACH         100

#define MIN_LOWTEMPBREACH        0
#define MIN_LOWTEMPWARNING       5
#define MIN_TEMPNORMAL           10
#define MIN_HIGHTEMPWARNING      40
#define MIN_HIGHTEMPBREACH       45
#define MAX_HIGHTEMPBREACH       80

#define MIN_LOWCHARGERATEBREACH   0
#define MIN_LOWCHARGERATEWARNING  0.2
#define MIN_CHARGERATENORMAL      0.3
#define MIN_HIGHCHARGERATEWARNING 0.7
#define MIN_HIGHCHARGERATEBREACH  0.8
#define MAX_HIGHCHARGERATEBREACH  1.0


#define E_OK                       0
#define E_NOT_OK                   1



extern int BattSocLowLimit(float soc);
extern int BattSocHighLimit(float soc);
extern int tBatterySocIsOk(float soc );
extern int BattTempLowLimit(float temp);
extern int intBattTempHighLimit(float temp , char tempUnit);
extern int inttBatteryTempIsOk(float temp , char tempUnit );
extern int intBattChargeRateLowLimit(float chargeRate);
extern int intBattChargeRateHighLimit(float chargeRate);
extern int inttBatteryChargeRateIsOk(float chargeRate );
extern bool inttBattTempUnit(char cel);
extern float inttBattConvertTemp(float temp, char tempUnit);

extern int batteryIsOk(float temp, float soc, float chargeRate);
extern int batteryIsNotOk(float temp, float soc, float chargeRate);


#endif