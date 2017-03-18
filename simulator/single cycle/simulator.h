#include <stdio.h>
#include <stdlib.h>

int r[32], rl[32], Cycle;
unsigned int Hi, Lo, PC, sp, D[1024], I[1024], iin, din, halt;
FILE *ii, *di, *sn, *err;
