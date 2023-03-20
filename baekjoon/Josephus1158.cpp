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
* 다음 단계로 갔는데 end에 도달했으면 begin으로 변경해야함
* 만약 begin으로 변경하지 못하면 end++이므로 오류남
*/
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	list<int>a;
	vector<int>rep;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		a.push_back(i);
	}
	list<int>::iterator cur = a.begin();
	while (!a.empty()) {
		for (int i = 1; i < k; i++) {
			cur++;
			if (cur == a.end()) {
				cur = a.begin();
			}
		}
		rep.push_back(*cur);
		a.erase(cur++); // cur을 제거 후 cur++로 이동
		if (cur == a.end()) {
			cur = a.begin();
		}
	}
	cout << "<";
	for (int i = 0; i < rep.size(); i++) {
		cout << rep[i];
		if (i != rep.size() - 1)
			cout << ", ";
	}
	cout << ">";
}
