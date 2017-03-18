#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"
void cycle_0() {
    int i;
    fprintf(sn, "cycle 0\n");
    for(i = 0; i < 32; ++i) fprintf(sn, "$%02d: 0x00000000\n", i);
    fprintf(sn, "$HI: 0x00000000\n$LO: 0x00000000\nPC: 0x%08X\n\n\n", PC * 4);
}

void snap(int cycle) {
    int i;
    fprintf(sn, "cycle %d\n", cycle);
    for(i = 0; i < 32; ++i) {
        if(r[i] != rl[i]) {
            fprintf(sn, "$%02d: 0x%08X\n",i , r[i]);
            rl[i] = r[i];
        }
    }
    if(Hi != Hil) {
        fprintf(sn, "$HI: 0x%08X\n", Hi);
        Hil = Hi;
    }
    if(Lo != Lol) {
        fprintf(sn, "$LO: 0x%08X\n", Lo);
        Lol = Lo;
    }
    if(PC != PCl) {
        fprintf(sn, "PC: 0x%08X\n", PC * 4);
        PCl = PC;
    }
    fprintf(sn, "\n\n");
}
