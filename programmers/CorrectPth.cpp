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
/*
올바른 괄호 -> Stack 사용! stack에는 열린 괄호를 넣어주고, 닫힌 괄호를 
만나면 현재 index에 열린 괄호가 있으면 비워주기
*/
using namespace std;
string stack = ""; // string을 쓴 이유는 push, pop을 제공해주기 떄문에.. 배열을 쓰면 push, pop함수 만들어줘야함

// Peek()함수는 가장 위에 있는 문자를 반환
char Peek() { 
    return stack[stack.size()-1];
}
bool solution(string s){
    bool answer = true;
    for (int i = 0; i < s.size(); i++) {
        if (stack.empty()) // stack이 비워있으면 무조건 넣어줘야함 ( why? 비교를 해야하므로)
            stack.push_back(s[i]);
        else {
            if (Peek() == '(') { // stack에서 가장 위에 있는 문자가 열린 문자인데
                if (s[i] == ')') // 현재 문자열이 닫힌 문자를 가지고 있으면 꺼내준다.( 괄호가 바르게 짝지어졌으므로)
                    stack.pop_back();
                else // 현재 문자열이 열린 문자면 stack에 넣어주기
                    stack.push_back(s[i]);
            }
            else // stack에서 가장 위에 있는 문자가 닫힌 문자면 그대로 넣어주기
                stack.push_back(s[i]);
        }
    }

    if (!stack.empty()) // 괄호를 다 check해봤는데 stack에 괄호가 남아있으면 올바른 괄호가 아닌 것들이므로 false
        answer = false;

    return answer;
}
