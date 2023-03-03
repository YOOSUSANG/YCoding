
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
vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m; // map을 사용해서 사전을 초기화시킨다.  
    string ch = ""; // 사전에 들어갈 문자열
    string s; // 길이가 1인 모든 단어를 string으로 포함하도록 하기 위한 string s
    
    // 길이가 1인 모든 단어를 사전에 포함
    for (int i = 0; i < 26; i++) {
        char c = 'A' + i;
        s = "";
        s.push_back(c);
        m.insert(make_pair(s, i + 1));
    }
    //사전에 들어갈 문자열 check
    for (int i = 0; i < msg.size(); i++) {
        ch.push_back(msg[i]);
        if (m.count(ch) == 0) { // map에 존재하지 않으면 새로운 문자열을 만들 수 있다.
            answer.push_back(m[ch.substr(0, ch.size() - 1)]); // 이전 문자열 사전 번호 넣기
            m.insert(make_pair(ch,m.size()+1)); //새로운 문자열 삽입 및 사전 번호 증가
            ch = ch.substr(ch.size() - 1, 1); // 다시 새롭게 시작할 사전 문자열
        }
    }
    answer.push_back(m[ch]); // 마지막으로 처리되지 않은 글자 처리
    return answer;
}
