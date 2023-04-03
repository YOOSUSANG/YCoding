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
/*
* 괄호의 값
*/
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<pair<char,int>>st;
	stack<char>ch;
	string in;
	int sum=0,cnt=1; // 총합, 누적 개수
	cin >> in;
	//우선 올바른 괄호인지 check
	for (int i = 0; i <in.size(); i++) {
		if (ch.empty()) {
			ch.push(in[i]);
			continue;
		}
		else {
			if ((in[i] == ')' && ch.top() == '(')|| (in[i] == ']' && ch.top() == '[')) {
				ch.pop();
			}
			else
				ch.push(in[i]);
		}
	}
	//올바른 괄호가 아니면 0
	if (!ch.empty()) {
		cout << 0;
		return 0;
	}
	//올바른 괄호면 값 구하기
	for (int i = 0; i < in.size(); i++) {
		if (in[i] == ')' || in[i]==']') { // 닫힌 괄호인데
			if (i - 1 == st.top().second) // index차이가 1이면 더해주기
				sum += cnt;
			if (in[i] == ')') {// *2했으니까 /2로 없애기			
				cnt /= 2;
			}
			else if (in[i] == ']') { // *3했으니가 /3으로 없애기
				cnt /= 3;
			}
			st.pop();
		}
		else {
			if (in[i] == '(') {
				cnt *= 2;
				st.push(make_pair(in[i],i));
			}
			else if (in[i] == '[') {
				cnt *= 3;
				st.push(make_pair(in[i],i));
			}
		}
	}
	cout << sum;
}

