#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<string.h>
#include<sstream>
#include <stdbool.h>
#include <stdlib.h>
#include<map>
#include<algorithm>
using namespace std;
/*
* 짝지어 제거하기 stack
*/
int solution(string s){
    int answer;
    string st;
    for (int i = 0; i < s.size(); i++) {
        if (i == 0)
            st.push_back(s[i]);
        else {
            if (st.back() == s[i])
                st.pop_back();
            else
                st.push_back(s[i]);
        }
    }
    if (st.empty())
        answer = 1;
    else
        answer = 0;

    return answer;
}

