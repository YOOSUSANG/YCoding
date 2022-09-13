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
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int row;
    if (yellow == 0) {// brown은 8개부터 시작이므로 yellow개수가 0이면 가로길이는 4, 세로길이는 2이다.
        row = 4;
        while (1) {
            if (row * 2 == brown) // *2을 해준 이유는 위,아래 개수
                break;
            row++;
        }
        answer.push_back(row);
        answer.push_back(2);
    }
    else { // yellow가 한개라도 있으면 완전 탐색을 통해 계산 이때 세로길이3, 가로길이 3부터 탐색 시작
        int cnt, ycnt; // cnt는 증가하는개수, ycnt는 찾고자 하는 yellow 개수
        for (int col = 3; col < 10000; col++) {
            row = col; // 가로,세로가 같을때 부터 시작 -> 이후 세로만 점점 커진다.
            cnt = col - 2; // 가로마다  증가하는 yellow 개수
            ycnt = (row - 2) * (row - 2);// 초기 yellow 개수 (col-2, col-2)로 대체 가능
            while (1) {
                if (yellow == ycnt) {// yellow 개수가 같은데
                    if (brown + yellow == (row * col)) { // 전체 블록개수도 같으면
                        answer.push_back(row); //가로
                        answer.push_back(col); //세로 
                        break;
                    }

                }
                ycnt += (cnt);// yellow 개수가 아니면 yellow개수 증가
                row++;// 가로 증가
                if (ycnt > yellow) //만약에 내가 구한 yellow개수가 찾고자 하는 yellow개수보다 크면 못구하므로 break;
                    break;
            }
        }
    }
    return answer;
}
