#include <vector>
#include<string.h>
#include <stdbool.h>
#include <stdlib.h>
#include<map>
/*
* 문제를 보면 4개씩 끊어서 빈칸이 생성되는 것을 확인할 수 있다.  4개씩 반복되는 횟수는 총 4개이므로 GCD를 통해서
* 구할 수 있음을 알 수 있다. GCD는 가로, 세로 합에서 구하므로 이 가로, 세로 합 - GCD를 했더니 빈칸의 개수를 구할 수 있었다.
*  W, H 가 1억이하이므로 자료형이 제일 큰 unsigned long long 으로 형변환시켜서 쓰레기 값 방지
*/ 
using namespace std;
long long solution(int w, int h) {
    long long answer = 0;
    unsigned long long result = (unsigned long long) w * (unsigned long long)h; //크기가 크므로 형변환을 시켜야함
    long long a = w, b = h;
    long long c;
    while (1) {
        c = a % b;
        if (c == 0)
            break;
        a = b;
        b = c;
    }
    answer = result - ((w + h) - b);
    return answer;
}

