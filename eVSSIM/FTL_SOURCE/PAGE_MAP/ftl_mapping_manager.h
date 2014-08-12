// Copyright(c)2013 
//
// Hanyang University, Seoul, Korea
// Embedded Software Systems Lab. All right reserved

#ifndef _MAPPING_MANAGER_H_
#define _MAPPING_MANAGER_H_

extern int32_t* mapping_table;
extern void* block_table_start;

extern unsigned int flash_index;
extern unsigned int* plane_index;
extern unsigned int* block_index;

void INIT_MAPPING_TABLE(void);
void TERM_MAPPING_TABLE(void);

int32_t GET_MAPPING_INFO(int32_t lpn);
int GET_NEW_PAGE(int mode, int mapping_index, int32_t* ppn);

int UPDATE_OLD_PAGE_MAPPING(int32_t lpn);
int UPDATE_NEW_PAGE_MAPPING(int32_t lpn, int32_t ppn);

unsigned int CALC_FLASH(int32_t ppn);
unsigned int CALC_BLOCK(int32_t ppn);
unsigned int CALC_PAGE(int32_t ppn);
unsigned int CALC_PLANE(int32_t ppn);
unsigned int CALC_CHANNEL(int32_t ppn);
unsigned int CALC_SCOPE_FIRST_PAGE(int32_t address, int scope);

#endif
