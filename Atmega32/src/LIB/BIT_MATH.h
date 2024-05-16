/*
 * BIT_MATH.h
 *
 * Created: 8/6/2023 9:39:41 PM
 *  Author: Mazen.Atta
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*Set Bit*/
#define SET_BIT(REG, BIT_NUM) (REG |= (1 << BIT_NUM))

/*Clear Bit*/
#define CLR_BIT(REG, BIT_NUM) (REG &= (~(1 << BIT_NUM)))

/*Toggle Bit*/
#define TOG_BIT(REG, BIT_NUM) (REG ^= (1 << BIT_NUM))

/*Get Bit*/
#define GET_BIT(REG, BIT_NUM) ((REG >> BIT_NUM) & 1)

#define RSHFT_REG(REG,NO)         (REG<<NO)
#define LSHFT_REG(REG,NO)         (REG>>NO)



#define ASSIGN_REG(REG, value) (REG | value)
#define SET_REG(REG) (REG | 0XFF)
#define CLR_REG(REG) (REG | 0X00)
#define TOG_REG(REG) (~REG)

#define SET_H_NIB(REG) ((REG | 0xF0))
#define SET_L_NIB(REG) ((REG | 0x0F))
#define CLR_H_NIB(REG) ((REG & 0x0F))
#define CLR_L_NIB(REG) ((REG & 0xF0))
#define GET_H_NIB(REG) ()

#define CHECK_IF_BIT_SET(REG, BIT) (REG & (1 << (BIT)))
#define CHECK_IF_BIT_CLEARED(REG, BIT) (!(REG & (1 << (BIT))))

#define CHECK_IF_BIT_SET_MODIFIED(REG, BIT) (1 & (REG >> (BIT)))
#define CHECK_IF_BIT_CLEARED_MODIFIED(REG, BIT) (!(1 & (REG >> (BIT))))

#endif /* BIT_MATH_H_ */