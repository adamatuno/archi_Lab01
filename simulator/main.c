#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

unsigned int readfile(FILE *f) {
    unsigned int a;
    fread(&a, 4, 1, f);
    return (a&0x000000ff)<<24|(a&0x0000ff00)<<8|(a&0x00ff0000)>>8|(a&0xff000000)>>24;
}

void init() {
    int i;
    unsigned int word;
    halt = 0;
    ii = fopen("iimage.bin", "rb");
    di = fopen("dimage.bin", "rb");
    sn = fopen("snapshot.rpt", "wb");
    err = fopen("error_dump.rpt", "wb");

    err_overwrite_HiLo = 0;
    PCin = PC = readfile(ii) / 4;
    PCl = PC;
    iin = readfile(ii);
    for(i = 0; i < 256; ++i) {
        if(i < PCin + iin && i >= PCin) I[i] = readfile(ii);
        else I[i] = 0x00000000;
    }
    r[29] = rl[29] = spin = readfile(di);
    din = readfile(di);
    for(i = 0; i < din * 4; i += 4) {
        word = readfile(di);
        D[i] = word >> 24;
        D[i + 1] = (word >> 16) & 0x000000ff;
        D[i + 2] = (word >> 8) & 0x000000ff;
        D[i + 3] = word & 0x000000ff;
    }
    for(i = din * 4; i < 1024; ++i) D[i] = 0x00000000;
    for(i = 0; i < 32; ++i) if(i != 29) r[i] = rl[i] = 0x00000000;
    Hi = Hil = 0x00000000;
    Lo = Lol = 0x00000000;
}

int main(){
    int i;
    unsigned int code;
    Cycle = 1;
    init();
    cycle_0();
    while(!halt && Cycle <= 500000) {
    code = I[PC];
    PC++;
    if((code & 0xfc0fffff) != 0x00000000) switch(type(get_op(code))) {
        case 'R':
            Rti(get_func(code), get_rs(code), get_rt(code), get_rd(code), get_sha(code));
            break;
        case 'J':
            JSti(get_op(code), get_addr(code));
            break;
        default:
            Iti(get_op(code), get_rs(code), get_rt(code), get_imm(code));
            break;
    }
    if(!halt) snap(Cycle);
    ++Cycle;
    }
return 0;
}
