# 과제 : GCD 알고리즘 복잡도 분석

## 1. 제출한 GCD 알고리즘 파일 링크
* **GitHub 링크:** https://github.com/minji-sudo/C_Assignment3/blob/main/main.c
                   https://github.com/minji-sudo/C_Assignment3/blob/main/my_math.c

## 2. 시간 복잡도 및 Big-O 계산
사용한 알고리즘 : 두 수의 최대공약수를 구하기 위해 유클리드 호제법(Euclidean Algorithm)을 사용하였다. 
이 알고리즘은 큰 수를 작은 수로 나눈 나머지를 구하고, 다시 그 작은 수를 방금 구한 나머지와 나누는 과정을 반복하여 나머지가 0이 될 때의 나누는 수를 찾는 방식이다.

시간 복잡도 분석 : 유클리드 호제법은 나눗셈의 나머지 연산을 사용한다. 이 과정에서 숫자의 크기가 매 단계마다 급격히 감소하며,
최악의 경우에도 입력값의 자릿수에 비례하는 횟수만큼만 반복하면 계산이 종료된다.

Big-O 계산 결과: $O(\log(\min(a, b)))$입력받은 두 수 중 작은 수를 기준으로 로그 복잡도를 가진다. 
