/*
 * std_types.h
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_



typedef unsigned char         boolean;

typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           sint8;          /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          sint16;         /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64;         /*       0..18446744073709551615  */

#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif

#ifndef TRUE
#define TRUE 0x01U
#endif

#ifndef FALSE
#define FALSE 0x00U
#endif

#define STD_HIGH        0x01U       /* Standard HIGH */
#define STD_LOW         0x00U       /* Standard LOW */

#define STD_ACTIVE      0x01U       /* Logical state active */
#define STD_IDLE        0x00U       /* Logical state idle */

#define STD_ON          0x01U       /* Standard ON */
#define STD_OFF         0x00U       /* Standard OFF */

#define PORT_HIGH      0xFFU
#define PORT_LOW       0x00U

typedef uint8  Std_ReturnType;
#define E_OK            ((Std_ReturnType)0x00U)      /* Function Return OK */
#define E_NOT_OK        ((Std_ReturnType)0x01U)


#endif /* STD_TYPES_H_ */
