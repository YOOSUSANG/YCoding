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
    int a = 1, b = 1,c;
    int cnt = 3;
    if (n == 2)
        return 1;

    while (1) {
        c = a % 1234567 + b % 1234567;
        a = b % 1234567;
        b = c % 1234567;
        if (cnt == n)
            break;
        cnt++;
    }
    return c % 1234567;
}
