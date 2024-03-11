#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_ALPHABET 36
#define TRANSLATE_STR_MORSE 1
#define TRANSLATE_MORSE_STR 2

typedef struct {
    char *morse;
    char c;
} Morse_code;

Morse_code morse_translate[] = {
    {".-", 'a'},    {"-...", 'b'},  {"-.-.", 'c'},  {"-..", 'd'},   {".", 'e'},     {"..-.", 'f'},
    {"--.", 'g'},   {"....", 'h'},  {"..", 'i'},    {"---.", 'j'},  {"-.-", 'k'},   {".-..", 'l'},
    {"--", 'm'},    {"-.", 'n'},    {"---", 'o'},   {".-.-", 'p'},  {"--.-", 'q'},  {".-.", 'r'},
    {"...", 's'},   {"-", 't'},     {"..-", 'u'},   {"...-", 'v'},  {".--", 'w'},   {"-..-", 'x'},
    {"-.--", 'y'},  {"--..", 'z'},  {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'},
    {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'}, {"-----", '0'},
};

void error_exit();
char *get_string();
void input_command();

/* Функция очистки буфера от лишних символов */
void free_buffer() {
    int ch;
    while ((ch = getchar()) != ' ' && ch != '\n') {
    }
}

void translate_string_to_morse(char *str) {
    while (*str != '\0') {
        int count = 0;
        for (int j = 0; j < SIZE_ALPHABET; j++) {
            if (tolower(*str) == morse_translate[j].c) {
                if (!count) printf(" ");
                printf("%s", morse_translate[j].morse);
                break;
            }
        }
        str++;
    }
}

int main() {
    input_command();

    return EXIT_SUCCESS;
}

// посимвольное получение динамической строки с пробелами c получением её реальной длины
char *get_string() {
    int len = 0;
    int size = 1;
    char *s = (char *)malloc(sizeof(char));

    char c = getchar();
    while (c != '\n') {
        s[(len)++] = c;
        if (len >= size) {
            size *= 2;
            char *tmp = (char *)realloc(s, size * sizeof(char));
            if (tmp == NULL) {
                error_exit();
            } else {
                s = tmp;
            }
        }
        c = getchar();
    }

    s[len] = '\0';
    return s;
}

/* Функция завершения программы с ошибкой */
void error_exit() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}

/* Функция ввода команды */
void input_command() {
    int command = 0;
    scanf("%d", &command);
    switch (command) {
        case (TRANSLATE_STR_MORSE):
            free_buffer();
            char *line = get_string();  // считываем динамическую строку
            translate_string_to_morse(line);
            free(line);  // освобождаем динамическую память
            break;
        case (TRANSLATE_MORSE_STR):
            printf("TRANSLATE_MORSE_STR");
            break;

        default:
            error_exit();
            break;
    }
}