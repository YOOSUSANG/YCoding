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
int solution(string str1, string str2) {
    int answer = 0;// 총 size 저장 a + b
    int Intersection = 0; //교집합 a n b
    int Union = 0; //합집합 a u b  = a + b - a n b
    double ans = 0; // 실수부분 저장 

    //str1, str2 소문자로 전환
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    map<string,int>s;
    for (int i = 0; i < str1.size()-1; i++) {
        string res = str1.substr(i, 2);
        if ('a' <= res[0] && res[0] <= 'z' && 'a' <= res[1] && res[1] <= 'z') { // 특수문자가 존재하지 않으면
            if (s.count(res) == 0) // map에 없으면 넣기
                s.insert(make_pair(res, 1));
            else 
                s[res]++; // 중복된 숫자가 있으면 개수 증가
            
            answer++;
        }
    }

    for (int i = 0; i < str2.size()-1; i++) {
        string res = str2.substr(i, 2);
        if ('a' <= res[0] && res[0] <= 'z' && 'a' <= res[1] && res[1] <= 'z') { // 특수문자가 존재하지 않으면
            if (s[res]!=0) { // 교집합 처리가 가능하면
                Intersection++;
                s[res]--; // 교집합 처리를 해줬으니 개수 감소
            }
            answer++;
        }
    }
    Union = answer - Intersection; // a u b = a + b - a n b 
    
    if (Union == 0) // 예외처리
        return 65536;

    ans = (Intersection /(double) Union) * 65536;
    return (int) ans;
}
