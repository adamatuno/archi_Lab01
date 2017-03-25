#include <stdio.h>
#include <stdlib.h>

fpos_t pos;
int r[32], rl[32], Cycle, err_overwrite_HiLo;
unsigned int Hi, Hil, Lo, Lol, PC, PCin, PCl, D[1024], I[256], iin, din, halt, spin;
FILE *ii, *di, *sn, *err;

unsigned int get_op(unsigned int i);
unsigned int get_rs(unsigned int i);
unsigned int get_rt(unsigned int i);
unsigned int get_rd(unsigned int i);
unsigned int get_sha(unsigned int i);
unsigned int get_func(unsigned int i);
int get_imm(unsigned int i);
int get_addr(unsigned int i);
char type(unsigned int op);
void write_0(unsigned int r);
long long itl(int a);
void number_overflow(int a, int b, int c);
void overwrite_HiLo(int rst);
void mem_overflow(int addr, int range);
void data_misaligned(int C, int type);
void Rti(unsigned int func, unsigned int s, unsigned int t, unsigned int d, unsigned int C);
void JSti(unsigned int op, unsigned C);
void Iti(unsigned int op, unsigned int s, unsigned int t, int C);
void cycle_0();
void snap(int cycle);
