#include "test_BatManagSys_Status.h"

int test_batteryIsOk(float expectedTemp, float expectedsoc, float expectedChargeRate, char tempUnit)
{	
	batteryIsOk(expectedsoc,expectedTemp,expectedChargeRate, tempUnit);
}
int test_batteryIsNotOk(float expectedTemp, float expectedsoc, float expectedChargeRate, char tempUnit)
{	
	batteryIsNotOk(expectedsoc,expectedTemp,expectedChargeRate, tempUnit);
}

void testBatteryStatus_params(void)
{
	  assert(test_batteryIsNotOk(-1,88,1.0,'C'));
      assert(test_batteryIsNotOk(50,80,0.9, 'C'));
      assert(test_batteryIsOk(39,32,0.7, 'F'));
      assert(test_batteryIsOk(30,42,0.6, 'F'));
}    
