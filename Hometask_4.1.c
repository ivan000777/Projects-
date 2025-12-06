#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Розмір масиву N x N
#define N 4 

int main() {
    srand(time(NULL)); 

    int original[N][N];
    int rotated[N][N];
    
    // 1. Заповнення масиву випадковими числами
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            original[i][j] = rand() % 100; 
        }
    }

    // 2. Друк о масиву
    printf("\nOriginal Array (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", original[i][j]);
        }
        printf("\n");
    }

    // 3. Обертання на 90 за годинниковою стрілкою,j=0, 1, 2, ..., N-1.
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