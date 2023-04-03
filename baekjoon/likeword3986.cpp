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
* 좋은 단어
*/
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<char>st;
	string name;
	int n,cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name;
		for (int j = 0; j < name.size(); j++) {
			if (st.empty()) {
				st.push(name[j]);
				continue;
			}
			else {
				if ((name[j] == 'A' && st.top() == 'A') ||(name[j] == 'B' && st.top() == 'B')) {
					st.pop();
				}
				else
					st.push(name[j]);
			}
		}
		if (st.empty()) {
			cnt++;
		}
		while (!st.empty()) {
			st.pop();
		}
	}
	cout << cnt;
}

