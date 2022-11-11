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
/*
*  영어 끝말잇기
*/
using namespace std;
bool comp(pair<string, int>p1, pair<string, int>p2) {
    return p1.second < p2.second;
}
vector<int> Invalid(int i, int n) {
    vector<int>v;
    int first;
    int second;
    first = i % n;
    second = i / n + 1;
    if (i % n == 0)
        first = n;
    if (i % n == 0)
        second = i / n;
    v.push_back(first);
    v.push_back((second));
    return v;
}
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int>m;
    string ch;
    m.insert(make_pair(words[0],1));
    //1. 중복 제거
    for (int i = 1; i < words.size(); i++) {
        if (m.count(words[i]) == 1) {
            answer = Invalid(i+1, n);
            break;
        }

        m.insert(make_pair(words[i], i+1));
    }
    vector<pair<string, int>>vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(),comp);
    
    //2. 뒷, 앞 다름
    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        if (iter->second != 1) {
            iter--;
            ch = iter->first;
            iter++;
            if (ch[ch.size() - 1] != iter->first[0]) {
                answer = Invalid(iter->second, n);
                break;
            }
        }
    }
    if (answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
