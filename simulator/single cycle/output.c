#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

void snap(int cycle){
    int i;
    printf("cycle %d", cycle);
    if(0 == cycle){
        for(i = 0; i< 32; ++i) printf("$%02d: 0x00000000", i);
        printf("$HI: 0x00000000\n$LO: 0x00000000\nPC: 0x%08x", PC);
    }
}
