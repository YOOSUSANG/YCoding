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
 카펫 완전탐색
     yello개수: 1    4    9    16    25    36    49 
         가로: 3by3 4by4 5by5 6by6  7by7  8by8  9by9 즉 열은 고정됨
*/
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int col = 3,ok=0,cnt;
    //우선 yello 개수에 따른 가로 구하기
    for (int i = 1; i < 1415; i++) { // 1415제곱은 2002225이므로 yellow 한계
        if (i * i <=yellow) { // yellow 개수가 작은 값부터 탐색 
            cnt = i * i; // 증가하는 개수 3by3는 1씩 4by4는 2씩 5by5는 3씩...
            for (int j = col; j <= 1000000; j +=1) { //행을 1씩 증가시켜 찾아 본다.
                if (((j * col) - yellow == brown) && (cnt==yellow)) { // yellow 개수와 cnt가 같고 행*열 - yellow가 brown이면 알맞게 찾은 것
                    answer.push_back(j); // 행
                    answer.push_back(col); // 열
                    ok++; //찾음
                    break;
                }
                cnt += i; // 열에 따른 yellow 개수 증가
            }

            if (ok == 1)
                break;
        }
        if (ok == 1)
            break;

        col++; // 열 증가 
    }
    return answer;
}
