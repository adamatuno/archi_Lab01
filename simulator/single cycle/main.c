#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

unsigned int readfile(int rst, FILE *f) {
    fpos_t pos;
    if(rst) pos = 0;
    unsigned int a;
    fsetpos(f, &pos);
    fread(&a, 4, 1, f);
    pos += 4;
    return (a&0x000000ff)<<24|(a&0x0000ff00)<<8|(a&0x00ff0000)>>8|(a&0xff000000)>>24;
}

void init() {
    int i;
    halt = 0;
    ii = fopen("iimage.bin", "r");
    di = fopen("dimage.bin", "r");
    sn = fopen("sn.rpt", "w");
    err = fopen("err.rpt", "w");

    err_overwrite_HiLo = 0;
    PC = readfile(1, ii) / 4;
    PCl = PC;
    iin = readfile(0, ii);
    for(i = 0; i < iin; ++i) I[i] = readfile(0, ii);

    sp = readfile(1, di);
    din = readfile(0, di);
    for(i = 0; i < 1024; ++i) {
        if(i < din) D[i] = readfile(0, di);
        else D[i] =0x00000000;
    }
    for(i = 0; i < 32; ++i) r[i] = rl[i] = 0x00000000;
    Hi = 0x00000000;
    Lo = 0x00000000;
}

int main(){
    unsigned int code;
    Cycle = 0;
    init();
    while(!halt && Cycle < 500000) {
    switch(type(get_op(code))) {
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
    PC++;
    Cycle++;
    }
return 0;
}
