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
	int n, num, t, rep,idx=0,total=0;
	string action;
	deque<int> dq;
	cin >> n >> num;
	for (int i = 0; i < n; i++) {
		dq.push_back(i + 1);
	}
	for (int i = 0; i < num; i++) {
		cin >> t;
		if (dq.front() == t) {
			dq.pop_front();
		}
		else {
			//t의 index 찾기(왼쪽기준)
			for (int j = 0; j < dq.size(); j++) {
				if (dq[j] == t) {
					idx = j;
					break;
				}
			}
			//왼쪽으로 가는게 최소면 왼쪽 이동
			if (idx < dq.size() - idx) {
				for (int j = 0; j < idx; j++) {
					rep = dq.front();
					dq.pop_front();
					dq.push_back(rep);
				}
				total += idx;
				dq.pop_front();

			}
			else { // 아니면 오른쪽 이동
				for (int j = 0; j < dq.size() - idx; j++) {
					rep = dq.back();
					dq.pop_back();
					dq.push_front(rep);
				}
				total += dq.size() - idx;
				dq.pop_front();
			}
		}
	}
	cout <<total;
}
