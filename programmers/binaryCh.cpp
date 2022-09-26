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
using namespace std;
vector<int> solution(string s) {
    vector<int> answer; // 결과
    int zero = 0,one,count = 0; // zero 개수, one 개수, 이진 변화 개수
    int decimal;// 10진수 저장
    while (1) {
        one = 0; // 1의 개수는 초기화 이진 변화 결과마다 반복해서 구하므로
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                one++;
            else
                zero++;
        }
        decimal = one; // 1의 개수를 저장 (십진수)
        s.clear(); // 1를 넣어줄 string 초기화
        while (1) {
            s += to_string(decimal % 2);
            decimal /= 2;
            if (decimal == 0) { // 몫이 0이면 더 이상 구할 수 없음
                reverse(s.begin(),s.end());// 거꾸로 저장됐으니 reserve()함수를 사용해서 뒤집기
                count++;//횟수 증가
                break;
            }
        }
        if (s == "1") // 이진 결과값이 1이면 끝
            break;
    }
    // 결과에 저장
    answer.push_back(count);
    answer.push_back(zero);
    return answer;
}

