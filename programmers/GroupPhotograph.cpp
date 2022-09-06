#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<string.h>
#include<map>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<string>cdata; //복사본
vector<int>vec; // 차이를 저장해주는 벡터
map<char, int>m;// 각 문자마다 지정된 번호 ex ACFJMNRT 라고 있으면 A는 1번쨰, C는 2번쨰로 가정
string names;// 8명의 친구들을 저장하는 것 
int ch[8];// 중복을 방지하는 배열 ( 연속적으로 배열에 못 들어감) AA >> X 
int answer;//개수
int cnt;// 각 문자마다 지정된 번호를 카운팅하는 변수
void check(int k) {
    ch[k] = 1;//방문체크
    if (m.size() == 8) { // map size가 다 찼으면 주어진 조건이 성립하는지 확인해준다.
        for (int i = 0; i < cdata.size(); i++) { //각각의 차이들을 다 넣어준다. 이떄 사이에 있는 사람 수이므로 -1을 해줘야함 
            vec.push_back(abs(m[cdata[i][0]] - m[cdata[i][2]]) - 1); //abs라는 절댓값 함수를 취해 -가 안나오도록 만듬

        }
        //이제 연산 등호에 따라서 조건이 성립되는지 확인해줘야한다. 내가 구현한 방식은 다르면 바로 return을 떄리는 방법을 썼다.
        for (int i = 0; i < vec.size(); i++) {
            if (cdata[i][3] == '=') { //등호가 = 인데
                if (cdata[i][4]-'0' != vec[i]) {//원하는 간격과 배치된 간격이 다르면 
                    vec.clear();// 차이들을 다 초기화 시켜주고 다시 map이 다 차면 또 vector에 넣어주기 위해 clear()함
                    return;
                }
            }
            else if (cdata[i][3] == '<') { // 등호가 < 인데
                if (cdata[i][4]-'0' <= vec[i]) { // 원하는 간격이 배치된 간격보다 작거나 같으면 성립되지 않음 
                    vec.clear();
                    return;
                }

            }
            else if (cdata[i][3] == '>') { //등호가 > 인데
                if (cdata[i][4]-'0' >= vec[i]) { //원하는 간격이 배치된 간격보다 크거나 같으면 성립x
                    vec.clear();
                    return;
                }
            }
        }
        //모든 경우의 수를 뚫고 여기까지 왔으면 결국 성립하므로 개수를 증가 시킨다.
        answer++;
        vec.clear(); //다른 경우의 수를 구하기 위해서 vec를 초기화
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (ch[i] == 0) { // 방문하지 않은 친구면
            m.insert(make_pair(names[i], cnt++)); //순서를 부여하여 map에 저장

            check(i); // 다시 check(int k)에 들어간다.
            
            //check(i)함수가 끝났다는 것은 map에 8명이 다 찼으므로 재조정 해줘야함
            m.erase(names[i]); //현재 방문한 사람 뺴주기
            cnt--;// 순서 감소
            ch[i] = 0; // 현재 방문한 사람을 뺴줬으니까 상태를 변경해준다. 0은 방문 하지않음, 1은 방문함
        }
    }

}
int solution(int n, vector<string> data) {
    answer = 0;
    cnt = 1;
    names = "ACFJMNRT";// 8명의 친구들
    memset(ch, 0,8*sizeof(int)); // memset을 통해 공간을 할당 ch을 모두 0으로 초기화( 0은 방문 하지 않음)
    cdata.resize(data.size());// data를 쓰기 위해서 cdata 크기 재조정
    copy(data.begin(), data.end(), cdata.begin());// 복사
    for (int i = 0; i < names.size(); i++) {
        m.insert(make_pair(names[i], cnt++)); //순서번호 부여 이떄 번호 1를 부여함 (처음부터 시작하므로)
        check(i);
        ch[i] = 0;// 방문하지 않음을 표시 (A부터 시작한게 끝났으므로)
        cnt--; // 순서 감소
        m.erase(names[i]); // map에서 제거
        
    }
    return answer;
}

