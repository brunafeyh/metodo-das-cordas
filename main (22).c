#include <stdio.h>
#include <math.h>


double f(double x) {
    return x * x - 4; 
}

// Método das Cordas
double metododascordas(double a, double b, double tol, int max_iter) {
    double x0, x1;
    int iter = 0;

    do {
        x0 = a - (f(a) * (b - a)) / (f(b) - f(a));
        if (f(a) * f(x0) < 0) {
            b = x0;
        } else {
            a = x0;
        }
        x1 = a - (f(a) * (b - a)) / (f(b) - f(a));
        iter++;
    } while (fabs(x1 - x0) > tol && iter < max_iter);

    return x1;
}

int main() {
    double a = 1.0; // Intervalo [a, b]
    double b = 3.0;
    double tol = 1e-6; // Tolerância
    int max_iteracoes = 100; // Número máximo de iterações

    double raiz = metododascordas(a, b, tol, max_iteracoes);

    printf("A raiz aproximada é: %lf\n", raiz);

    return 0;
}