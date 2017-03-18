#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"


void Rti(unsigned int func, unsigned int s, unsigned int t, unsigned int d, unsigned int C){
    long long t1, t2, temp;
    unsigned long long ull;
    unsigned int sign;
    int n;
    switch(func){
    case 0x20:///add
        write_0(d);
        number_overflow(r[s], r[t], 1);
        r[d] = r[s] + r[t];
        r[0] = 0;
        break;
    case 0x21:///addu
        write_0(d);
        r[d] = r[s] + r[t];
        r[0] = 0;
        break;
    case 0x22:///sub
        write_0(d);
        number_overflow(r[s], -r[t], 1);
        r[d] = r[s] - r[t];
        r[0] = 0;
        break;
    case 0x24://and
        write_0(d);
        r[d] = r[s] & r[t];
        r[0] = 0;
        break;
    case 0x25://or
        write_0(d);
        r[d] = r[s] | r[t];
        r[0] = 0;
        break;
    case 0x26://xor
        write_0(d);
        r[d] = r[s] ^ r[t];
        r[0] = 0;
        break;
    case 0x27://nor
        write_0(d);
        r[d] = ~(r[s] | r[t]);
        r[0] = 0;
        break;
    case 0x28://nand
        write_0(d);
        r[d] = ~(r[s] & r[t]);
        r[0] = 0;
        break;
    case 0x2a://slt
        write_0(d);
        r[d] = r[s] < r[t];
        r[0] = 0;
        break;
    case 0x00://sll
        r[d] = r[t] << C;
        r[0] = 0;
        break;
    case 0x02://srl
        write_0(d);
        r[d] = r[t] >> C;
        r[0] = 0;
        break;
    case 0x03://sra
        write_0(d);
        n = C;
        sign = (r[t] > 0) ? 0x00000000 : 0x80000000;
        while(n--) r[d] = (r[t] >> 1) | sign;
        r[0] = 0;
        break;
    case 0x08://jr
        PC = r[s] / 4;
        break;
    case 0x18:///mult
        overwrite_HiLo(0);
        number_overflow(r[s], r[t], 0);
        t1 = r[s];
        t2 = r[t];
        ull = t1 * t2;
        Hi = (int) (ull >> 32);
        Lo = (int) (ull & 0x00000000ffffffff);
        break;
    case 0x19:///multu
        overwrite_HiLo(0);
        t1 = r[s] & 0x00000000ffffffff;
        t2 = r[t] & 0x00000000ffffffff;
        ull = t1 * t2;
        Hi = (int) (ull >> 32);
        Lo = (int) (ull & 0x00000000ffffffff);
        break;
    case 0x10://mfhi
        write_0(d);
        overwrite_HiLo(1);
        r[d] = Hi;
        r[0] = 0;
        break;
    case 0x12://mflo
        write_0(d);
        overwrite_HiLo(1);
        r[d] = Lo;
        r[0] = 0;
        break;
    default: ///wrong
        break;
    }

}
