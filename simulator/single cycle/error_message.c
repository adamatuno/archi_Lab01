#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

int write_0(unsigned int r){
    if(r == 0){
        fprintf(di, "In cycle %d: Write $0 Error\n", Cycle);
        return 1;
    }
    else return 0;
}

long long itl(int a){
    long long b = a;
    return b;
}

void Number_overflow(int a, int b, int c){/**c=1 add, c=0 multi **/
    long long A = a, B = b;
    if(c && ((a > 0 && b > 0 && a + b < 0) || (a < 0 && b < 0 && a + b > 0)))
    fprintf(di, "In cycle %d: Number Overflow\n", Cycle);
    if(!c && ((a * b < 0 && A * B > 0) || (a * b > 0 && A * B < 0)))
    fprintf(di, "In cycle %d: Number Overflow\n", Cycle);
}
