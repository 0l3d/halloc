# HALLOC

halloc is simple malloc for C.

## How it works?

First of all, we start with certain questions. For memory allocation, we need to check whether the memory is free, as well as keep track of the size and value of the memory. By utilizing concepts like pointer arithmetic, we actually perform memory allocation using the sbrk system call, and since we use system calls, we do this in an optimized and organized manner. Later, we return head + 1, which is not the structure of the allocated memory but the pointer value. When freeing memory, which means we roughly return to the structure value by doing head - 1 and mark that structure as free by setting free = 1, indicating that it has been deallocated.

## Author

Created By _0l3d_
