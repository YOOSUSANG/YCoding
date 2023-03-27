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
	deque<int> dq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> action;
		if (action == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (action == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (action == "pop_front") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout<<dq.front()<<"\n";
				dq.pop_front();
			}
		}
		else if (action == "pop_back") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (action == "size") {
			cout << dq.size() << "\n";
		}
		else if (action == "empty") {
			if (dq.empty()) {
				cout << "1" << "\n";
			}
			else
				cout << "0" << "\n";
		}
		else if (action == "front") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else
				cout << dq.front() << "\n";

		}
		else if (action == "back") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else
				cout << dq.back() << "\n";
		}

	}
}
