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
    sn = fopen("snaptshot.rpt", "w");
    err = fopen("error_dump.rpt", "w");

    PC = readfile(1, ii) / 4;
    iin = readfile(0, ii);
    for(i = 0; i < iin; ++i) I[i] = readfile(0, ii);

    sp = readfile(1, di);
    din = readfile(0, di);
    for(i = 0; i < 1024; ++i) {
        if(i < din) D[i] = readfile(0, di);
        else D[i] =0x00000000;
    }
    for(i = 0; i < 32; ++i) r[i] = 0x00000000;
    Hi = 0x00000000;
    Lo = 0x00000000;
}

int main(){
    unsigned int code;
    Cycle = 0;
    init();
    while(!halt){
    switch(type(get_op(code))){
        case R:
            Rti(getfunc(code), get_rs(code), get_rt(code), get_rd(code), get_sha(code));
            break;
        case J:
        case S:
            JSti(get_op(code), get_addr(code));
            break;
        default:
            Iti(get_op(code), get_rs(code), get_rt(code), get_imm(code));
            break;
    }
    snap(Cycle);

    PC++;
    Cycle++;
    }
    //test
    int a, b, qq, i;
    unsigned int t1, t2, c, t;
    //test
return 0;
}
