#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int solution(vector<int> elements) {
    int answer = 0;
    int sum, head, tail; // 합계, 앞쪽, 뒤쪽
    map<int, int> m; // 중복 방지
    for (int i = 1; i <= elements.size(); i++) {
        head = 0; // 시작점
        tail = 1;// 끝점
        sum = elements[0]; // 처음에 index = 0 부분을 저장한다.
        while (1) {
            if (tail - head == i) { //간격이 i면
                m.insert(make_pair(sum, 0)); // sum 넣기
                cout<<"길이: "<<i<<"  "<<"합계: "<<sum<<"  "<<"map 크기:"<<m.size()<<endl;
                sum -= elements[head]; // 앞쪽 뺴주기
                head++; //앞쪽 증가 (시작하는 기준점을 바꿔줌)
                if (head == elements.size()) // 끝까지 다 돌았으면 끝(기준점이 elements.size()면)
                    break;
            }
            sum += elements[tail % elements.size()]; // tail은 원형탐색이므로 % elements.size()로 처리해서 인덱스 범위를 못넘어가게 한다.
            tail++;
        }
    }
    answer = m.size();
    return answer;
}
