#include "morse.h"

int main() {
    input_command();
    return EXIT_SUCCESS;
}

/* Функция ввода команды */
void input_command() {
    char line[256] = "";
    char result_str[256] = "";

    switch (get_command()) {
        case (TRANSLATE_LTR_MORSE):
            get_string(line);
            if (!translate_letters_to_morse(line, result_str))
                printf("%s", result_str);
            else
                error_exit();
            break;
        case (TRANSLATE_MORSE_LTR):
            get_string(line);
            if (!translate_morse_to_letters(line, result_str)) {
                printf("%s", result_str);
            } else {
                error_exit();
            }
            break;

        default:
            error_exit();
            break;
    }
}

/* Функция возвращает код введенной команды */
int get_command() {
    int command = 0;
    if (scanf("%d", &command) == 1) {
        if (command == 1) command = TRANSLATE_LTR_MORSE;
        if (command == 2) command = TRANSLATE_MORSE_LTR;
    }
    free_buffer();
    return command;
}

// получение строки с пробелами
void get_string(char *str) {
    fgets(str, 256, stdin);
    int len = strlen(str);
    if (str[len] == '\n') {
        str[len - 1] = '\0';
    }
}

/* Функция завершения программы с ошибкой */
void error_exit() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}

/* Функция очистки буфера от лишних символов */
void free_buffer() {
    int c;
    while ((c = getchar()) != '\n') {
        ;
    }
}

/* Функция перевода строки в азбуку Морзе. Возвращает 0 если нет ошибок*/
int translate_letters_to_morse(char *str, char *result_str) {
    int error = 0;
    int count = 0;
    while (*str != '\0') {
        if (*str == ' ') {
            strcat(result_str, "\t");
            count = 0;
        } else {
            int add_symbol_flag = 0;
            for (int j = 0; j < SIZE_ALPHABET; j++) {
                if (toupper(*str) == morse_translate[j].c) {
                    if (count) strcat(result_str, " ");
                    strcat(result_str, morse_translate[j].morse);
                    count++;
                    add_symbol_flag = 1;
                    break;
                }
            }
            if (add_symbol_flag == 0) error = 1;
        }
        str++;
    }

    return error;
}

/* Функция перевода из азбуки Морзе в строку */
int translate_morse_to_letters(char *str, char *result_str) {
    int error = 0;
    while (*str != '\0') {
        int count = 0;
        char morse_str[256] = "";
        while (*str != ' ' && *str != '\t' && *str != '\0') {
            morse_str[count] = *str;
            count++;
            str++;
        }
        morse_str[count] = '\0';
        char c[2] = "";
        if (!check_symbol(morse_str, c)) {
            strcat(result_str, c);
        } else {
            error++;
        }
        if (*str == '\t') strcat(result_str, " ");
        str++;
    }

    return error;
}

/* Проверки строки с алфавитом азбуки Морзе */
int check_symbol(char *str, char *result) {
    int error = 1;
    for (int i = 0; i < SIZE_ALPHABET; i++) {
        if (!strcmp(str, morse_translate[i].morse)) {
            result[0] = morse_translate[i].c;
            result[1] = '\0';
            error = 0;
            break;
        }
    }

    return error;
}
