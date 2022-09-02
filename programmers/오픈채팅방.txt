#include <string>
#include <vector>
#include<sstream>
#include<map>
using namespace std;
vector<string> solution(vector<string> record) {
    vector<string> answer; //결과를 저장하는 것
    map<string, string>m;
    vector<string>str;
    string sub_Str;
    string action;
    string id;
    int len;
    for (auto i = record.begin(); i != record.end(); i++) {
        //공백기준으로 구분하기 위해서 istringstream 사용
        istringstream ss(*i);
        len = 0;
        while (getline(ss, sub_Str, ' ')) {// 공백기준으로 자름 자른 문자열들은 sub_Str에 저장된다.
            //첫 문자열은 Enter, Leave, Change, 두번쨰 문자열은 아디, 세번쨰 문자열은 이름
            if (len == 0) {
                action = sub_Str;
            }
            else if (len == 1) {
                id = sub_Str;
                if (action == "Leave")
                    str.push_back("님이 나갔습니다.");

            }
            else {
                if (action == "Enter") {
                    str.push_back("님이 들어왔습니다.");
                    if (m.count(id)==1) { //이미 키값이 존재하면 이전꺼 바꾸기
                        m.erase(id);//지우고
                        m.insert(make_pair(id, sub_Str));//추가하기
                    }else
                        m.insert(make_pair(id, sub_Str));//추가하기
                        
                    
                }
                else if (action == "Change") {
                    m.erase(id);
                    m.insert(make_pair(id, sub_Str));
                }
            }
            len++;
        }
    }
    int key = 0;
    for (auto i = record.begin(); i != record.end(); i++) {
        //공백기준으로 구분하기 위해서 istringstream 사용
        istringstream ss(*i);
        len = 0;
        while (getline(ss, sub_Str, ' ')) {// 공백기준으로 자름 자른 문자열들은 sub_Str에 저장된다.
            //첫 문자열은 Enter, Leave, Change, 두번쨰 문자열은 아디, 세번쨰 문자열은 이름
            if (len == 0) {
                action = sub_Str;
            }
            else if (len == 1) {
                id = sub_Str;
                if(action == "Change")
                    break;
                
                if (m.count(id)==1)
                    answer.push_back(m[id] + str[key++]);
            }
            len++;
        }
    }
    return answer;
}
