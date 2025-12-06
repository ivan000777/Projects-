#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000  // Максимальна довжина рядка

// Функція шифрування
char caesar_cipher(char character, signed char key) {
    if (!isalpha(character)) return character;

    int is_upper = isupper(character);
    char base = is_upper ? 'A' : 'a';
    int char_index = character - base;

    int new_index = (char_index + key) % 26;
    if (new_index < 0) new_index += 26;

    return (char)(base + new_index);
}

int main() {
    char input[MAX_LEN];
    signed char key;

    // Введення ключа
    printf("Enter encryption key [-128, 127]: ");
    if (scanf("%hhd", &key) != 1) {
        printf("Invalid key. Terminated.\n");
        return 1;
    }

    key = key % 26;

    // Очищення буфера після числа
    while (getchar() != '\n');

    // Введення рядка символів одним рядком
    printf("Enter text to encrypt: ");
    if (!fgets(input, MAX_LEN, stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    // Видалення символу нового рядка
    input[strcspn(input, "\n")] = 0;

    printf("Encrypted text: ");
    for (int i = 0; i < strlen(input); i++) {
        printf("%c", caesar_cipher(input[i], key));
    }
    printf("\n");

    return 0;
}

