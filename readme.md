# FastMath

Uses (multiarch/crossbuild)[https://hub.docker.com/r/multiarch/crossbuild/] docker image to cross-compile. Also can use mingw to easily cross-compile to windows.

## Second-pass results

Learned that `SuppressUnmanagedCodeSecurityAttribute` adds huge performance benefits on windows.

Learned that the process of fixing memory to pass via `ref` is slower on windows than with mono. Changing
to use pointers added huge gains on windows.

## First-Pass Results

10m matrix multiplications

### Linux

300ms for C11 restricted pointers
500ms for c99 pointers
1000ms under mono

### Windows (VM)
440 ms windows .NET
640 for c11

### OSX (x86_64 VM w/ Mono 3.4 x86)

600 ms for .NET
300 ms for dylib (32 bit)
