#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<string.h>
#include <stdbool.h>
#include <stdlib.h>
#include<map>
/*
124 나라의 숫자 규칙을 보면 3으로 나눈 몫, 나머지를 활용해서 푼다. 이때 3의 배수일 경우는 나머지가 0이므로 무조건 4로 고정시켜주고,
몫을 구한 값에서 -1을 해줘서 다시 반복해준다.
*/
using namespace std;
string solution(int n) {
    string answer = "";//결과
    string OTF = "124"; //124로만 표현할 수 있으므로 124로 string을 초기화 시켰다. index는 0부터 시작!
    string re = "";//나머지 연산의 값들이 들어가는 것 후에 뒤에서 꺼내기 위함
   
    while (1) {
        re.push_back(n % 3);//우선 나머지 저장
        if (n % 3 == 0) { //만약 3의 배수면 3으로 나눈 다음에 -1해준다.
            n /= 3;
            n -= 1;
        }else //3의 배수가 아니면 3으로 나눈다.
            n /= 3;

        if (n <= 3) {// n이 0,1,2,3에 속하면 이제 반복할 의미가 없으므로 break해준다. OTF index에 매핑될 수 있으니까
            if (n != 0)//이떄 0이 아닌 경우만 1,2,4가 될 수 있으므로 넣어주기.(0이면 -1시 메모리 범위 넘어감) 이떄 -1을 해준 이유는 OTF index에 맞추려고!
                answer.push_back(OTF[(n)-1]);
            break;
        }   
    }
    for (int i = re.size() - 1; i >= 0; i--) {//가장 최근꺼는 vector뒤에 저장돼있으므로 뒤로부터 탐색
        if (re[i] == 0)//0이면 아까 설명한 것 처럼 4로 바꿔줘야함
            answer.push_back(OTF[2]);
        else // 1,2,3 이면 인덱스에 맞춰야 하므로 -1을 해준다. OTF[0] = '1', OTF[1] = '2', OTF[2] = '4';
            answer.push_back(OTF[re[i] - 1]);
    }
    return answer;
}
