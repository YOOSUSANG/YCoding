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
using namespace std;
/*
* 반례     8
     2 4 7 5 3 1 8 6 
*/
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int>stack;
	string print;
	int n, num, preNum=0,asc=0; // preNum -> 이전 값, ase -> 오름차순 값
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (preNum < num) {
			//오름차순을 지키지 못했으면
			if (num <= asc) {
				cout << "NO";
				return 0;
			}
			for (int j = asc+1; j <= num; j++) {
				stack.push(j);
				print.push_back('+');
			}
			asc = num; // 오름차순 저장
			print.push_back('-');
			stack.pop();

		}
		else {
			while (1) {
				/*
				top 확인 전에 더 이상 stack에서 꺼낼 수 없으면 num이 stack에 존재하지 않으므로 만약 8까지 도달해서 8만 있고 이후 6이라는 숫자가
				들어오면 pop 불가능
				*/
				if (stack.empty()) {
					cout << "NO";
					return 0;
				}
				if (num == stack.top()) {
					print.push_back('-');
					stack.pop();
					break;
				}
				print.push_back('-');
				stack.pop();
			}
		}
		preNum = num;
	}
	for (int i = 0; i < print.size(); i++) {
		cout << print[i] << "\n";
	}
}
