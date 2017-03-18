#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"
void Iti(unsigned int op, unsigned int s, unsigned int t, int C){
    long long temp;
    unsigned int a,b,c,d;
    switch(op){
    case 0x08://addi
        if(write_0(t)) break;
        temp = itl(r[s]) + itl(C);
        if(nof(temp)) r[t] = r[s] + C;
        break;
    case 0x09://addiu
        if(write_0(t)) break;
        r[t] = r[s] + C;
        break;
    case 0x23://lw
        if(write_0(t)) break;
        a = D[r[s] + C];
        b = D[r[s] + C + 1];
        c = D[r[s] + C + 2];
        d = D[r[s] + C + 3];
        r[t] = (a << 24) | (b << 16) | (c << 8) | d;
        break;
    case 0x21://lh
        if(write_0(t)) break;
        a = D[r[s] + C];
        b = D[r[s] + C + 1];
        r[t] = ((a << 8) | b) & 0x0000ffff;
        break;
    case 0x25://lhu
        if(write_0(t)) break;
        a = D[r[s] + C];
        b = D[r[s] + C + 1];
        if(b / 255) r[t] = (a << 8) | b | 0xffff0000;
        else r[t] = ((a << 8) | b) & 0x0000ffff;
        break;
    case 0x20://lb
        if(write_0(t)) break;
        a = D[r[s] + C] & 0x000000ff;
        if(a / 255) r[t] = a | 0xffffff00;
        else r[t] = a;
        break;
    case 0x24://lbu
        if(write_0(t)) break;
        r[t] = D[r[s] + C] & 0x000000ff;
        break;
    case 0x2b://sw
        D[r[s] + C] = r[t] >> 24;
        D[r[s] + C + 1] = (r[t] >> 16) & 0x000000ff;
        D[r[s] + C + 2] = (r[t] >> 8) & 0x000000ff;
        D[r[s] + C + 3] = r[t] & 0x000000ff
        break;
    case 0x29://sh
        D[r[s] + C] = (r[t] >> 8) & 0x000000ff;
        D[r[s] + C + 1] = r[t] & 0x000000ff;
        break;
    case 0x28://sb
        D[r[s] + C] = r[t] & 0x000000ff;
        break;
    case 0x0f://lui
        if(write_0(t)) break;
        r[t] = C << 16;
        break;
    case 0x0c://andi
        if(write_0(t)) break;
        r[t] = r[s] & C;
    case 0x0d://ori
        if(write_0(t)) break;
        r[t] = r[s] | C;
        break;
    case 0x0e://nori
        if(write_0(t)) break;
        r[t] = ~(r[s] | C);
        break;
    case 0x0a://slti
        if(write_0(t)) break;
        r[t] = r[s] < C;
    case 0x04://beq
        if(r[s] == r[t]) PC = PC + 1 + C;
        break;
    case 0x05://bne
        if(r[s] != r[t]) PC = PC + 1 + C;
        break;
    case 0x07://bgtz
        if(r[s] > 0) PC = PC + 1 + C;
        break;
    default: //wrong
    break;
    }
}
