#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>
#include<sstream>
#include <stdbool.h>
#include <algorithm>
#include <stdlib.h>
#include<map>
#include<stack>
#include <math.h>
using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int>time;
    stack<int> st;
    for (int i = 0; i < progresses.size(); i++) {
        time.push_back(ceil((100 - (double)progresses[i]) /speeds[i]));
    }
    //stack 사용을 위해 뒤에서부터 저장
    while (time.size()!=0) {
        st.push(time.back());
        time.pop_back();
    }
    int head = st.top(); // 처음 걸리는 날짜
    st.pop(); // 스택 비우기
    int cnt = 1; // 개수
    while (st.size()!=0) {
        if (st.top() <= head) { //자기보다 오래 안걸렸으면 같이 배포가능능
            cnt++;
        }
        else { //자기보다 오래 걸렸으면 배포가 불가능
            answer.push_back(cnt); // 개수 넣기
            cnt = 1;// 갱신
            head = st.top() ; // 갱신 
        }
        st.pop();
    }
    answer.push_back(cnt);
    return answer;
}
