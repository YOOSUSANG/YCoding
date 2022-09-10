#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<string.h>
#include<sstream>
#include <stdbool.h>
#include <stdlib.h>
#include<map>
/*
 최대값, 최소값 구하기 
*/
using namespace std;
int Max(int a, int b) {
    return a > b ? a : b;
}
int Min(int a, int b) {
    return a > b ? b : a;
}
string solution(string s) {
    string answer = "";
    string sub_str = ""; // 공백으로 나누어진 문자열들을 저장하는 것
    int MaxNum, MinNum;
    istringstream ss(s); // istringstram을 통해서 문자열을 반복함(getline을 쓰기 위해서) string이 옴
    int len = 0; //처음 길이떄 값을 저장하고 그 이외에 값 비교를 하기 위해서
    while (getline(ss, sub_str, ' ')) { //ss을 공백기준으로 나눠서 sub_str에 저장한다.
        //처음 길이가 0이면 그냥 저장 >> 비교하기 전에 기본값 설정
        if (len == 0) { 
            MaxNum = stoi(sub_str);
            MinNum = stoi(sub_str);
        }
        //비교
        else {
            MaxNum = Max(MaxNum, stoi(sub_str));
            MinNum = Min(MinNum, stoi(sub_str));
        }
        len++;
    }
    //비교 후 값저장
    answer += to_string(MinNum);
    answer += " ";
    answer += to_string(MaxNum);

    return answer;
}
