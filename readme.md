# FastMath

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