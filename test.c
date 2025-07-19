#include "halloc.h"
#include <stdio.h>

int main() {
  int heap_size = 100;
  int *heap = halloc(sizeof(int) * heap_size);

  for (int i = 0; i < heap_size; i++) {
    heap[i] = i;
    printf("%d\n", heap[i]);
  }

  int *zero = zalloc(5, sizeof(int));
  for (int i = 0; i < 5; i++)
    printf("%d ", zero[i]);

  heap = ralloc(heap, sizeof(int) * 200);
  for (int i = heap_size; i < 200; i++) {
    heap[i] = i;
    printf("%d\n", heap[i]);
  }

  hfree(zero);
  hfree(heap);
}
