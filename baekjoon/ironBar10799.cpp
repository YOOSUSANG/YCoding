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
* 쇠막대기
*/
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<pair<char,int>>st;
	string in;
	int sum=0, cnt=0; // 총합, 누적 개수
	cin >> in;
	for (int i = 0; i < in.size(); i++) {
		if (in[i] == '(') { // 여는 괄호면 레이저 or 막대기 시작
			cnt += 1;// 누적 개수 증가
			sum += 1;// 막대기 개수 하나 추가
			st.push(make_pair(in[i], i));
		}
		else if (in[i] == ')') {// 닫힌 괄호면 레이저 or 막대기 끝
			//레이저면 (index차이가 1밖에 안나면 레이저이다.)
			if (st.top().second == i - 1) {
				sum--;//막대기가 아니므로 막대기 개수 감소
				cnt--;// 막대기가 아니므로 누적 막대기 개수 감소
				sum += cnt; // 누적개수 더해주기
				st.pop();//지우기
			}
			else { //레이저가 아니면 cnt 감소 후 지우기
				cnt--; // 막대기 감소
				st.pop();// pop
			}
		}
	}
	cout << sum;
}

