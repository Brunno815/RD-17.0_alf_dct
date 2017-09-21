#include <stdio.h>
#include <stdlib.h>


#define EN_LAB 1
#define EN_ALF 1
#define EN_BUTTERFLY 1
#define LIMIT_ALF 100000
#define LIMIT_4 100000
#define LIMIT_8 100000
#define LIMIT_16 100000
#define LIMIT_32 100000

void openFiles();
void closeFiles();

extern FILE* files4[4];
extern FILE* files8[8];
extern FILE* files16[16];
extern FILE* files32[32];
extern FILE* files_alf[9];
extern FILE* files_alf_coeff[9];
extern int j;
extern int count[4];
extern int count_alf;
extern char inFile[1000];
extern int en_which;
extern int en_print_alf;