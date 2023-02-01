#include <vector>
#include<string.h>
#include<sstream>
#include <stdbool.h>
#include <algorithm>
#include <stdlib.h>
#include<map>
#include<stack>
using namespace std;
int Max(int a, int b) {
    return a > b ? a:b;
}
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long i = left; i <=right; i++) {
        answer.push_back(Max(i % n, i / n) + 1);

    }
    return answer;
}
