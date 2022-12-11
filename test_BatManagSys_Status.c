#include "test_BatManageSys_Staus.h"

int test_batteryIsOk(float expectedTemp, float expectedsoc, float expectedChargeRate)
{	
	batteryIsOk(expectedsoc,expectedTemp,expectedChargeRate,expectedTempUnit);
}
int test_batteryIsNotOk(float expectedTemp, float expectedsoc, float expectedChargeRate)
{	
	batteryIsNotOk(expectedsoc,expectedTemp,expectedChargeRate,expectedTempUnit);
}

void testBatteryStatus_params(void)
{
	  assert(test_batteryIsNotOk(-1,88,1.0));
      assert(test_batteryIsNotOk(50,80,0.9));
      assert(test_batteryIsOk(39,32,0.7));
      assert(test_batteryIsOk(30,42,0.6));
}    
   