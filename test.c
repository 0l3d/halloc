#include "halloc.h"
#include <stdio.h>

int main() {
  int heap_size = 100;
  int *heap = halloc(sizeof(int) * heap_size);

  for (int i = 0; i < heap_size; i++) {
    heap[i] = i;
    printf("%d\n", heap[i]);
  }

  hfree(heap);
}
