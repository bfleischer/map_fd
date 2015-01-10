//
//  map_fd.h
//  map_fd
//
//  Created by Benjamin Fleischer on 10.01.15.
//  Copyright (c) 2015 Benjamin Fleischer. All rights reserved.
//

#ifndef __map_fd__map_fd__
#define __map_fd__map_fd__

#include <mach/kern_return.h>
#include <mach/vm_types.h>

kern_return_t map_fd(int          fd,
                     vm_offset_t  offset,
                     vm_offset_t *va,
                     boolean_t    findspace,
                     vm_size_t    size);

#endif /* defined(__map_fd__map_fd__) */
