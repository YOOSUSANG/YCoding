#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> vec;
    if (cacheSize == 0) { //cache size가 0이면 all miss
        return 5 * cities.size();
    }
    for (int i = 0; i < cities.size(); i++) {
        //소문자, 대문자 -> 소문자로
        transform(cities[i].cbegin(), cities[i].cend(), cities[i].begin(), towlower); 
        
        int size = vec.size(); // miss인지 판별하기위해서 만약 vector Size랑 같지 않으면 이미 제거된거라 if문 들어가지 않음
        //vector을 도는데 도시이름이 있으면 hit
        for (int j = 0; j < vec.size(); j++) { 
            if (vec[j] == cities[i]) { 
                answer += 1;
                vec.erase(vec.begin() + j); // 해당자리제거 (hit 된거)
                break;
            }
        }
        //Size(이전 vector size)와 현재 vec Size랑 같으면 즉 hit가 발생하지 않았으면
        if (size == vec.size()) {
            answer += 5; // miss 발생인데
            if(vec.size()==cacheSize) // 현재 vector size가 다 찼으면 LRU 알고리즘으로 인해 오래된 캐시 제거  
                vec.erase(vec.begin() + 0);
        }
        vec.push_back(cities[i]); // 넣어주기
    }
    return answer;
}
