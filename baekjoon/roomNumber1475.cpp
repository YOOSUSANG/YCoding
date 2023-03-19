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
using namespace std;
int Max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[10] = { 0, };
	int num, max = 0;
	cin >> num;
	while (1) {
		int digits = num % 10;
		if (digits == 9 || digits == 6) { // 동일하게 처리
			if (arr[9] == arr[6]) { // 둘 다 빈 상태
				arr[9]++; // 고정
			}
			else
				arr[6]++; // 고정
		}
		else {
			arr[digits]++;
		}
		num /= 10;
		if (num == 0)
			break;
	}
	for (int i = 0; i < 10; i++) {
		max = Max(max, arr[i]);
	}
	cout << max;
}
