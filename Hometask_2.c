#include <stdio.h>
#include <math.h>


double geometric_sum(double a, double r, int n) {
    return a * (1 - pow(r, n)) / (1 - r);
}

int main() {

    double a_float = 0.5;
    double r_float = 0.5;
    int n_float = 23;

    double a_double = 0.5;
    double r_double = 0.5;
    int n_double = 52;

    float max_float_mantissa = 1.0f + (float)geometric_sum(a_float, r_float, n_float);
    double max_double_mantissa = 1.0 + geometric_sum(a_double, r_double, n_double);

    printf("Максимальна мантиса для 32: %.23f\n", max_float_mantissa);
    printf("Максимальна мантиса для 64: %.52f\n", max_double_mantissa);

    return 0;

}
