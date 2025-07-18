#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

typedef struct block {
  int free;
  size_t size;
  struct block *next;
} block;

void *halloc(size_t addr);
void hfree(void *ptr);
