#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
/* N개의 최소공배수
*/

//최대 공약수를 구하는 알고리즘
int gcd(int a, int b) {
    while (1) {
        int c = a % b;
        if (c == 0)
            return b;
        a = b;
        b = c;
    }
}
int solution(vector<int> arr) {
    int answer = 1; //공통이 되는 최소공배수
    int cnt=1;// index 증가
    /*
    * 생각한 로직은 각 index 자리에 최소가 될 수 있는 수들을 갱신해준다.
    * 3 6 12가 있다면 1 2 4 -> 1 1 2 이런식으로 해당 index 자리를 갱신
    */
    while (1) {
        int n1 = arr[cnt-1]; //0부터 시작이므로 cnt-1
        arr[cnt-1] = 1;// 자기자신을 자기자신으로 나누면 1이므로 1저장 
        answer *= n1;// 최대공약수 곱해주기
        //cnt부터 자리수 갱신
        for (int i = cnt; i < arr.size(); i++) {
            int num = gcd(n1, arr[i]); //최대 공약수 구하기
            arr[i] = arr[i] / num;// 각 자리수 갱신 수/최대 공약수
        }
        cnt++; // 다음 index탐색을 위한 cnt++
        if (cnt == arr.size()) // 탐색을 다했으면 break
            break;
    }
    // 갱신된 각 자리수를 곱해서 저장하기
    for (int i = 0; i < arr.size(); i++) {
        answer *= arr[i];
    }

    return answer;
}
