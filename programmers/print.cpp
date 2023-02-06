#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<string.h>
#include<sstream>
#include <stdbool.h>
#include <algorithm>
#include <stdlib.h>
#include<map>
#include<deque>
using namespace std;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> q; // 중요도, 위치
    for (int i = 0; i < priorities.size(); i++) {
        q.push_back(make_pair(priorities[i], i));
    }

    int head; // 중요도
    int correct; // 위치
    int size; // deque 크기
    int cnt = 1; // 순서
    while (q.size() != 0) {
        head = q.front().first; // 중요도
        correct = q.front().second; // 위치
        q.pop_front(); // deque 꺼내기
        size = q.size(); // 꺼낸 후 deque size

        for (auto iter = q.begin(); iter != q.end(); iter++) {
            if (head < iter->first) { // 자신보다 중요도가 높은 것이 deque에 있으면 
                q.push_back(make_pair(head, correct)); // 자기자신을 다시 넣어준다.
                break;
            }
        }

        if (size == q.size()) { // 꺼낸 후 deque size랑 같으면 자기자신을 넣어주지 않은거라서 프린트 
            if (correct == location) { // 이떄 자신이 찾고자 하는 위치가 같으면
                answer = cnt; // 순서 반영
                break;
            }
            else // 자신이 찾고자 하는 위치가 아니면 
                cnt++; // 다음 순서로 정하기
        }
    }
    return answer;
}
