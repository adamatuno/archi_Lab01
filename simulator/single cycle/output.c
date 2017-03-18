#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

void snap(int cycle) {
    int i;
    fprintf(sn, "cycle %d\n", cycle);
    if(0 == cycle) {
        for(i = 0; i < 32; ++i) fprintf(sn, "$%02d: 0x00000000\n", i);
        fprintf(sn, "$HI: 0x00000000\n$LO: 0x00000000\nPC: 0x%08x", PC * 4);
    }
    for(i = 0; i < 32; ++i) {
        if(r[i] != rl[i]) {
            fprintf(sn, "$%02d: 0x%08x\n", r[i]);
            rl[i] = r[i];
        }
    }
    if(Hi != Hil) {
        fprintf(sn, "$HI: 0x%08x\n", Hi);
        Hil = Hi;
    }
    if(Lo != Lol) {
        fprintf(sn, "$LO: 0x%08x\n", Lo);
        Lol = Lo;
    }
    if(PC != PCl) {
        fprintf(sn, "PC: 0x%08x\n", PC * 4);
        PCl = PC;
    }
    fprintf(sn, "\n\n");
}
