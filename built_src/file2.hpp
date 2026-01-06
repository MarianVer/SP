#define _CRT_SECURE_NO_WARNINGS

#define SYMBOL_NUMBER 256
#define MAX_STATES 1024
#define MAX_FINIT_STATES 1024

#define Q000 0
#define Q_FIN 1
#define Q_ER 2

int transitionTable2[SYMBOL_NUMBER][MAX_STATES];

void init_file2() {
    // Заглушка: Нічого не розпізнає
    for(int i=0; i<SYMBOL_NUMBER; i++) 
        for(int j=0; j<MAX_STATES; j++) 
            transitionTable2[i][j] = Q_ER;
}

struct InitFile2 { InitFile2(){ init_file2(); } } initFile2_obj;
