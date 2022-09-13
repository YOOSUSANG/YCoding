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
멀리뛰기 -> 효진이는 한번에 1칸, 또는 2칸을 뛸 수 있음
        1칸: 1
        2칸: (1,1), 2
        3칸: (1,1,1),(1,2),(2,1)
        4칸:(1,1,1,1),(1,1,2),(1,2,1),(2,1,1),(2,2) 
      규칙을 살펴보면 전꺼와 전전꺼을 사용한다.
*/
using namespace std;
long long solution(int n) {
    long long answer = 0;
    long long a = 1, b = 2, c;
    if (n == 1)// 1칸인 경우
        return a;
    else if (n == 2)// 2칸인경우
        return b;
    else {// 3칸이상인 경우
        int len = 3;
        while (1) {
            c = a % 1234567 + b % 1234567;
            a = b % 1234567;
            b = c % 1234567;
            if (len == n) { //자신이 찾고 싶은 칸에 도달했으면 answer에 저장 후 break;
                answer = c % 1234567;
                break;
            }
            len++;
        }
    }
    return answer;
}
