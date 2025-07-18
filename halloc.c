#include "halloc.h"
block *head = NULL;

void *halloc(size_t alsiz) {
  if (head == NULL) {
    head = (block *)sbrk(sizeof(block) + alsiz);
    if (head == (void *)-1)
      return NULL;
    head->size = alsiz;
    head->free = 0;
    head->next = NULL;
    return (void *)(head + 1);
  }

  block *current = head;
  while (current != NULL) {

    if (current->free == 1 && current->size >= alsiz) {
      current->free = 0;
      return (void *)(current + 1);
    }

    current = current->next;
  }

  current = (block *)sbrk(sizeof(block) + alsiz);
  if (current == (void *)-1)
    return NULL;
  current->size = alsiz;
  current->free = 0;
  current->next = NULL;
  return (void *)(current + 1);
}

void hfree(void *addr) {
  if (addr == NULL)
    return;
  block *fr = (block *)addr - 1;
  fr->free = 1;
}
