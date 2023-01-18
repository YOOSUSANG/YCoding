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
/*
* 문자열 s가 주어지면 0~s 길이까지 왼쪽으로 회전하면서 올바른 괄호 문자열이 되게 하는 개수 구하기
*/
using namespace std;
int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i++) { // 왼쪽으로 회전하므로 시작점을 index = 0으로 설정 1, 2, 3.. 순으로 시작점 매칭 
        string st;
        int start = i; // 시작점 설정
        for (int w = 0; w < s.size(); w++) { // 총 반복 횟수
            if (st.empty()) { // st가 비워져있으면 처음이므로 그냥 넣어줌
                st.push_back(s[(start + w) % s.size()]);
            }
            else {
                // 경우의 수가 3가지 이므로 3가지에 맞게 설정 
                if (st.back() == '(' && s[(start + w) % s.size()] == ')')
                    st.pop_back();
                else if (st.back() == '{' && s[(start + w) % s.size()] == '}')
                    st.pop_back();
                else if (st.back() == '[' && s[(start + w) % s.size()] == ']')
                    st.pop_back();
                else 
                    st.push_back(s[(start + w) % s.size()]);
            }
        }
        if (st.empty())
            answer++;
    }
    return answer;
}
