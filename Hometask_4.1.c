#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Розмір масиву N x N
#define N 4 

int main() {
    // Ініціалізація генератора випадкових чисел
    srand(time(NULL)); 

    int original[N][N];
    int rotated[N][N];
    
    // 1. Заповнення оригінального масиву 4x4 випадковими числами
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Випадкове число у діапазоні [0, 99]
            original[i][j] = rand() % 100; 
        }
    }

    // 2. Друк оригінального масиву
    printf("\nOriginal Array (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", original[i][j]);
        }
        printf("\n");
    }

    // 3. Обертання на 90° за годинниковою стрілкою
    // rotated[новий рядок] = original[старий стовпець]
    // rotated[новий стовпець] = N - 1 - original[старий рядок]
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated[j][N - 1 - i] = original[i][j];
        }
    }

    // 4. Друк обернутого масиву
    printf("\nRotated Array (90° Clockwise):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", rotated[i][j]);
        }
        printf("\n");
    }

    return 0;
}