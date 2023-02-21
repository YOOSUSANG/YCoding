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
int answer;
vector<int>vec; // 전역으로 사용하기 위한 vec
void dfs(int i,int sum,int target) {
    if (i == vec.size()) {// index 끝까지 다 돌았으면
        if (sum == target)
            answer++;
        return;
    }else if (i > vec.size())// size크기를 넘었으면 
        return;
    dfs(i + 1, sum - vec[i], target);// -
    dfs(i + 1, sum + vec[i], target);// +

}
