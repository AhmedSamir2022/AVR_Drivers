/********************************************************************/
/*********************    NAME:AHMED SAMIR   ************************/
/*********************    LAYER:MCAL         ************************/
/*********************    COMPONENT:GIE      ************************/
/*********************    VERSION:1.00       ************************/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"

void GIE_VoidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void GIE_VoidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}

