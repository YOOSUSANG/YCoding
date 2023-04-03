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
/*
* 괄호
*/
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<char>st;
	string name;
	int n,cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name;
		for (int j = 0; j < name.size(); j++) {
			if (st.empty()) {
				st.push(name[j]);
				continue;
			}
			else {
				if (name[j] == ')') {
					if (st.top() == '(') {
						st.pop();
					}
					else
						st.push(name[j]);
				}
				else
					st.push(name[j]);
			}
		}
		if (st.empty()) {
			cout << "YES" << "\n";
		}
		else
			cout << "NO" << "\n";

		while (!st.empty()) {
			st.pop();
		}
	}
}

