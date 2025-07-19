#include <stddef.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

typedef struct block {
  int free;
  size_t size;
  struct block *next;
  struct block *prev;
} block;

void *halloc(size_t addr);
void *zalloc(size_t n, size_t size);
void hfree(void *ptr);
