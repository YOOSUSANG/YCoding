#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<string.h>
#include<sstream>
#include <stdbool.h>
#include <stdlib.h>
#include<map>
/*
피보나치 수열 재귀로도 쉽게 구할 수 있지만 시간 초과가 나므로 반복문을 통해서 구현했다.
*/
using namespace std;
int solution(int n) {
    int answer = 0; // 결과
    int a = 0, b = 1, c; // a는 0번째, b는 1번째, c는 (n-1) + (n-2) 번쨰 
    if (n == 0) // 0번째면 return 0;
        return 0;
    else if (n == 1) // 1번째면 return 1;
        return 1;
    else {
        int len = 2; // 2번쨰 이상이므로 counting
        while (1) { // n번째 피보나치 수를 1234567으로 나눈 나머지를 리턴하는 함수을 만드는 것이므로 다 % 1234567을 해줘야함
            c = a % 1234567 + b % 1234567;
            a = b % 1234567;
            b = c % 1234567;
            if (len == n) { // 내가 찾고 싶은 n번째를 찾았으면 break;
                answer = c % 1234567;
                break;
            }
            len++;

        }
    }
    return answer;
}
