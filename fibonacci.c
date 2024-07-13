
#include <stdio.h>
#include <math.h>

double potencia(double base, int expoente) {
    double resultado = 1.0;
    if (expoente >= 0) {
        for (int i = 0; i < expoente; i++) {
            resultado *= base;
        }
    } else {
        for (int i = 0; i > expoente; i--) {
            resultado /= base;
        }
    }
    return resultado;
}

int main() {
    int n, m;
    double nTermo;
    int resultado;
    scanf("%d %d", &n, &m);

    double x = (1 + sqrt(5)) / 2;
    double y = (1 - sqrt(5)) / 2;
    nTermo = (potencia(x, n) - potencia(y, n)) / sqrt(5);
    resultado = (int)nTermo % (int)potencia(2, m);
    //printf("%.0lf\n", nTermo);
    printf("%d\n", resultado);
    return 0;
}