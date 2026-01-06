/* Wrapper to link C main with C++ Parsers */

// Оголошуємо функцію з syntax_one.cpp
int main_syntax(int argc, char* argv[]);

// Оголошуємо функцію з one_file__x86_Debug.cpp
// Якщо в тому файлі функція вже має extern "C" і називається call_main_spirit,
// то ми просто декларуємо її тут для лінкера, або вона вже доступна.
// Але wrapper.cpp часто використовується, щоб обернути C++ винятки або манглінг імен.

extern "C" {
    // Ця функція викликається з main.c
    // Вона перенаправляє виклик до C++ функції main_syntax
    int call_main_syntax(int argc, char* argv[]) {
        return main_syntax(argc, argv);
    }

    // Якщо one_file__x86_Debug.cpp має функцію call_main_spirit вже з extern "C",
    // то її можна викликати напряму з main.c.
    // Якщо ж там функція має іншу назву (наприклад, main_spirit), розкоментуйте нижче:
    /*
    extern int main_spirit(int argc, char* argv[]);
    int call_main_spirit(int argc, char* argv[]) {
        return main_spirit(argc, argv);
    }
    */
}
