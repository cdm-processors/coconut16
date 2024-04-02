#ifndef _STDDEF_H_
#define _STDDEF_H_

#include <machine/types.h>

typedef i16     ptrdiff_t;
#ifndef __cplusplus
typedef u16     wchar_t;
#endif /* !__cplusplus */
typedef usize   size_t;

#define NULL    ((void*)0)

#define offsetof(type, member) ((size_t)&(((type*)0)->member))

#endif /* _STDDEF_H_ */
