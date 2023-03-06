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
int Max(int a, int b) {
    return a > b ? a : b;
}
vector<vector<int>>newDungeons; //copy
int check[9] = { 0, }; // 확인한 던전 check
int answer;
int cnt = 0;
void dfs(int k) {
    for (int j = 0; j < newDungeons.size(); j++) {
        //한번도 탐험하지 않은 던전이고 최소 필요 피로도보다 크거나 같으면
        if (check[j] == 0 && k >= newDungeons[j][0]) {
            check[j] = 1; // 해당 던전 탐색 완료
            k -= newDungeons[j][1]; // 피로도 감소
            cnt++; // 던전 개수 증가
            answer = Max(answer, cnt); // max값 저장
            dfs(k); // 다음 던전 탐색을 위한 dfs

            // 탐색이 끝나거나 조건이 충족되지 않으면
            check[j] = 0;
            k += newDungeons[j][1];
            cnt--;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    answer = 0;
    //2차원 vector 복사
    newDungeons.assign(dungeons.size(), vector<int>(dungeons.size()));
    copy(dungeons.begin(), dungeons.end(), newDungeons.begin());
    //탐색 시작
    dfs(k);
    return answer;
}
