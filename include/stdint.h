#ifndef _STDINT_H_
#define _STDINT_H_

#include <machine/types.h>

/* from ISO/IEC 988:1999 spec */

/* 7.18.1.1 Exact-width integer types */
typedef i8              int8_t;
typedef i16             int16_t;
typedef i32             int32_t;

typedef u8              uint8_t;
typedef u16             uint16_t;
typedef u32             uint32_t;


/* 7.18.1.2 Minumun-width integer types */
typedef int8_t          int_least8_t;
typedef int16_t         int_least16_t;
typedef int32_t         int_least32_t;

typedef uint8_t         uint_least8_t;
typedef uint16_t        uint_least16_t;
typedef uint32_t        uint_least32_t;


/* 7.18.1.3 Fastest-width integer types */
typedef int8_t          int_fast8_t;
typedef int16_t         int_fast16_t;
typedef int32_t         int_fast32_t;

typedef uint8_t         uint_fast8_t;
typedef uint16_t        uint_fast16_t;
typedef uint32_t        uint_fast32_t;


/* 7.18.1.4 Integer types capable of hgolding object pointers */
typedef int16_t         intptr_t;
typedef uint16_t        uintptr_t;


/* 7.18.1.5 Greatest-width integer types */
typedef int16_t         intmax_t;
typedef uint16_t        uintmax_t;


/* 7.18.2 Limits of specified-width integer types:
 *   These #defines specify the minimum and maximum limits
 *   of each of the types declared above.
 */


/* 7.18.2.1 Limits of exact-width integer types */
#define INT8_MIN         (-127-1)
#define INT16_MIN        (-32767-1)
#define INT32_MIN        (-2147483647-1)

#define INT8_MAX         +127
#define INT16_MAX        +32767
#define INT32_MAX        +2147483647

#define UINT8_MAX         255
#define UINT16_MAX        65535
#define UINT32_MAX        4294967295U

/* 7.18.2.2 Limits of minimum-width integer types */
#define INT_LEAST8_MIN    INT8_MIN
#define INT_LEAST16_MIN   INT16_MIN
#define INT_LEAST32_MIN   INT32_MIN

#define INT_LEAST8_MAX    INT8_MAX
#define INT_LEAST16_MAX   INT16_MAX
#define INT_LEAST32_MAX   INT32_MAX

#define UINT_LEAST8_MAX   UINT8_MAX
#define UINT_LEAST16_MAX  UINT16_MAX
#define UINT_LEAST32_MAX  UINT32_MAX

/* 7.18.2.3 Limits of fastest minimum-width integer types */
#define INT_FAST8_MIN     INT8_MIN
#define INT_FAST16_MIN    INT16_MIN
#define INT_FAST32_MIN    INT32_MIN

#define INT_FAST8_MAX     INT8_MAX
#define INT_FAST16_MAX    INT16_MAX
#define INT_FAST32_MAX    INT32_MAX

#define UINT_FAST8_MAX    UINT8_MAX
#define UINT_FAST16_MAX   UINT16_MAX
#define UINT_FAST32_MAX   UINT32_MAX

/* 7.18.2.4 Limits of integer types capable of holding object pointers */
#define INTPTR_MIN        INT16_MIN
#define INTPTR_MAX        INT16_MAX
#define UINTPTR_MAX       UINT16_MAX

/* 7.18.2.5 Limits of greatest-width integer types */
#define INTMAX_MIN        INT16_MIN
#define INTMAX_MAX        INT16_MAX

#define UINTMAX_MAX       UINT16_MAX

/* 7.18.3 "Other" */
#define PTRDIFF_MIN       INT16_MIN
#define PTRDIFF_MAX       INT16_MAX

#define SIZE_MAX          UINT16_MAX

#define WCHAR_MAX         INT16_MAX


/* 7.18.4 Macros for integer constants */
#define INT8_C(v)    ((int8_t)v)
#define INT16_C(v)   ((int16_t)v)
#define INT32_C(v)   (v ## L)

#define UINT8_C(v)   ((uint8_t)v)
#define UINT16_C(v)  ((uint16_t)v)
#define UINT32_C(v)  (v ## UL)

#define INTMAX_C(v)  (INT16_C(v))
#define UINTMAX_C(v) (UINT16_C(v))


#endif /* _STDINT_H_ */
