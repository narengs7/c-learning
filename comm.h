#ifndef _COMMON_FUNC_
#define _COMMON_FUNC_
#include <stdint.h>

#ifndef DATA_TYPE_USED 
#define DATA_TYPE_USED int32_t
#endif

typedef struct __result__ OprResult;

struct __result__{
	DATA_TYPE_USED data;
	uint32_t status;
};

#endif