/*
 * RCC.h
 *
 * Created: 9/21/2023 9:39:41 PM
 *  Author: Mazen.Atta
 */

#ifndef RCC_H_
#define RCC_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "APP/Cnfig.h"
#include "APP/MemMap.h"

/***Macros**/
#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2

#define RCC_HSI_ON 1
#define RCC_HSI_OFF 0

#define RCC_HSE_CRYSTAL_ON 3
#define RCC_HSE_OFF 2

#define RCC_HSE_RC_ON 5

#define RCC_PLL_ON 7
#define RCC_PLL_OFF 6

#define RCC_SW_NOTALLOWED 3

typedef enum
{
    PLL_HSI,
    PLL_HSE,
    PLL_HSE_Div2,
} PLL_SRC_t;

typedef enum
{
    PLL_MUL_2 = 0,
    PLL_MUL_3,
    PLL_MUL_4,
    PLL_MUL_5,
    PLL_MUL_6,
    PLL_MUL_7,
    PLL_MUL_8,
    PLL_MUL_9,
    PLL_MUL_10,
    PLL_MUL_11,
    PLL_MUL_12,
    PLL_MUL_13,
    PLL_MUL_14,
    PLL_MUL_15,
    PLL_MUL_16
} PLL_MUL_t;

#define RCC_AHB 0
#define RCC_APB1 1
#define RCC_APB2 2

/**************RCC functions*****************/
void RCC_VidSelectSysCLK(u8 Copy_u8SysClk);

void RCC_VidSelectControlCLK(u8 Copy_u8ControlHSI, u8 Copy_u8ControlHSE, u8 Copy_u8ControlPLL);

void RCC_VidCheckClk(u8 Copy_u8Clk, pu8 Add_pu8RdyStatus);

void RCC_VidCnfgrPLL(PLL_SRC_t Copy_enuPllSrc, PLL_MUL_t Copy_enuPllMul);

void RCC_VidEnablePeriphral(u8 Copy_u8PeriphralBus, u8 Copy_u8Peripheral);

void RCC_VidDisablePeriphral(u8 Copy_u8PeriphralBus, u8 Copy_u8Peripheral);

#endif /*RCC_H_*/
