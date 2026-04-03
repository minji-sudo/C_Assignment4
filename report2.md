#  피보나치 수열과 GCD의 복잡도 분석 보고서

## 1. 과제 개요
본 과제에서는 피보나치 수열을 재귀적 방법으로 구현하고, 인접한 두 피보나치 수 $F(n)$과 $F(n-1)$의 최대공약수(GCD)를 계산하는 과정에서 발생하는 실행 시간을 측정하여 알고리즘의 시간 복잡도를 검증합니다.

## 2. 구현 코드
프로파일링을 위해 `time.h`의 `clock()` 함수를 사용하여 다음과 같이 코드를 작성하였습니다.

c
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
    double time_result;

    printf("n_value | Time (sec)\n");
    printf("--------------------\n");

    for (n = 5; n <= 40; n = n + 5) {
        start = clock(); 
        int f1 = fibo(n);
        int f2 = fibo(n - 1);
        gcd(f1, f2); 
        end = clock(); 
        time_result = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d       | %f\n", n, time_result);
    }
    return 0;

 
## 3. 시간 복잡도 및 Big-O 분석
(1) 피보나치 수열 (재귀): O(2n)
재귀 방식으로 구현된 피보나치 함수는 이미 계산된 값을 구하기 위해 다시 함수를 호출하는 중복 연산이 기하급수적으로 발생합니다.
n이 1 증가할 때마다 호출 횟수가 약 1.618배(황금비)씩 늘어나므로,시간 복잡도는 지수 시간인 O(2n)에 해당합니다.

(2) GCD (유클리드 호제법): O(logn)
유클리드 호제법은 나머지 연산을 통해 입력값의 크기를 매 단계마다 매우 빠르게 줄여나갑니다.
따라서 입력값이 피보나치 수와 같이 커지더라도 계산 횟수는 로그 스케일로 유지되는 매우 효율적인 **O(logn)**의 복잡도를 가집니다.


## 4. 결과 데이터
![ 결과 데이터 ](graph.png)

## 5. 결론
측정결과 n=30을 기점으로 실행시간이 급증했다. 이는 재귀적 수열의 시간 복잡도가 지수함수 형태를 띈다는 것을 보여준다. 




