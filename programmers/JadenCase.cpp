#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<string.h>
#include<sstream>
#include <stdbool.h>
#include <stdlib.h>
#include<map>
using namespace std;
/*
 JadenCase 문자열 만들기 첫 문자는 대문자, 나머지는 소문자 이때 공백문자가 연속해서 나올 수 있음
 공백문자가 연속해서 나올 떄 마지막 문자열때 공백이 연속해서 나올 수 있으므로 처리 
*/
string solution(string s) {
    string answer = ""; // 결과
    string sub_str = ""; // 공백기준으로 나눔
    istringstream ss(s); // 문자열을 공백으로 나누기 위해서
    // 공백 기준으로 나누고 첫 문자 -> 대문자, 나머지 문자 -> 소문자
    while (getline(ss, sub_str, ' ')) { 
        if ('a' <= sub_str[0] && sub_str[0] <= 'z')
            sub_str[0] = sub_str[0] - 32; // 아스키코드 변환

        for (int i = 1; i < sub_str.size(); i++) {
            if ('A' <= sub_str[i] && sub_str[i] <= 'Z')
                sub_str[i] = sub_str[i] + 32; // 아스키코드 변환
        }
        answer += sub_str; // 바꿔준 문자열을 넣어주기
        answer += " ";// 공백도 넣어주기
    }
    //마지막 문자열에서 공백이 연속해서 나오면 처리
    if(s[s.size()-1]!=' ')
        answer.pop_back();

    return answer;
}
