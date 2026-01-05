#define _CRT_SECURE_NO_WARNINGS
#define WIN_M /* Для Windows консолі */

#ifdef WIN_M
#include <windows.h>
#endif
#include "stdio.h"	

/* Оголошуємо функції з інших файлів */
extern int call_main_spirit(int argc, char* argv[]);
extern int call_main_syntax(int argc, char* argv[]);

int main(int argc, char* argv[]) {
#ifdef WIN_M
	/* Вмикаємо підтримку кольорів та очищення екрану в Windows 10+ */
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hConsole, &dwMode);
	SetConsoleMode(hConsole, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
	
	/* Очищення екрану */
	printf("\x1b[2J\x1b[H"); 

	printf("=======================================================\n");
	printf("        Course Project: Variant 2 (Vereshchak)         \n");
	printf("=======================================================\n\n");

	printf("Enter 'y' to verify by EBNF (Boost Spirit)\n");
	printf("Enter other key to verify by LL(2) prototype\n");
	printf("Your choice: ");

	char valueByGetChar = getchar();

	/* Очищення буфера клавіатури після вводу символу */
	if (valueByGetChar != '\n') {
		char temp;
		while ((temp = getchar()) != '\n' && temp != EOF);
	}

	if (valueByGetChar == 'y' || valueByGetChar == 'Y') {
		/* Виклик парсера на Boost Spirit (файл one_file__x86_Debug.cpp) */
		return call_main_spirit(argc, argv);
	}

	/* Виклик ручного парсера (якщо він є у проекті) */
	return call_main_syntax(argc, argv);
}
