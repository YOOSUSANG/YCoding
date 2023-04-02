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
	stack<char>st;
	string input;
	while (1) {
		getline(cin, input);
		if (input == ".")
			break;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(' || input[i] == '[') {
				st.push(input[i]);
			}
			else if (input[i] == ')' || input[i] == ']') {
				if (st.empty()) {
					st.push(input[i]);
					continue;
				}
				if (input[i] == ')') {
					if (st.top() == '(') {
						st.pop();
					}else
						st.push(input[i]);
				}
				else if (input[i] == ']') {
					if (st.top() == '[') {
						st.pop();
					}
					else
						st.push(input[i]);
				}
			}
		}
		if (st.empty()) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
		while (!st.empty()) {
			st.pop();
		}
	}
}

