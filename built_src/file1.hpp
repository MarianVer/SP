#define _CRT_SECURE_NO_WARNINGS

#define SYMBOL_NUMBER 256
#define MAX_STATES 1024
#define MAX_FINIT_STATES 1024

// Стани:
#define Q000 0 // Початковий
#define Q001 1 // Фінальний (знайдено символ)
#define Q002 2 // Проміжний (знайдено '-', чекаємо '>')
#define Q_ER 3 // Помилка

int transitionTable1[SYMBOL_NUMBER][MAX_STATES];

void init_file1() {
    // 1. Заповнюємо помилками за замовчуванням
    for(int i=0; i<SYMBOL_NUMBER; i++) {
        for(int j=0; j<MAX_STATES; j++) {
            transitionTable1[i][j] = Q_ER;
        }
    }

    // 2. Одиночні розділювачі (перехід з Q000 в Q001)
    // Символи: ( ) { } [ ] , ; : < >
    unsigned char singles[] = { '(', ')', '{', '}', '[', ']', ',', ';', ':', '<', '>' };
    for(int k=0; k < sizeof(singles); k++) {
        transitionTable1[singles[k]][Q000] = Q001;
    }

    // 3. Стрілка "->"
    // '-' переводить з Q000 в Q002
    transitionTable1['-'][Q000] = Q002;
    // '>' переводить з Q002 в Q001 (фінал)
    transitionTable1['>'][Q002] = Q001;
}

// Це "хак", щоб ініціалізація пройшла при старті. 
// В реальному генераторі тут був би просто великий масив чисел.
struct InitFile1 { InitFile1(){ init_file1(); } } initFile1_obj;
