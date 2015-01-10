map_fd
======

Xcode 3.2.6 is the last version of Xcode that supports building kernel extension for Mac OS X 10.4 and 10.5. However, running Xcode 3.2.6 on Mac OS X versions greater than 10.6 is unsupported and requires some tweaking.

Trying to build legacy kernel extension with Xcode 3.2.6 on OS X 10.10 will throw the following error:

    dyld: lazy symbol binding failed: Symbol not found: _map_fd
      Referenced from: /Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/ld_classic
      Expected in: /usr/lib/libSystem.B.dylib

The `ld_classic` tool included in Xcode 3.2.6 is based on the deprecated `map_fd` syscall, that is no longer available on OS X 10.10.

This project's `libmap_fd.dylib` addresses the issue by providing a custom implementation of the `map_fd` syscall based on `mmap`, that is compatible with `ld_classic`. For it to work `libmap_fd.dylib` needs to be injected into `ld_classic`. This can be accomplished by setting the following environment variables before invoking `ld_classic`:

    DYLD_FORCE_FLAT_NAMESPACE=1
    DYLD_INSERT_LIBRARIES="/path/to/libmap_fd.dylib"

The injection process can be automated by replacing the `ld_classic` binary with as shell script that sets the above environment variables and calls the original `ld_classic` tool. See the included `ld_classic` shell script.
