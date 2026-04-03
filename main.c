#include <stdio.h>
#include <time.h>

int fibo(int n) {
    if (n <= 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}


int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int n;
    clock_t start, end;
    double result;

    printf("n값  |  걸린 시간(초)\n");
    printf("--------------------\n");

    
    for (n = 5; n <= 40; n = n + 5) {
        start = clock();

        int f1 = fibo(n);
        int f2 = fibo(n - 1);
        gcd(f1, f2); 

        end = clock();
        result = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d    |  %f\n", n, result);
    }

    return 0;
}
