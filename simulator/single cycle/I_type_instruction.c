#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"
void Iti(unsigned int op, unsigned int s, unsigned int t, int C){
    long long temp;
    switch(op){
    case 0x08://addi
        temp = itl(r[s]) + itl(C);
        if(nof(temp)) r[t] = r[s] + C;
        break;
    case 0x09://addiu
        r[t] = r[s] + C;
        break;
    case 0x23://lw
        r[t] = D[r[s] + C/4];
        break;
    case 0x21://lh
        break;
    case 0x25://lhu
        break;
    case 0x20://lb
        break;
    case 0x24://lbu
        break;
    case 0x2b://sw
        break;
    case 0x29://sh
        break;
    case 0x28://sb
        break;
    case 0x0f://lui
        r[t] = C << 16;
        break;
    case 0x0c://andi
        r[t] = r[s] & C;
    case 0x0d://ori
        r[t] = r[s] | C;
        break;
    case 0x0e://nori
        r[t] = ~(r[s] | C);
        break;
    case 0x0a://slti
        r[t] = r[s] < C;
    case 0x04://beq
        break;
    case 0x05://bne
        break;
    case 0x07://bgtz
        break;
    default: //wrong
    break;
    }
}
