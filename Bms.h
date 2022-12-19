#ifndef BMS_H
#define BMS_H
#include <stdbool.h>
#define MAX_CAPACITY_BATTERY 25


#define MIN_LOWSOCBREACH         0
#define MIN_LOWSOCWARNING        20
#define MIN_SOCNORMAL		     24
#define MIN_HIGHSOCWARNING 	     76
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


#define STATUS_OK                       0
#define STATUS_NOT_OK                   1

#define TEMP_UNIT_FARENHEIT       'F'
#define TEMP_UNIT_CELCIUS         'C'


extern int BattSocLowLimit(float soc);
extern int BattSocHighLimit(float soc);
extern int tBatterySocIsOk(float soc );
extern int BattTempLowLimit(float temp);
extern int BattTempHighLimit(float temp , char tempUnit);
extern int tBatteryTempIsOk(float temp , char tempUnit );
extern int BattChargeRateLowLimit(float chargeRate);
extern int BattChargeRateHighLimit(float chargeRate);
extern int tBatteryChargeRateIsOk(float chargeRate );
extern bool tBattTempUnit(char cel);
extern float tBattConvertTemp(float temp, char tempUnit);

extern int batteryIsOk(float temp, float soc, float chargeRate, char tempUnit);
extern int batteryIsNotOk(float temp, float soc, float chargeRate, char tempUnit);


#endif