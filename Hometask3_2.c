#include <stdio.h>
#include <ctype.h>

// Функція шифрування
char caesar_cipher(char character, signed char key) {
    if (!isalpha(character)) {
        return character;
    }

    int is_upper = isupper(character);
    char base = is_upper ? 'A' : 'a';
    int char_index = character - base;

    int new_index = (char_index + key) % 26;
    if (new_index < 0) {
        new_index += 26;
    }

    return (char)(base + new_index);
}

int main() {
    int num_chars;
    signed char key;
    char input_char;

    // Запит кількості символів
    printf("Enter the number of characters to encrypt: ");
    if (scanf("%d", &num_chars) != 1 || num_chars <= 0) {
        printf("Invalid input for the number of characters. Terminated.\n");
        return 1;
    }

    // Запит ключа
    printf("Enter encryption key [-128, 127]: ");
    if (scanf("%hhd", &key) != 1) {
        printf("Invalid input for the encryption key. Terminated.\n");
        return 1;
    }

    // Нормалізація ключа (щоб уникнути зайвих циклів)
    key = key % 26;

    // Очищення буфера перед циклом
    while (getchar() != '\n');

    for (int i = 1; i <= num_chars; i++) {
        printf("Enter character %d: ", i);

        // Читаємо символ, пропускаючи пробіли
        if (scanf(" %c", &input_char) != 1) {
            printf("Error reading input.\n");
            i--;
            while (getchar() != '\n'); // очищення буфера
            continue;
        }

        // Якщо не літера, повторюємо запит
        if (!isalpha(input_char)) {
            printf("Invalid input: must be a valid alphabetic character\n");
            i--;
            while (getchar() != '\n');
            continue;
        }

        // Шифрування
        char encrypted_char = caesar_cipher(input_char, key);
        printf("Encrypted character: %c\n", encrypted_char);

        // Очищення буфера на випадок зайвих символів
        while (getchar() != '\n');
    }

    return 0;
}
