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
* 커서는 문장 뒤에 위치! erase 사용법 숙지!
*/
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt;
	char ac,tion;
	string ans;
	list<char>a;
	cin >> ans;
	cin >> cnt;
	for (int i = 0; i < ans.size(); i++) {
		a.push_back(ans[i]);
	}
	list<char>::iterator cur = a.begin();
	for (int i = 1; i <= ans.size(); i++) {
		cur++;
	}

	for (int i = 0; i < cnt; i++) {
		cin >> ac;
		if (ac == 'L') {
			if(cur!=a.begin()) // 맨 앞이 아닌 경우 커서 이동 가능
				cur--;
		}
		else if (ac == 'D') { // 맨 뒤가 아닌 경우 커서 이동 가능
			if(cur!=a.end())
				cur++;
		}
		else if (ac == 'B') {
			if (cur != a.begin()) { // 맨 앞이 아닌 경우 제거 가능
				cur--; // 왼쪽으로 옮겨주고
				a.erase(cur++); // 왼쪽 제거 후 다시 오른쪽으로 넘어간다.
			}
		}
		else if (ac == 'P') { // 커서 왼쪽에 추가
			cin >> tion;
			a.insert(cur, tion);
		}
	}
	for (auto iter = a.begin(); iter != a.end(); iter++) {
		cout << *iter;
	}
}
