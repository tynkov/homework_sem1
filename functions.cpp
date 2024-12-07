#include "functions.h"

double coef[11];

double func(short x) {
    double d = coef[0];
    d += coef[1] * x;
    for (int i = 2; i < 10; i++) {
        d += coef[i] * pow(x, i);
    }
    return d;
}

short mutation(short x0, short x1) {
    return x0 + rand() % (x1 - x0 + 1);
}

short inversion(short x) {
    return (rand() % 2 == 0) ? x - 1 : x + 1;
}

void crossover(short* x, short x0, short x1) {
    int k = 99;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            short candidate = (x[i] + x[j]) / 2;
            if (candidate >= x0 && candidate <= x1) {
                x[k--] = candidate;
            }
        }
    }
    for (int i = 8; i < k; i++) {
        x[i] = mutation(x0, x1);
    }
}

void sort(short* x, double* y, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (fabs(y[j]) < fabs(y[i])) {
                swap(y[i], y[j]);
                swap(x[i], x[j]);
            }
        }
    }
}

void init(short x0, short x1, short* population, double* f, int n) {
    for (int i = 0; i < n; i++) {
        population[i] = mutation(x0, x1);
        f[i] = func(population[i]);
    }
}

short genetic(short x0, short x1, short* population, double* f, int n) {
    init(x0, x1, population, f, n);
    sort(population, f, n);

    int iter = 0;
    while (f[0] != 0 && iter < 50000) {
        iter++;
        crossover(population, x0, x1);
        for (int i = 0; i < n; i++) {
            f[i] = func(population[i]);
        }
        sort(population, f, n);
    }
    return population[0];
}