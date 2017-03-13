#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

unsigned int getNthIns(int n, FILE *f) {
    fpos_t pos = n*4;
    unsigned int a;
    fsetpos (f, &pos);
    fread (&a, 4, 1, f);
    return (a&0x000000ff)<<24|(a&0x0000ff00)<<8|(a&0x00ff0000)>>8|(a&0xff000000)>>24;
}

void init() {
    int i;
    for(i = 0; i < 32; ++i) r[i] = 0;
    for(i = 0; i < 1024; ++i) I[i] = D[i] = '0';
}

int main(){
    FILE* f1 = fopen("iimage.bin", "r");
    FILE* f2 = fopen("dimage.bin", "r");
    unsigned int code;
    init();
    code = getNthIns(2, f1);
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
    t = 4294967295;
    t1 = a;
    t2 = b;
    c = t1 + t2;
    qq = a == t;
    printf("%u, %d", qq, qq);
    //test
return 0;
}
