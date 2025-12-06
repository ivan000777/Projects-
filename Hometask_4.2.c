#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Визначення констант
#define N 1000  // Розмір масиву
#define RANGE_MAX 10 // Максимальне значення випадкового числа (1..10)

// Структура для зберігання числа та його кількості
typedef struct {
    int number;
    int count;
} CountData;

// Функція порівняння для qsort (сортування за спаданням кількості)
int compare_counts(const void *a, const void *b) {
    // Приведення до вказівників на структуру CountData
    const CountData *data_a = (const CountData *)a;
    const CountData *data_b = (const CountData *)b;
    
    // Сортування за спаданням: B - A
    return data_b->count - data_a->count;
}

int main() {
    // Ініціалізація генератора випадкових чисел
    srand(time(NULL)); 

    // Масив для зберігання 1000 випадкових чисел
    int random_array[N];
    
    // Масив для підрахунку частоти. 
    // Індекси 1..10 будуть використовуватися для чисел 1..10.
    // Розмір RANGE_MAX + 1 = 11, де індекс 0 ігнорується.
    int counts[RANGE_MAX + 1] = {0}; 
    
    // 1. Генерація масиву та підрахунок частоти
    // Часова складність: O(N)
    for (int i = 0; i < N; i++) {
        // Генеруємо число у діапазоні [1..10]
        int num = (rand() % RANGE_MAX) + 1;
        random_array[i] = num;
        
        // Підраховуємо входження
        counts[num]++; 
    }

    // 2. Підготовка даних для сортування
    // Кількість унікальних чисел - це RANGE_MAX (10)
    CountData results[RANGE_MAX]; 
    
    // Часова складність: O(M), де M=10 (RANGE_MAX). Це константа.
    for (int i = 1; i <= RANGE_MAX; i++) {
        results[i - 1].number = i;
        results[i - 1].count = counts[i];
    }

    // 3. Сортування результатів за спаданням
    // Часова складність: O(M log M), де M=10. Це константа.
    qsort(results, RANGE_MAX, sizeof(CountData), compare_counts);

    // 4. Друк результатів
    printf("Number of occurrences for each random number (N=%d):\n", N);
    
    // Часова складність: O(M)
    for (int i = 0; i < RANGE_MAX; i++) {
        printf("Number %2d: %4d times\n", results[i].number, results[i].count);
    }

    return 0;
}