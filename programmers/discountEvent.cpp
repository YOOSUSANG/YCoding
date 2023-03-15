#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<sstream>
#include <stdbool.h>
#include <algorithm>
#include <stdlib.h>
#include<map>
#include <unordered_map>
#include<deque>
using namespace std;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> buyMap; // 구매한 제품을 담은 Map 
    int totalNumber = 10; // day
    int check;
    //해당 index부터 10일동안 살 수 있는 제품만 체크할 수 있으므로 -10해줌
    for (int i = 0; i <= discount.size() - totalNumber; i++) {
        check = 0; // 초기화
        buyMap.clear();// 초기화

        for (int j = i; j < (i + totalNumber); j++) {
            // 제품을 사지 못했으면 사기 
            if (buyMap.count(discount[j]) == 0) {
                buyMap.insert(make_pair(discount[j], 1));
            }
            else
                buyMap[discount[j]] += 1;
        }
        //자신이 원하는 수량만큼 샀는지 체크 
        for (int j = 0; j < number.size(); j++) {
            if (buyMap[want[j]] != number[j]) {
                check++;
            }
        }
        //수량만큼 샀으면 answer++
        if (check == 0) {
            answer++;
        }
    }
    return answer;
}
