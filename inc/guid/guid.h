#ifndef _GUID_H_
#define _GUID_H_

#define MAX_GUID_TYPE_COUNT     (256)

BOOL guid_init(int32_t nUniqID, int32_t nShmType, BOOL bResume);
BOOL guid_uninit(void);
uint64_t guid_alloc(int32_t nType);

#endif