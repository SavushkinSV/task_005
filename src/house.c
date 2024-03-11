#include <stdio.h>
#include <stdlib.h>

void error_exit();
void input_dimensions();
int get_total(int width, int length, int height);
void check_price(int total_price, int current_price);

int main() {
    input_dimensions();

    return EXIT_SUCCESS;
}

/* Функция завершения программы с ошибкой */
void error_exit() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}

/* Функция ввода ширины, длины, высоты и текущей суммы */
void input_dimensions() {
    int width = 0;
    int length = 0;
    int height = 0;
    int current_price = 0;
    if (scanf("%d %d %d %d", &width, &length, &height, &current_price) != 4) {
        error_exit();
    }
    if (width <= 0 || length <= 0 || height <= 0 || current_price < 0) {
        error_exit();
    }
    int total_price = get_total(width, length, height);
    check_price(total_price, current_price);
}

/* Функция расчета итоговой цены */
int get_total(int width, int length, int height) {
    int foundation_cost = width * length * 1000;
    int cost_of_wals = 2 * (width + length) * height * 500;
    int roof_cost = (width * length * 700) + height * 100;

    return foundation_cost + cost_of_wals + roof_cost;
}

/* Функция проверки итоговой и текущей сумм */
void check_price(int total_price, int current_price) {
    if (total_price <= current_price) {
        printf("YES");
    } else {
        printf("NO %d", total_price - current_price);
    }
}