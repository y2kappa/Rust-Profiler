#ifndef LIBMEM_C_H_
#define LIBMEM_C_H_

#ifdef __cplusplus
extern "C" {
#endif

#include<stddef.h>

size_t getPeakRSS();
size_t getCurrentRSS();

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  /* LIBMEM_C_H_ */