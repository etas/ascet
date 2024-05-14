#ifndef HA_TYPES_H_
#define HA_TYPES_H_

/* Standard type definitions for handcode */
typedef unsigned char				BOOL;
typedef char						C8;
typedef signed char  				S8;
typedef unsigned char 				U8;
typedef volatile unsigned char 		VU8;
typedef unsigned short  			U16;
typedef volatile unsigned short  	VU16;
typedef signed short				S16;
typedef unsigned long				U32;
typedef volatile unsigned long		VU32;
typedef signed long					S32;
typedef signed long long 			S64;
typedef unsigned long long 			U64;
typedef float						F32;
typedef double 						F64;
typedef void						VOID;
#define SVOID						static void
typedef U32 						SYSTIM;

#define FALSE_U8					(U8)0
#define TRUE_U8						(U8)1

#endif
