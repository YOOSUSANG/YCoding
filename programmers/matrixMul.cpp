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
using namespace std;
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer; // 답
    vector<int> colvec1;  // arr1에 해당하는 열벡터
    vector<int> colvec2; //  arr2에 해당하는 열벡터
    // ->순으로 저장 ( 곱해지는 순서 )
    for (int i = 0; i < arr1.size(); i++) { // 세로
        for (int j = 0; j < arr1[i].size(); j++) { // 가로
            colvec1.push_back(arr1[i][j]);
        }
    }
    // 아래순으로 저장 ( 곱해지는 순서 )
    for (int i = 0; i < arr2[0].size(); i++) { // 가로
        for (int j = 0; j < arr2.size(); j++) {// 세로
            colvec2.push_back(arr2[j][i]);
        }
    }
    int check = 0; // arr1에 해당하는 열벡터에 index
    int sum = 0; // 합
    int i; // index 증가
    while (1) {
        vector<int>rep; // 저장 vector
        i = 0;
        for (int j = 0; j < colvec2.size(); j++) {
            sum += colvec1[(i % arr2.size()) + check] * colvec2[j];
            i++;
            if (i == arr2.size()) {
                rep.push_back(sum);
                sum = 0;
                i = 0;

            }
        }
        answer.push_back(rep);
        check += arr2.size();
        if (check >= colvec1.size())
            break;
    }
    return answer;
}
