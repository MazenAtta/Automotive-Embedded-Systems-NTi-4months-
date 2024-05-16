/*
 * STD_TYPES.h
 *
 * Created: 8/6/2023 9:39:27 PM
 *  Author: Mazen.Atta
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*unsigned types*/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;

/*signed types*/
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long int s64;

/*float Types*/
typedef float f32;
typedef double f64;

/*NULL*/
#define NULL 0
#define NULL_PTR ((void *)0)

/*Boolean*/
typedef enum
{
	FALSE = 0,
	TRUE
} Bool_t;

#endif /* STD_TYPES_H_ */