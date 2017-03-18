#include <stdio.h>
#include <stdlib.h>


fpos_t pos;
int r[32], rl[32], Cycle, err_overwrite_HiLo;
unsigned int Hi, Hil, Lo, Lol, PC, PCin, PCl, sp, D[1024], I[1024], iin, din, halt;
FILE *ii, *di, *sn, *err;
