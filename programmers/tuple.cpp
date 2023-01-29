#include <vector>
#include<string.h>
#include<sstream>
#include <stdbool.h>
#include <algorithm>
#include <stdlib.h>
#include<map>
using namespace std;
bool compare(pair<vector<int>, int> a, pair <vector<int>, int> b) {
    return a.second < b.second; //value값 비교
}

vector<int> solution(string s) {
    vector<int> answer; // 답을 저장하는 것
    map<int,int>m; // 중복체크를 방지하는 것
    map<vector<int>,int>res; // {}, {}의 크기를 저장하는 map
    vector<vector<int>>vec(100001); // {}안에 있는 내용들을 저장하는 것
    string rep; // {}안에 있는 내용들을 저장하는 것
    int cnt = 0; // count 숫자

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '}' || s[i] == ',') {
            if (s[i] == '}' && rep.size() != 0) {
                vec[cnt].push_back(stoi(rep));
                cnt++;
            }
            else if (s[i] == ',' && rep.size() != 0) {
                vec[cnt].push_back(stoi(rep));
            }
            rep.clear();
        }
        else if (s[i] != '{') {
            rep.push_back(s[i]);
        }
    }
    //정렬을 위해서 map으로 저장한다.
    for (int i = 0; i < cnt; i++) {
        res.insert(make_pair(vec[i], vec[i].size()));
    }
    vector<pair<vector<int>, int>> v(res.begin(), res.end()); //map을 vector로 전환
    sort(v.begin(), v.end(), compare);

    //처음 넣기
    m.insert(make_pair(v[0].first[0], v[0].second));
    answer.push_back(v[0].first[0]);

    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < v[i].second; j++) {
            //중복된 숫자가 없으면 새로운 숫자라서 넣어준다.
            if (m.count(v[i].first[j]) == 0) {
                m.insert(make_pair(v[i].first[j], v[i].second));
                answer.push_back(v[i].first[j]);
                break;
            }
        }
    }
    return answer;
}
