//
//  map_fd.c
//  map_fd
//
//  Created by Benjamin Fleischer on 10.01.15.
//  Copyright (c) 2015 Benjamin Fleischer. All rights reserved.
//

#include "map_fd.h"

#include <sys/mman.h>
#include <stdio.h>

kern_return_t map_fd(int          fd,
                     vm_offset_t  offset,
                     vm_offset_t *va,
                     boolean_t    findspace,
                     vm_size_t    size)
{
    void *result = NULL;

    result = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, offset);
    
    if (result == MAP_FAILED) {
        return KERN_FAILURE;
    } else {
        *va = (uintptr_t)result;
        return KERN_SUCCESS;
    }
}