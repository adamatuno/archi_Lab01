#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"
void Iti(unsigned int op, unsigned int s, unsigned int t, int C){
    long long temp;
    unsigned int a, b, c, d, Cu = C;
    switch(op){
    case 0x08://addi
        write_0(t);
        number_overflow(r[s], C, 1);
        r[t] = r[s] + C;
        r[0] = 0;
        break;
    case 0x09://addiu
        write_0(t);
        r[t] = r[s] + C;
        r[0] = 0;
        break;
    case 0x23://lw
        write_0(t);
        number_overflow(r[s], C, 1);
        mem_overflow(r[s] + C, 3);
        data_misaligned(C, 1);
        a = D[r[s] + C];
        b = D[r[s] + C + 1];
        c = D[r[s] + C + 2];
        d = D[r[s] + C + 3];
        r[t] = (a << 24) | (b << 16) | (c << 8) | d;
        r[0] = 0;
        break;
    case 0x21://lh
        write_0(t);
        number_overflow(r[s], C, 1);
        mem_overflow(r[s] + C, 1);
        data_misaligned(C, 0);
        a = D[r[s] + C];
        b = D[r[s] + C + 1];
        r[t] = ((a << 8) | b) & 0x0000ffff;
        r[0] = 0;
        break;
    case 0x25://lhu
        write_0(t);
        number_overflow(r[s], C, 1);
        mem_overflow(r[s] + C, 1);
        a = D[r[s] + C];
        b = D[r[s] + C + 1];
        if(b / 255) r[t] = (a << 8) | b | 0xffff0000;
        else r[t] = ((a << 8) | b) & 0x0000ffff;
        r[0] = 0;
        break;
    case 0x20://lb
        write_0(t);
        number_overflow(r[s], C, 1);
        mem_overflow(r[s] + C, 0);
        a = D[r[s] + C] & 0x000000ff;
        if(a / 255) r[t] = a | 0xffffff00;
        else r[t] = a;
        r[0] = 0;
        break;
    case 0x24://lbu
        write_0(t);
        number_overflow(r[s], C, 1);
        mem_overflow(r[s] + C, 0);
        r[t] = D[r[s] + C] & 0x000000ff;
        r[0] = 0;
        break;
    case 0x2b://sw
        number_overflow(r[s], C, 1);
        mem_overflow(r[s] + C, 3);
        data_misaligned(C, 1);
        D[r[s] + C] = r[t] >> 24;
        D[r[s] + C + 1] = (r[t] >> 16) & 0x000000ff;
        D[r[s] + C + 2] = (r[t] >> 8) & 0x000000ff;
        D[r[s] + C + 3] = r[t] & 0x000000ff;
        break;
    case 0x29://sh
        number_overflow(r[s], C, 1);
        mem_overflow(r[s] + C, 1);
        data_misaligned(C, 0);
        D[r[s] + C] = (r[t] >> 8) & 0x000000ff;
        D[r[s] + C + 1] = r[t] & 0x000000ff;
        break;
    case 0x28://sb
        number_overflow(r[s], C, 0);
        mem_overflow(r[s] + C, 1);
        D[r[s] + C] = r[t] & 0x000000ff;
        break;
    case 0x0f:///lui
        write_0(t);
        r[t] = Cu << 16;
        r[0] = 0;
        break;
    case 0x0c:///andi
        write_0(t);
        a = r[s];
        r[t] = a & Cu;
        r[0] = 0;
        break;
    case 0x0d:///ori
        write_0(t);
        a = r[s];
        r[t] = a | Cu;
        r[0] = 0;
        break;
    case 0x0e:///nori
        write_0(t);
        a = r[s];
        r[t] = ~(a | C);
        r[0] = 0;
        break;
    case 0x0a://slti
        write_0(t);
        r[t] = r[s] < C;
        r[0] = 0;
        break;
    case 0x04://beq
        number_overflow(PC*4, 4*C+4, 1);
        if(r[s] == r[t]) PC = PC + C;
        break;
    case 0x05://bne
        number_overflow(PC*4, 4*C+4, 1);
        if(r[s] != r[t]) PC = PC + C;
        break;
    case 0x07://bgtz
        number_overflow(PC*4, 4*C+4, 1);
        if(r[s] > 0) PC = PC + C;
        break;
    default: //wrong
        break;
    }
}
