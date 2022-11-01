#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<string.h>
#include<sstream>
#include <stdbool.h>
#include <stdlib.h>
#include<map>
#include<algorithm>
using namespace std;
/*
 다음 큰 숫자
*/
int solution(int n) {
    int answer = 0;
    int re = n;
    int one1_cnt = 0;
    while (1) {
        if (re % 2 == 1)
            one1_cnt++;
        re /= 2;
        if (re == 0)
            break;
    }
    int one2_cnt = 0;
    for (int i = n + 1; i < n * 2; i++) {
        one2_cnt = 0;
        int real = i;
        while (1) {
            if (real % 2 == 1)
                one2_cnt++;
            real /= 2;
            if (real == 0)
                break;
        }
        if (one2_cnt == one1_cnt) {
            answer = i;
            break;
        }
    }
    return answer;
}
