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
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int>stack;
	int n,num,sum=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
			if (stack.size() != 0)
				stack.pop();
		}
		else
			stack.push(num);
	}
	while (!stack.empty()) {
		sum += stack.top();
		stack.pop();
	}
	cout << sum;

}
