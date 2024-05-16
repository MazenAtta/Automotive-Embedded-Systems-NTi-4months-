/*
 * MemMap.h
 *
 * Created: 9/21/2023 9:39:41 PM
 *  Author: Mazen.Atta
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_

#include "LIB/STD_TYPES.h"

/*************************************************RCC Register*****************************************************/
typedef union
{
    struct
    {
        unsigned HSION    : 1;
        unsigned HSIRDY   : 1;
        unsigned HSITRIM  : 5;
        unsigned HSICAL   : 9;
        unsigned HSEON    : 1;
        unsigned HSERDY   : 1;
        unsigned HSEBYP   : 1;
        unsigned CSSON    : 1;
        unsigned Reserved0 : 4;
        unsigned PLLON    : 1;
        unsigned PLLRDY   : 1;
        unsigned Reserved1 : 6;
    };
    u32 RCC_RC_REGISTER;
} RCC_RC_t;

typedef union
{
    struct
    {
        unsigned SW          : 2;
        unsigned SWS         : 2;
        unsigned HPRE        : 4;
        unsigned PPRE1       : 3;
        unsigned PPRE2       : 3;
        unsigned ADCPRE      : 2;
        unsigned PLLSRC      : 1;
        unsigned PLLXTPRE    : 1;
        unsigned PLLMUL      : 4;
        unsigned USBPRE      : 1;
        unsigned RESERVED0   : 1;
        unsigned MCO         : 3;
        unsigned RESERVED1   : 5;

    };
    u32 RCC_CFGR_REGISTER;
} RCC_CFGR_t;

#define RCC_CR_REG ((volatile RCC_RC_t *)0x40021000)
#define RCC_CFGR_REG  ((volatile RCC_CFGR_t *)0x40021004)

#define RCC_CIR *((volatile u32 *)0x40021008)
#define RCC_APB2RSTR *((volatile u32 *)0x4002100C)
#define RCC_APB1RSTR *((volatile u32 *)0x40021010)
#define RCC_AHBENR *((volatile u32 *)0x40021014)

/********AHB periphrals********/

#define SDIOEN 10 // SDIO clock enable
#define FSMCEN 8  // FSMC clock enable
#define CRCEN 6   // CRC clock enable
#define FLITFEN 4 // FLITF clock enable
#define SRAMEN 2  // SRAM interface clock enable
#define DMA2EN 1  // DMA2 clock enable
#define DMA1EN 0  // DMA1 clock enable

#define RCC_APB2ENR *((volatile u32 *)0x40021018)

/********APB2 periphrals********/

#define TIM11EN 21  // TIM11 timer clock enable
#define TIM10EN 20  // TIM10 timer clock enable
#define TIM9EN 19   // TIM9 timer clock enable
#define ADC3EN 15   // ADC3 interface clock enable
#define USART1EN 14 // USART1 clock enable
#define TIM8EN 13   // TIM8 Timer clock enable
#define SPI1EN 12   // SPI1 clock enable
#define TIM1EN 11   // TIM1 timer clock enable
#define ADC2EN 10   // ADC 2 interface clock enable
#define ADC1EN 9    // ADC 1 interface clock enable
#define IOPGEN 8    // IO port G clock enable
#define IOPFEN 7    // IO port F clock enable
#define IOPEEN 6    // IO port E clock enable
#define IOPDEN 5    // IO port D clock enable
#define IOPCEN 4    // IO port C clock enable
#define IOPBEN 3    // IO port B clock enable
#define IOPAEN 2    // IO port A clock enable
#define AFIOEN 0    // Alternate function IO clock enable

#define RCC_APB1ENR *((volatile u32 *)0x4002101C)

/********APB1 periphrals********/

#define DACEN 29    // DAC interface clock enable
#define PWREN 28    // Power interface clock enable
#define BKPEN 27    // Backup interface clock enable
#define CANEN 25    // CAN clock enable
#define USBEN 23    // USB clock enable
#define I2C2EN 22   // I2C2 clock enable
#define I2C1EN 21   // I2C1 clock enable
#define UART5EN 20  // USART5 clock enable
#define UART4EN 19  // USART4 clock enable
#define USART3EN 18 // USART3 clock enable
#define USART2EN 17 // USART2 clock enable
#define SPI3EN 15   // SPI 3 clock enable
#define SPI2EN 14   // SPI2 clock enable
#define WWDGEN 11   // Window watchdog clock enable
#define TIM14EN 8   // TIM14 timer clock enable
#define TIM13EN 7   // TIM13 timer clock enable
#define TIM12EN 6   // TIM12 timer clock enable
#define TIM7EN 5    // TIM7 timer clock enable
#define TIM6EN 4    // TIM6 timer clock enable
#define TIM5EN 3    // TIM5 timer clock enable
#define TIM4EN 2    // TIM4 timer clock enable
#define TIM3EN 1    // TIM3 timer clock enable
#define TIM2EN 0    // TIM2 timer clock enable

#define RCC_BDCR *((volatile u32 *)0x40021020)
#define RCC_CSR *((volatile u32 *)0x40021024)

#endif /*MemMap_H_*/
