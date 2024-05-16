/*
 * MemMap.h
 *
 * Created: 8/6/2023 9:31:00 PM
 *  Author: Mazen.Atta
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_

/*********************************DIO***********************************/

#define PORTA *((volatile u8 *)0x3B)
#define DDRA *((volatile u8 *)0x3A)
#define PINA *((volatile u8 *)0x39)

#define PORTB *((volatile u8 *)0x38)
#define DDRB *((volatile u8 *)0x37)
#define PINB *((volatile u8 *)0x36)

#define PORTC *((volatile u8 *)0x35)
#define DDRC *((volatile u8 *)0x34)
#define PINC *((volatile u8 *)0x33)

#define PORTD *((volatile u8 *)0x32)
#define DDRD *((volatile u8 *)0x31)
#define PIND *((volatile u8 *)0x30)

/**********************************ADC*************************************/
#define ADMUX *((volatile u8 *)0x27)
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 5
#define ADLAR 4
#define REFS0 6
#define REFS1 7

#define ADCSRA *((volatile u8 *)0x26)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE 3
#define ADIF 5
#define ADATE 4
#define ADSC 6
#define ADEN 7

#define ADCL *((volatile u8 *)0x24)
#define ADCH *((volatile u8 *)0x25)
#define ADC *((volatile u16 *)0x24)

#define SFIOR *((volatile u8 *)0x50)
#define PSR10 0
#define PSR2 1
#define PUD 2
#define ACME 3
#define ADTS0 5
#define ADTS1 6
#define ADTS2 7

/**************************************************SREG******************************************************/

#define SREG *((volatile u8 *)0x5F)

/**************************************************EXTI******************************************************/

/*MCUR REG*/
#define MCUCR *((volatile u8 *)0x55)

#define ISC00_BIT 0
#define ISC01_BIT 1
#define ISC10_BIT 2
#define ISC11_BIT 3

/*MCUCSR REG*/
#define MCUCSR *((volatile u8 *)0x54)

#define ISC2_BIT 6

/*MCUSR GICR*/
#define GICR *((volatile u8 *)0x5B)

#define INT2 5
#define INT0 6
#define INT1 7

/*MCUSR GIFR*/
#define GIFR *((volatile u8 *)0x5A)

#define INTF2 5
#define INTF0 6
#define INTF1 7

/********************************Timer*****************************************/
#define TIMSK *((volatile u8 *)0x59)

#define TOIE0 0
#define OCIE0 1
#define TOIE1 2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2 6
#define OCIE2 7

#define TIFR *((volatile u8 *)0x58)

#define TOV0 0
#define OCF0 1
#define TOV1 2
#define OCF1B 3
#define OCF1A 4
#define ICF1 5
#define TOV2 6
#define OCF2 7

#define TCCR0 *((volatile u8 *)0x53)

#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0 7

#define OCR0 *((volatile u8 *)0x5C)
#define TCNT0 *((volatile u8 *)0x52)

#define TCCR1A *((volatile u8 *)0x4F)

#define WGM10 0
#define WGM11 1
#define FOC1B 2
#define FOC1A 3
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

#define TCCR1B *((volatile u8 *)0x4E)

#define CS10 0
#define CS11 1
#define CS12 2
#define WGM12 3
#define WGM13 4
#define ICES1 6
#define ICNC1 7

#define TCNT1H *((volatile u8 *)0x4D)
#define TCNT1L *((volatile u8 *)0x4C)
#define TCNT1 *((volatile u16 *)0x4C)

#define OCR1AH *((volatile u8 *)0x4B)
#define OCR1AL *((volatile u8 *)0x4A)
#define OCR1A *((volatile u16 *)0x4A)

#define OCR1BH *((volatile u8 *)0x49)
#define OCR1BL *((volatile u8 *)0x48)
#define OCR1B *((volatile u16 *)0x48)

#define ICR1H *((volatile u8 *)0x47)
#define ICR1L *((volatile u8 *)0x46)
#define ICR1 *((volatile u16 *)0x46)

/********************************UART*****************************************/
#define UDR *((volatile u8 *)0x2C)

#define UCSRC *((volatile u8 *)0x40)
#define UCPOL 0
#define UCSZ0 1
#define UCSZ1 2
#define USBS 3
#define UPM0 4
#define UPM1 5
#define UMSEL 6
#define URSEL 7

#define UBRRH *((volatile u8 *)0x40)
#define UBRRL *((volatile u8 *)0x29)

#define UCSRA *((volatile u8 *)0x2B)
#define MPCM 0
#define U2X 1
#define PE 2
#define DOR 3
#define FE 4
#define UDRE 5
#define TXC 6
#define RXC 7

#define UCSRB *((volatile u8 *)0x2A)
#define TXB8 0
#define RXB8 1
#define UCSZ2 2
#define TXEN 3
#define RXEN 4
#define UDRIE 5
#define TXCIE 6
#define RXCIE 7

/********************************SPI*****************************************/
#define SPDR *((volatile u8 *)0x2F)

#define SPSR *((volatile u8 *)0x2E)
#define SPI2X 0
#define WCOL 6
#define SPIF 7

#define SPCR *((volatile u8 *)0x2D)
#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE 6
#define SPIE 7

/********************************Watch Dog Timer*****************************************/
#define MCUCSR *((volatile u8 *)0x54)

#define PORF 0
#define EXTRF 1
#define BORF 2
#define WDRF 3
#define JTRF 4
#define ISC2 6
#define JTD 7

#define WDTCR *((volatile u8 *)0x41)

#define WDP0 0
#define WDP1 1
#define WDP2 2
#define WDE 3
#define WDTOE 4

/********************************I2C*****************************************/
#define TWAR *((volatile u8 *)0x22)
#define TWA6 7
#define TWA5 6
#define TWA4 5
#define TWA3 4
#define TWA2 3
#define TWA1 2
#define TWA0 1
#define TWGCE 0

#define TWBR *((volatile u8 *)0x20)

#define TWCR *((volatile u8 *)0x56)
#define TWINT 7
#define TWEA 6
#define TWSTA 5
#define TWSTO 4
#define TWWC 3
#define TWEN 2
#define TWIE 0

#define TWDR *((volatile u8 *)0x23)

#define TWSR *((volatile u8 *)0x21)
#define TWS7 7
#define TWS6 6
#define TWS5 5
#define TWS4 4
#define TWS3 3
#define TWPS1 1
#define TWPS0 0

/********************************ISR*****************************************/

/* Interrupt Vectors */

/* External Interupt Request  0 */
#define INT0_VECT __vector_1

/* External Interupt Request  1 */
#define INT1_VECT __vector_2

/* External Interupt Request  2 */
#define INT2_VECT __vector_3

/* Timer/Counter2 Compare Match */
#define TIMR2_COMP_VECT __vector_4

/* Timer/Counter2 Overflow */
#define TIMR2_OVF_VECT __vector_5

/* Timer/Counter1 Capture Event */
#define TIMR1_ICU_VECT __vector_6

/* Timer/Counter1 Compare Match A */
#define TIMR1_OCA_VECT __vector_7

/* Timer/Counter1 Compare Match B */
#define TIMR1_OCB_VECT __vector_8

/* Timer/Counter1  Overfloww */
#define TIMR1_OVF_VECT __vector_9

/* Timer/Counter0 Compare Match */
#define TIMR0_OC_VECT __vector_10

/* Timer/Counter2 Overflow  */
#define TIMR0_OVF_VECT __vector_11

/* Serial Transfer Complete */
#define SPI_STC_VECT __vector_12

/* USART, Rx Complete */
#define UART_RX_VECT __vector_13

/* USART, Data Register Empty */
#define UART_UDRE_VECT __vector_14

/* USART, Tx Complete */
#define UART_TX_VECT __vector_15

/* ADC Conversion Complete */
#define ADC_VECT __vector_16

/* EEPROM Ready */
#define EE_RDY_VECT __vector_17

/* Analog Comparator */
#define ANA_COMP_VECT __vector_18

/* 2-wire Serial Interface */
#define TWI_VECT __vector_19

/* Store Program Memory Ready */
#define SPM_RD_VECT __vector_100

#define BAD_VECT __vector_default

/* Interrupt Functions */
#define sei() __asm__ __volatile__("sei" ::)
#define cli() __asm__ __volatile__("cli" ::)
#define reti() __asm__ __volatile__("reti" ::)
#define ret() __asm__ __volatile__("ret" ::)

#define ISR_NOBLOCK() __attribute__((interrupt))
#define ISR_NAKED() __attribute__((naked))

#define ISR(vector, ...)                             \
    void vector(void) __attribute__((signal, used)); \
    void vector(void)

#endif /* MEMMAP_H_ */