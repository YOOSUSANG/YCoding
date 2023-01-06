#include <string>
#include <vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> p1, pair<int, int>p2) {
	if (p1.second == p2.second) { // 차이가 같으면 숫자가 내림차순으로 정렬
		return p1.first > p2.first;
	}else // 차이가 다르면 차이 값으로 오름차순으로 정렬
		return p1.second < p2.second; 

}
vector<int> solution(vector<int> numlist, int n) {
	vector<int> answer;
	vector<pair<int, int>> vec;
	for (int i = 0; i < numlist.size(); i++) {
		vec.push_back(make_pair(numlist[i], abs(n - numlist[i])));
	}
	sort(vec.begin(), vec.end(), compare);
	for (auto iter = vec.begin(); iter != vec.end(); iter++) {
		answer.push_back(iter->first);
	}
	return answer;
}
