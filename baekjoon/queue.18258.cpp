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
	int n, num;
	string action;
	queue<int> que;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> action;
		if (action == "push") {
			cin >> num;
			que.push(num);
		}
		else if (action == "pop") {
			if (que.empty())
				cout << "-1"<<"\n";
			else {
				cout << que.front()<<"\n";
				que.pop();
			}
		}
		else if (action == "size") {
			cout << que.size() << "\n";
		}
		else if (action == "empty") {
			if (que.empty()) {
				cout << "1" << "\n";
			}
			else
				cout << "0" << "\n";
		}
		else if (action == "front") {
			if (que.empty())
				cout << "-1" << "\n";
			else
				cout << que.front() << "\n";

		}
		else if (action == "back") {
			if (que.empty())
				cout << "-1" << "\n";
			else
				cout << que.back() << "\n";
		}
	}
}
