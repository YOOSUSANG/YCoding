include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<string.h>
#include<sstream>
#include <stdbool.h>
#include <stdlib.h>
#include<map>
#include<algorithm>
/*
  숫자의 표현 -> 연속한 자연수들을 표현하는 방식이므로 순차적으로 증가시켜서 check
*/
using namespace std;
int solution(int n) {
    int answer = 0;
    int last = 0, first = 1; // first는 순차적으로 값을 증가시키는 것으로 우선 1부터시작 last는 불 필요한 수 제거
    int sum = first; // 누적 합
    while (last < first) {// 반복문을 도는데 first는 last보다 클떄까지 반복함 first == last면 값은 0 
        if (sum == n) // 조건이 성립하면 개수 증가
            answer++;
        else if (sum > n) {// sum이 n보다 크면 last를 증가시켜 이미 방문했던 숫자들을 순차적으로 제거
            last++;
            sum -= last;
            continue;
        }
        // sum == n이후, sum < n일 경우는 값을 성립시켜야 하므로 first를 증가시킨 후 sum에 저장 
        first++;
        sum += first;
    }

    return answer;
}

