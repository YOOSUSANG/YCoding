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
bool compare(pair<int, int>a, pair<int, int>b) { // 내림차순 정렬
    return a.second > b.second;
}
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int>m; // key:귤, value: 개수
    for (int i = 0; i < tangerine.size(); i++) {
        if (m.count(tangerine[i]) == 0)
            m.insert(make_pair(tangerine[i], 1));
        else
            m[tangerine[i]]++;
    }
    vector<pair<int, int>>vec(m.begin(), m.end()); // map을 정렬하기 위해 vector로 복사
    sort(vec.begin(), vec.end(), compare);

    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        if (k <= iter->second) { //남아있는 귤 개수보다 크면
            answer++;
            break;
        }
        else { //현재 귤 개수가 남아있으면
            k -= iter->second;
            answer++;
        }
    }
    return answer;
}
