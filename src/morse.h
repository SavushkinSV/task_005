#ifndef MORSE_H
#define MORSE_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_ALPHABET 36
#define TRANSLATE_LTR_MORSE 1
#define TRANSLATE_MORSE_LTR 2

typedef struct {
    char *morse;
    char c;
} Morse_code;

Morse_code morse_translate[] = {
    {".-", 'A'},    {"-...", 'B'},  {"-.-.", 'C'},  {"-..", 'D'},   {".", 'E'},     {"..-.", 'F'},
    {"--.", 'G'},   {"....", 'H'},  {"..", 'I'},    {"---.", 'J'},  {"-.-", 'K'},   {".-..", 'L'},
    {"--", 'M'},    {"-.", 'N'},    {"---", 'O'},   {".-.-", 'P'},  {"--.-", 'Q'},  {".-.", 'R'},
    {"...", 'S'},   {"-", 'T'},     {"..-", 'U'},   {"...-", 'V'},  {".--", 'W'},   {"-..-", 'X'},
    {"-.--", 'Y'},  {"--..", 'Z'},  {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'},
    {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'}, {"-----", '0'},
};

void error_exit();
void get_string(char *str);
void input_command();
void free_buffer();
int get_command();
int translate_letters_to_morse(char *str, char *result_str);
int translate_morse_to_letters(char *str, char *result_str);
int check_symbol(char *str, char *result);

#endif  // MORSE_H