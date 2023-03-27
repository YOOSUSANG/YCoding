#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <stdbool.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <unordered_map>
#include <deque>
#include <list>
#include <stack>
#include <queue>
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,rep;
	queue<int> que;
	cin >> n;
	for (int i = 0; i < n; i++) {
		que.push(i + 1);
	}
	while (1){
		if (que.size() == 1) // queue에 한개만 남았으면
			break;

		que.pop();//제일 위 꺼내기
		rep = que.front();// 그 다음 윗장
		que.pop();// 그 다음 윗장 꺼내기
		que.push(rep);// 그 다음 윗장을 아래에 넣기
	}
	cout << que.front();
}
