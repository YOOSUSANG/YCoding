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
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int,int>>st;
	vector<int>vec; // 기록저장
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;

		while (1) {
			//stack이 비워져있으면 추가해야한다.
			if (st.size() == 0) {
				vec.push_back(0); //신호를 받을 수 있는 탑이 존재하지 않는다.
				st.push(make_pair(num, i + 1)); // stack에 넣기
				break;
			}
			//만약 자기가 더 크면 stack에 있는거는 더 이상 볼 필요가 없으므로 pop처리 
			if (st.top().first < num) {
				st.pop();
			}
			//자기보다 큰 탑을 발견했으면 바로 기록한다.
			else {
				if (st.top().first >= num) {
					vec.push_back(st.top().second);
					st.push(make_pair(num, i + 1));
					break;
				}
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
}
