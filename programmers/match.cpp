#include <vector>
#include<string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <algorithm>
/*
* 예상 대진표  
* 
*/
using namespace std;
int solution(int n, int a, int b) {
    int answer = 0;
    while (1) {
        // 홀수면 짝수로 바꿔서 반영, 짝수면 그대로 번호 반영
        a = a % 2 == 0 ? a / 2 : (a + 1) / 2;
        b = b % 2 == 0 ? b / 2 : (b + 1) / 2;
        if (a == b) {
            answer++;
            break;
        }
        answer++;
    }
    return answer;
}
