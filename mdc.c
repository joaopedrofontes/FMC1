#include <stdio.h>


int mdc(int a, int b) {

    if (b == 0)
        return a;
    return mdc(b, a % b);

}

int main() {

    int n;

    scanf("%d", &n);

    int somatorio = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            somatorio += mdc(i, j);
        }
    }

    printf("%d\n", somatorio);

    return 0;
}