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
* AC 뒤집기 과정에서 덱 성질을 이용해서 front, back pop 핵심
*/
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t,n,num=0,ch,er; // ch은 뒤집기, er는 error 발생했느지 안했는지
	string func, array;
	deque<int>dq;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> func; // RDD
		cin >> n; // 4
		cin >> array; // [1,2,3,4]
		ch = 0; // ch -> 1 역방향 / -> 0 순방향
		er = 0;
		//숫자만 뺴서 덱이 저장하기
		for (int j = 1; j < array.size() - 1; j++) {
			if (array[j] == ',' || j == array.size()-2) {
				if(j == array.size()-2)
					num = num * 10 + array[j] - '0';
				dq.push_back(num);
				num = 0;
				continue;
			}
			num = num * 10 + array[j] - '0';
		}

		for (int j = 0; j < func.size(); j++) {
			if (func[j] == 'R') {
				if (ch == 0)
					ch = 1;
				else if (ch == 1)
					ch = 0;
			}
			else if (func[j] == 'D') {
				if (dq.empty()) {
					cout << "error" << "\n";
					er = 1;
					break;
				}
				if (ch == 1)
					dq.pop_back();
				else if (ch == 0)
					dq.pop_front();
				
			}
		}
		if (er==0) {
			cout << "[";
			if (ch == 1) {
				for (int j = dq.size()-1; j>=0; j--) {
					if (j == 0)
						cout << dq[j];
					else
						cout << dq[j] << ",";
				}
			}
			else {
				for (int j = 0; j < dq.size(); j++) {
					if (j == dq.size() - 1)
						cout << dq[j];
					else
						cout << dq[j] << ",";
				}
			}
			cout << "]" << "\n";
			dq.clear();
		}
	}
}
