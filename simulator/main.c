#include <stdio.h>
#include <stdlib.h>

unsigned int getNthIns(int n, FILE *f){
fpos_t pos = n*4;
unsigned int a;
fsetpos (f, &pos);
fread (&a, 4, 1, f);
return (a&0x000000ff)<<24|(a&0x0000ff00)<<8|(a&0x00ff0000)>>8|(a&0xff000000)>>24;
}

int main(){
FILE* f1 =  fopen ("iimage.bin", "r");
FILE* f2 =  fopen ("dimage.bin", "r");
printf("%x", getNthIns (2, f1));
return 0;
}
