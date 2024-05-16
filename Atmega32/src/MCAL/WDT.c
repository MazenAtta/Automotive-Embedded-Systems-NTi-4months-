/*
 * WDT.c
 *
 * Created: 8/13/2023 10:32:36 AM
 *  Author: Mazen.Atta
 */

#include "WDT.h"

void WDT_VidSet(WDT_TimeOut_type Time_Out)
{
    u8 WDT_Value = 0x08;
    WDT_Value |= Time_Out;

  /* Write logical one to WDTOE and WDE */
    WDTCR = (1 << WDTOE) | (1 << WDE);
    WDTCR = WDT_Value;
}

void WDT_VidStop(void)
{ 
  /* Write logical one to WDTOE and WDE */
    WDTCR = (1 << WDTOE) | (1 << WDE); 
    /* Turn off WDT */
    WDTCR = 0x00;
}