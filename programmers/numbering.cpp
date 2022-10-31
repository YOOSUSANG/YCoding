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
int solution(int n) {
    int cnt = 0; // 개수 세기
    int head = 1, tail = 2; 
    int sum = head;
    while (head < tail) {
        if (sum == n)
            cnt++;
        if (sum < n) // n보다 작으면 끝 더해주기
            sum += tail++;
        else // n보다 크거나 같으면 앞 빼주기
            sum -= head++;

    }
    return cnt;
}
