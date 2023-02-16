#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<sstream>
#include <stdbool.h>
#include <algorithm>
#include <stdlib.h>
#include<map>
#include<deque>
using namespace std;
bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int>m;
    sort(phone_book.begin(), phone_book.end()); // 크기기준으로 오름차순 정렬 
    // map에 다 넣어준다.
    for (int i = 0; i < phone_book.size(); i++) { 
        m.insert(make_pair(phone_book[i], i));
    }
    //phone_book에 있는 요소들이 접두사를 포함하는지 확인
    for (int i = 1; i < phone_book.size(); i++) { // phone_book Element check
        for (int j = 1; j <= phone_book[i].size(); j++) { // 요소길이만큼 접두사 확인
            if (m.count(phone_book[i].substr(0, j)) && phone_book[i] != phone_book[i].substr(0, j)) // 자기자신은 제외
                answer = false;
        }
    }
    return answer;
}
