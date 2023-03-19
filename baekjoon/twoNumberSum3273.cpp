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
int arr[2000001] = { 0, };
/*
* OutOfBounds -> 음수부분을 고려하지 못했음
* 절댓값 쓰면 안됨 -> 10-11 = -1인데 abs을 쓰면 1로 처리돼서 안된다.
*/
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int>vec;
	int n, x,num,cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vec.push_back(num);
	}
	cin >> x;
	for(int i = n-1; i >= 0; i--) {
		if (x - vec[i] >= 0) {
			if (arr[x-vec[i]] == 1)
				cnt++;
			arr[vec[i]] = 1;

		}
	}
	cout << cnt;

}
