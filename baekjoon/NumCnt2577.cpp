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
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c,sum;
	int arr[10] = { 0, };
	cin >> a >> b >> c;
	sum = a * b * c;
	while (1) {
		arr[sum % 10]++;
		sum /= 10;
		if (sum == 0)
			break;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << "\n";
	}
}
