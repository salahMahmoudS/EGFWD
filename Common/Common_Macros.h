
/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  Common_Macros.h
*       Module:  Common
*
*  Description:  This file contains the basic math operations that are done on registers     
*  Author: Salah Mahmoud
*********************************************************************************************************************/
#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H


/**********************************************************************************************************************
*  GLOBAL FUNCTION MACROS
*********************************************************************************************************************/
/*CONCAT_HELPER MACRO is used to concatinate all GPIO pins into one register after calling the CONCAT MACRO*/
#define CONCAT_HELPER(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab,ac,ad,ae,af,ag,ah) (0b##a##b##c##d##e##f##g##h##i##j##k##l##m##n##o##p##q##s##t##u##v##x##y##z##aa##ab##ac##ad##ae##af##ag##ah) 

/*This MACRO is used to align all bits in GPIO ports to their corresponding register by mapping all pins defined in the configuration file to their register*/
#define CONCAT(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab,ac,ad,ae,af,ag,ah) (CONCAT_HELPER(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab,ac,ad,ae,af,ag,ah)) 

/*MACRO to set a certain bit in a register*/
#define SET_BIT(REGISTER,PIN) (REGISTER) =(REGISTER | 1<<PIN) 	
/*MACRO to clear a certain bit in a register */
#define CLEAR_BIT(REGISTER,PIN) (REGISTER) =((REGISTER) & ~((1) << (PIN)))
/*MACRO to toggle a certain bit in a register*/
#define TOGGLE_BIT(REGISTER,PIN) (REGISTER) =(REGISTER^(1<<PIN))
/*MACRO to return a certain bit state in a register*/
#define CHECK_BIT(REGISTER,PIN) ((REGISTER>>PIN)&1)							



#endif  /* BIT_MATH_H_ */

/**********************************************************************************************************************
*  END OF FILE: Std_Types.h
*********************************************************************************************************************/
