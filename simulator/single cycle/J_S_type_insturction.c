#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"
void JSti(unsigned int op, unsigned C){
    switch(op){
    case 0x02://j
        PC = (((PC + 1) << 2) & 0x000000f) | (C << 2);
        break;
    case 0x03://jal
        r[31] = (PC + 1) << 2;
        PC = (((PC + 1) << 2) & 0x000000f) | (C << 2);
        break;
    case 0x3f://halt
        halt = 1;
        break;
    default:
        break;
    }
}
