#include "RCC.h"

void RCC_VidSelectSysCLK(u8 Copy_u8SysClk)
{
	/*Select System clock*/
	RCC_CFGR_REG->SW = RESET;
	Copy_u8SysClk &= RCC_SW_NOTALLOWED;
	if (Copy_u8SysClk != RCC_SW_NOTALLOWED)
	{
		RCC_CFGR_REG->SW = Copy_u8SysClk;
	}
	else
	{
		/*Return Not Allowed Error*/
	}
}

void RCC_VidSelectControlCLK(u8 Copy_u8ControlHSI, u8 Copy_u8ControlHSE, u8 Copy_u8ControlPLL)
{

	/*************************HSI Control*********************************/
	if (Copy_u8ControlHSI == RCC_HSI_ON)
	{
		RCC_CR_REG->HSION = SET;
		while (RCC_CR_REG->HSIRDY != SET)
			;
	}
	else if (Copy_u8ControlHSI == RCC_HSI_OFF)
	{
		RCC_CR_REG->HSION = RESET;
	}
	else
	{
		/*Return HSI control Error*/
	}

	/**************************HSE control********************************/
	if (Copy_u8ControlHSE == RCC_HSE_CRYSTAL_ON)
	{
		RCC_CR_REG->HSEON = SET;
		while (RCC_CR_REG->HSERDY != RESET)
			;
	}
	else if (Copy_u8ControlHSE == RCC_HSE_RC_ON)
	{

		RCC_CR_REG->HSEON = RESET;
		RCC_CR_REG->HSEBYP = SET;
		RCC_CR_REG->HSEON = SET;
	}
	else if (Copy_u8ControlHSE == RCC_HSE_OFF)
	{
		RCC_CR_REG->HSEON = RESET;
		RCC_CR_REG->HSEBYP = RESET;
	}
	else
	{
		/*Return HSE control Error*/
	}

	/**************************PLL control********************************/
	if (Copy_u8ControlPLL == RCC_PLL_ON)
	{
		RCC_CR_REG->PLLON = SET;
		while (RCC_CR_REG->PLLRDY != SET)
			;
	}
	else if (Copy_u8ControlPLL == RCC_PLL_OFF)
	{
		RCC_CR_REG->PLLON = RESET;
	}
	else
	{
		/*Return PLL control Error*/
	}
}

void RCC_VidCheckClk(u8 Copy_u8Clk, pu8 Add_pu8RdyStatus)
{
	switch (Copy_u8Clk)
	{
	case RCC_HSI:
		if (RCC_CR_REG->HSIRDY == 1)
		{
			*Add_pu8RdyStatus = TRUE;
		}
		else
		{
			*Add_pu8RdyStatus = FALSE;
		}
		break;
	case RCC_HSE:
		if (RCC_CR_REG->HSERDY == 1)
		{
			*Add_pu8RdyStatus = TRUE;
		}
		else
		{
			*Add_pu8RdyStatus = FALSE;
		}
		break;
	case RCC_PLL:
		if (RCC_CR_REG->PLLRDY == 1)
		{
			*Add_pu8RdyStatus = TRUE;
		}
		else
		{
			*Add_pu8RdyStatus = FALSE;
		}
		break;
	default:
		break;
	}
}

void RCC_VidCnfgrPLL(PLL_SRC_t Copy_enuPllSrc, PLL_MUL_t Copy_enuPllMul)
{
	switch (Copy_enuPllSrc)
	{
	case PLL_HSI:
		RCC_CFGR_REG->PLLSRC = RESET;
		break;
	case PLL_HSE:
		RCC_CFGR_REG->PLLSRC = SET;
		RCC_CFGR_REG->PLLXTPRE = RESET;

		break;
	case PLL_HSE_Div2:
		RCC_CFGR_REG->PLLSRC = SET;
		RCC_CFGR_REG->PLLXTPRE = SET;
		break;
	default:
		break;
	}

	RCC_CFGR_REG->PLLMUL = Copy_enuPllMul;
}

void RCC_VidEnablePeriphral(u8 Copy_u8PeriphralBus, u8 Copy_u8Peripheral)
{
	if (Copy_u8Peripheral <= 31)
	{
		switch (Copy_u8PeriphralBus)
		{
		case RCC_AHB:
			SET_BIT(RCC_AHBENR, Copy_u8Peripheral);
			break;

		case RCC_APB1:
			SET_BIT(RCC_APB1ENR, Copy_u8Peripheral);
			break;

		case RCC_APB2:
			SET_BIT(RCC_APB2ENR, Copy_u8Peripheral);
			break;
		default:
			/*Return Error*/
			break;
		}
	}
	else
	{
		/*Return Error*/
	}
}

void RCC_VidDisablePeriphral(u8 Copy_u8PeriphralBus, u8 Copy_u8Peripheral)
{
	if (Copy_u8Peripheral <= 31)
	{
		switch (Copy_u8PeriphralBus)
		{
		case RCC_AHB:
			CLR_BIT(RCC_AHBENR, Copy_u8Peripheral);
			break;
		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR, Copy_u8Peripheral);

			break;
		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR, Copy_u8Peripheral);

			break;
		default:
			/*Return Error*/
			break;
		}
	}
	else
	{
		/*Return Error*/
	}
}

