#define _CRT_SECURE_NO_WARNINGS

#define SYMBOL_NUMBER 256
#define MAX_STATES 1024
#define MAX_FINIT_STATES 1024

// Стани
#define Q000 0 // Старт
#define Q001 1 // Фінал (0 або число)
#define Q_ER 2 // Помилка

int transitionTable4[SYMBOL_NUMBER][MAX_STATES];

void init_file4() {
    // 1. Очищення
    for(int i=0; i<SYMBOL_NUMBER; i++) 
        for(int j=0; j<MAX_STATES; j++) 
            transitionTable4[i][j] = Q_ER;

    // 2. Нуль
    transitionTable4['0'][Q000] = Q001;

    // 3. Цифри 1-9
    for (int c = '1'; c <= '9'; c++) {
        transitionTable4[c][Q000] = Q001;
    }

    // 4. Продовження числа (будь-які цифри)
    for (int c = '0'; c <= '9'; c++) {
        transitionTable4[c][Q001] = Q001;
    }
}

struct InitFile4 { InitFile4(){ init_file4(); } } initFile4_obj;
