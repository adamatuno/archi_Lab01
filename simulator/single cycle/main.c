#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

unsigned int getN(int n, FILE *f) {
    fpos_t pos = n*4;
    unsigned int a;
    fsetpos (f, &pos);
    fread (&a, 4, 1, f);
    return (a&0x000000ff)<<24|(a&0x0000ff00)<<8|(a&0x00ff0000)>>8|(a&0xff000000)>>24;
}

void init() {
    FILE* ii = fopen("iimage.bin", "r");
    FILE* di = fopen("dimage.bin", "r");
    FILE* sn = fopen("snaptshot.rpt", "w");
    FILE* err = fopen("error_dump.rpt", "w");
    int i;
    for(i = 0; i < 32; ++i) r[i] = 0x00000000;
    for(i = 0; i < 256; ++i) I[i] = D[i] = 0x00000000;
    HI = 0x0000000;
    LO = 0x0000000;
    PC = getN(0, ii);
    num_i = getN(4, ii);
    num_d = getN(4, di);


}

int main(){
    unsigned int code;
    init();
    code = getN(2, ii);
    switch(type(get_op(code))){
        R: break;
        J: break;
        S: break;
        default: break;
    }
    //test
    int a, b, qq;
    unsigned int t1, t2, c, t;
    a = -1;
    b = 1;
    t1 = a;
    t2 = b;
    c = t1 + t2;
    qq = (unsigned int)a < (unsigned int)b;
    printf("%u, %d", qq, qq);
    //test
return 0;
}
