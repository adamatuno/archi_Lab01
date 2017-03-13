#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

long long itl(int a){
    long long b = a;
    return b;
}

int nof(long long a){ ///not overflow
    long long max = 2147483647, min = -2147483647;
    if(a <= max && a >= min) return 1;
    return 0;
}

void Rti(unsigned int func, unsigned int s, unsigned int t, unsigned int d, unsigned int C){
    long long t1, t2, temp;
    int sign, n;
    switch(func){
    case 0x20:///add
        temp = itl(r[s]) + itl(r[t]);
        if(nof(temp)) r[d] = r[s] + r[t];
        else //error
        break;
    case 0x21:///addu
        r[d] = r[s] + r[t];
        break;
    case 0x22:///sub
        temp = itl(r[s]) - itl(r[t]);
        if(nof(temp)) r[d] = r[s] - r[t];
        else //error
        break;
    case 0x24:///and
        r[d] = r[s] & r[t];
        break;
    case 0x25://or
        r[d] = r[s] | r[t];
        break;
    case 0x26://xor
        r[d] = r[s] ^ r[t];
        break;
    case 0x27://nor
        r[d] = ~(r[s] | r[t]);
        break;
    case 0x28://nand
        r[d] = ~(r[s] & r[t]);
        break;
    case 0x2a://slt
        r[d] = r[s] < r[t];
        break;
    case 0x00://sll
        r[d] = r[t] << C;
        break;
    case 0x02://srl
        r[d] = r[t] >> C;
        break;
    case 0x03://sra
        n = C;
        sign = (r[t] > 0) ? 0x00000000 : 0x10000000;
        while(n--) r[d] = (r[t] >> 1) | sign;
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
        r[d] = Hi;
        break;
    case 0x12://mflo
        r[d] = Lo;
        break;
    default: ///wrong
    break;
    }

}