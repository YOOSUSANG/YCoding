#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int Max(int a,int b){
    return a>b?a:b;
}
int solution(vector<int> citations) {
    int answer = 0;
    int max,min;
    for(int h=10000;h>=0;h--){ // 큰 수부터 시작 최대값인 h-index를 구하는 것이므로
        max=0;
        min=0;
        for(int j=0;j<citations.size();j++){
            if(h<=citations[j]){ // i보다 크거나 같으면
                max++; // 이상 증가
            }else{ // i보다 작으면 
                min++;// 이하 증가
            }
        }
        if(max>=h && h>min){// 찾은 i가 i이상 인용됐고 i이하 인용됐으면 저장해주기.
            answer=h; // 저장 후 break; 
            break;
        }
    }
    return answer;
}
