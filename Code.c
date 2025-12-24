#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    system("chcp 1251 > nul");

    char str[1000];

    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    // Находим середину строки
    int middle = len / 2;
    int count = 0;

    char* ptr = str + middle; // Указатель на начало второй половины

    printf("Вторая половина строки: %s\n", ptr);

    for (int i = middle; i < len; i++) {
        char current = str[i];
        if (current == ' ') {
            continue;
        }
        if (!isalnum(current)) {
            if (i + 1 < len && str[i + 1] == ' ') {
                count++;
                printf("Найден знак препинания '%c' на позиции %d\n", current, i + 1);
            }
            else if (i == len - 1 && current != ' ') {
                count++;
                printf("Найден знак препинания '%c' на позиции %d\n", current, i + 1);
            }
        }
    }

    printf("\nКоличество знаков препинания во второй половине строки: %d\n", count);

    return 0;
}