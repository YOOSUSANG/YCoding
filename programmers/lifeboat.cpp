#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <algorithm>
/*
 구명보트 최대 2명이라서 변수 2개 사용
*/
using namespace std;
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end()); // 오름차순으로 정렬
    int fir = 0, la = people.size()-1;// 제일 작은 값, 제일 큰 값 비교를 위한 fir는 index=0, last=people().size()-1
    while (1) {
        if (fir == la ) {// 50 70 80 경우
            answer++;
            break;
        }
        if (fir > la)// 50 50 70 80 경우
            break;
        if (people[fir] + people[la] <= limit) { //무게가 허용되면
            la--; // 큰 무게 감소
            fir++;// 작은 무게 증가
        }
        else// 두 사람의 합이 무게 초과면
            la--; // 큰 무게는 포함 안되므로 큰 무게 감소
        answer++;// 구명보트 증가
    }
    return answer;
}
int main() {
   
    return 0;

}
