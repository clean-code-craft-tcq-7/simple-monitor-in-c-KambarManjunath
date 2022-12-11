#ifndef TEST_BMSSTATUS_H
#define TEST_BMSSTATUS_H

#include <assert.h>
#include "Bms.h"

extern int test_batteryIsOk(float expectedTemp, float expectedsoc, float expectedChargeRate);
extern int test_batteryIsNotOk(float expectedTemp, float expectedsoc, float expectedChargeRate);
extern void testBatteryStatus_params(void);


#endif