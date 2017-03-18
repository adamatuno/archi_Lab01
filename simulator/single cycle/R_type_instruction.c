#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"


void Rti(unsigned int func, unsigned int s, unsigned int t, unsigned int d, unsigned int C){
    long long t1, t2, temp;
    unsigned int sign;
    int n;
    switch(func){
    case 0x20:///add
        if(write_0(d)) break;
        temp = itl(r[s]) + itl(r[t]);
        if(nof(temp)) r[d] = r[s] + r[t];
        else //error
        break;
    case 0x21:///addu
        if(write_0(d)) break;
        r[d] = r[s] + r[t];
        break;
    case 0x22:///sub
        if(write_0(d)) break;
        temp = itl(r[s]) - itl(r[t]);
        if(nof(temp)) r[d] = r[s] - r[t];
        else //error
        break;
    case 0x24://and
        if(write_0(d)) break;
        r[d] = r[s] & r[t];
        break;
    case 0x25://or
        if(write_0(d)) break;
        r[d] = r[s] | r[t];
        break;
    case 0x26://xor
        if(write_0(d)) break;
        r[d] = r[s] ^ r[t];
        break;
    case 0x27://nor
        if(write_0(d)) break;
        r[d] = ~(r[s] | r[t]);
        break;
    case 0x28://nand
        if(write_0(d)) break;
        r[d] = ~(r[s] & r[t]);
        break;
    case 0x2a://slt
        if(write_0(d)) break;
        r[d] = r[s] < r[t];
        break;
    case 0x00://sll
        r[d] = r[t] << C;
        break;
    case 0x02://srl
        if(write_0(d)) break;
        r[d] = r[t] >> C;
        break;
    case 0x03://sra
        if(write_0(d)) break;
        n = C;
        sign = (r[t] > 0) ? 0x00000000 : 0x80000000;
        while(n--) r[d] = (r[t] >> 1) | sign;
        break;
    case 0x08://jr
        PC = r[s];
        break;
    case 0x18:///mult
        t1 = r[s];
        t2 = r[t];
        Hi = t1 * t2 >> 32;
        Lo = t1 * t2 & 0x00000000ffffffff;
        break;
    case 0x19:///multu
        t1 = r[s];
        t2 = r[t];
        Hi = t1 * t2 >> 32;
        Lo = t1 * t2 & 0x00000000ffffffff;
        break;
    case 0x10://mfhi
        if(write_0(d)) break;
        r[d] = Hi;
        break;
    case 0x12://mflo
        if(write_0(d)) break;
        r[d] = Lo;
        break;
    default: ///wrong
    break;
    }

}
