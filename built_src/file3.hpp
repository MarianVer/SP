#define _CRT_SECURE_NO_WARNINGS

#define SYMBOL_NUMBER 256
#define MAX_STATES 1024
#define MAX_FINIT_STATES 1024

// Стани
#define Q000 0 // Старт
#define Q001 1 // Є '_'
#define Q002 2 // Є '_A'
#define Q003 3 // Є '_AB' (Фінал)
#define Q_ER 4 // Помилка

int transitionTable3[SYMBOL_NUMBER][MAX_STATES];

void init_file3() {
    // 1. Очищення
    for(int i=0; i<SYMBOL_NUMBER; i++) 
        for(int j=0; j<MAX_STATES; j++) 
            transitionTable3[i][j] = Q_ER;

    // 2. Перехід по '_'
    transitionTable3['_'][Q000] = Q001;

    // 3. Переходи по великих літерах A-Z
    for (int c = 'A'; c <= 'Z'; c++) {
        transitionTable3[c][Q001] = Q002; // Перша літера
        transitionTable3[c][Q002] = Q003; // Друга літера (Фінал)
    }
}

struct InitFile3 { InitFile3(){ init_file3(); } } initFile3_obj;
