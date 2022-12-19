#include <stdio.h>
#include "Bms.h"


/****************soc*****************************************/
int BattSocLowLimit(float soc)
{	
	if ((soc >= MIN_LOWSOCBREACH) || (soc <= MIN_SOCNORMAL))
	{
		return STATUS_NOT_OK; 
	}
	else
	{
		/*SOC of Battery is in charging state*/
		return STATUS_OK; 
	}
}

int BattSocHighLimit(float soc)
{
	if ((soc >= MIN_HIGHSOCWARNING) || (soc <= MIN_HIGHSOCBREACH))
	{
		return STATUS_NOT_OK; 
	}
	else 
	{
		return STATUS_NOT_OK; 
	}
	
}

int tBatterySocIsOk(float soc )
{
	int socStatus = STATUS_OK;
	if((soc >= MIN_LOWSOCBREACH) && (soc <= MIN_HIGHSOCWARNING))
	{
		socStatus = BattSocLowLimit(soc);
	}
	else
	{
		socStatus = BattSocHighLimit(soc);
	}
	return socStatus;
}

/****************TEMP*****************************************/
int BattTempLowLimit(float temp)
{	
	if ((temp >= MIN_LOWTEMPBREACH) || (temp <= MIN_TEMPNORMAL))
	{
		return STATUS_NOT_OK; 
	}
	else
	{
		return STATUS_OK; 
	}
}

int BattTempHighLimit(float temp, char tempUnit)
{
	if ((temp >= MIN_HIGHTEMPWARNING) || (temp <= MIN_HIGHTEMPBREACH))
	{
		return STATUS_NOT_OK; 
	}
	else 
	{   tBattConvertTemp(temp, tempUnit);
		return STATUS_NOT_OK; 
	}
	
}

int tBatteryTempIsOk(float temp, char tempUnit )
{
	int tempStatus = STATUS_OK;
	if((temp >= MIN_LOWTEMPBREACH) && (temp < MIN_HIGHTEMPWARNING))
	{
		tempStatus = BattTempLowLimit(temp);
	}
	else
	{
		tempStatus = BattTempHighLimit(temp, tempUnit);
	}
	return tempStatus;
}

bool tBattTempUnit(char cel)
 {
 	if(cel == TEMP_UNIT_CELCIUS)
		return true;
	 else
		return false;
 }

float tBattConvertTemp(float temp, char tempUnit)
{
	float celcius;
	if((temp > MAX_HIGHTEMPBREACH) && (tempUnit == TEMP_UNIT_FARENHEIT))
	{
		celcius = (temp - 32) * 5 / 9;
	}
	else
	{
		return temp;
	}
}

/****************ChargeRate*****************************************/
int BattChargeRateLowLimit(float chargeRate)
{	
	if ((chargeRate >= MIN_LOWCHARGERATEBREACH) || (chargeRate <= MIN_CHARGERATENORMAL))
	{
		return STATUS_NOT_OK; 
	}
	else
	{
		return STATUS_OK; 
	}
}

int BattChargeRateHighLimit(float chargeRate)
{
	if ((chargeRate >= MIN_HIGHCHARGERATEWARNING) || (chargeRate <= MIN_HIGHCHARGERATEBREACH))
	{
		return STATUS_NOT_OK; 
	}
	else 
	{
		return STATUS_NOT_OK; 
	}
	
}

int tBatteryChargeRateIsOk(float chargeRate )
{
	int chargeRateStatus = STATUS_OK;
	if((chargeRate >= MIN_LOWCHARGERATEBREACH) && (chargeRate < MIN_HIGHCHARGERATEWARNING))
	{
		chargeRateStatus = BattChargeRateLowLimit(chargeRate);
	}
	else
	{
		chargeRateStatus = BattChargeRateHighLimit(chargeRate);
	}
	return chargeRateStatus;
}

int batteryIsOk(float temp, float soc, float chargeRate, char tempUnit)
{	
	float stateOfCharge = tBatterySocIsOk(soc);
	float temperature = tBatteryTempIsOk(temp, tempUnit);
	float chargerate = tBatteryChargeRateIsOk(chargeRate);
	return (temperature && stateOfCharge && chargerate);
}
int batteryIsNotOk(float temp, float soc, float chargeRate, char tempUnit)
{	
	float stateOfCharge = tBatterySocIsOk(soc);
	float temperature = tBatteryTempIsOk(temp, tempUnit);
	float chargerate = tBatteryChargeRateIsOk(chargeRate);
	return (temperature || stateOfCharge || chargerate);
}
