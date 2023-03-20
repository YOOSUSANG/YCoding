#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<sstream>
#include <stdbool.h>
#include <algorithm>
#include <stdlib.h>
#include<map>
#include <unordered_map>
#include<deque>
#include<list>
/*
* segfault runtime error가 나왔는데, 이중 반복문에서 같은 이름의 변수를 써서 error가 나왔다.
*/
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt;
	string ans;
	list<char>a;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> ans;
		list<char>::iterator cur;
		for (int j = 0; j < ans.size(); j++) {
			if (ans[j] == '<') {
				if (a.size() == 0)
					continue;

				if (cur != a.begin())
					cur--;
			}
			else if (ans[j] == '>') {
				if (a.size() == 0)
					continue;

				if (cur != a.end())
					cur++;
			}
			else if (ans[j] == '-') {
				if (a.size() == 0)
					continue;

				if (cur != a.begin()) {
					cur--;
					a.erase(cur++);
				}
			}
			else {
				if (a.size() == 0) {
					a.push_back(ans[j]);
					cur = a.begin();
					cur++;// 문자 뒤로 이동하기
				}
				else {
					a.insert(cur, ans[j]);
				}
			}
		}
		for (auto iter = a.begin(); iter != a.end(); iter++) {
			cout << *iter;
		}
		cout << "\n";
		a.clear();
	}
}
