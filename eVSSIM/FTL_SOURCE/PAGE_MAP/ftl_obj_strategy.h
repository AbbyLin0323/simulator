#ifndef _FTL_OBJ_H_
#define _FTL_OBJ_H_

#include <stdlib.h>
#include "common.h"
#include "uthash.h"

typedef int32_t object_id_t;

/* A page node in the linked list of object-mapped pages */
typedef struct page_node {
    int32_t page_id;
    object_id_t object_id;
    struct page_node *next;
} page_node;

/* The object struct. Metadata will be added as a pointer to another struct or as more fields */
typedef struct stored_object {
    object_id_t id;
    size_t size;
    page_node *pages;
    UT_hash_handle hh; /* makes this structure hashable */
} stored_object;

/* FTL functions */
int _FTL_OBJ_READ(int32_t object_id, unsigned int offset, unsigned int length);
int _FTL_OBJ_WRITE(int32_t object_id, unsigned int offset, unsigned int length);
int _FTL_OBJ_COPYBACK(int32_t source, int32_t destination);
int _FTL_OBJ_CREATE(size_t size);
int _FTL_OBJ_DELETE(int32_t object_id);

/* Helper functions */
stored_object *lookup_object(object_id_t object_id);
stored_object *create_object(size_t size);
int remove_object(stored_object *object);

page_node *add_page_list(page_node *p, int32_t page_id);
page_node *add_page(stored_object *object, int32_t page_id);
page_node *page_by_offset(stored_object *object, unsigned int offset);
page_node *lookup_page(int32_t page_id);
page_node *next_page(stored_object *object,page_node *current);

#endif
