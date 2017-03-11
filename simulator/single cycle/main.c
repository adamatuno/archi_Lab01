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
    FILE* f1 = fopen ("iimage.bin", "r");
    FILE* f2 = fopen ("dimage.bin", "r");
    init();
    printf("%c %d", I[3], r[4]);
return 0;
}
