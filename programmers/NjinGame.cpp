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
string solution(int n, int t, int m, int p) {
    string answer = "";
    string jin = ""; // 변환된 진법 저장
    int cnt = 0;
    for (int i = 0; i <= 100000; i++) { //임의의 10만이라는 고정된 숫자만큼 진법을 구하기 
        if (i == 0) {
            jin += to_string(i);
        }
        else {
            int j = i;
            string cjin = "";
            while (1) {
                // 진법으로 나눌 떄 자릿수가 10~15면 A~F로 저장하고, 아니면 그냥 자릿수로 넣어주기
                (j % n >= 10 && j % n <= 15) ? cjin += (char)(55 + (j % n)) : cjin += to_string(j % n);
                if (j / n == 0)
                    break;
                j /= n;
            }
            reverse(cjin.begin(), cjin.end()); // 역순을 정방향으로 정렬
            jin += cjin;
        }
    }
    // 자신의 순서가 왔으면 저장해주기
    for (int i = 0; i < jin.size(); i++) {
        if ((i % m) + 1 == p) {
            answer.push_back(jin[i]);
            cnt++;
        }
        if (cnt == t)
            break;
    }
    return answer;
}
