#include <stdio.h>
int main(){
int r[32], d[1024];
FILE* f1 =  fopen("iimage.bin","r");
FILE* f2 =  fopen("dimage.bin","r");
fpos_t pos = 8;
unsigned int a;
//while(!feof(f1)){
fsetpos (f1, &pos);
fread (&a, sizeof(int), 1, f1);
unsigned int b0,b1,b2,b3;
b0 = (a & 0x000000ff) << 24;
b1 = (a & 0x0000ff00) << 8;
b2 = (a & 0x00ff0000) >> 8;
b3 = (a & 0xff000000) >> 24;
a = b0 | b1 | b2 | b3;
printf ("%08x %d\n", a, pos);
//}
return 0;
}
