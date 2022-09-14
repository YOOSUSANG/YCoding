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
A, B의 누적된 값이 최솟값이 될라면 오름차순정렬, 내림차순 정렬 후 둘이 곱해서 결과를 가져오면
된다.( 제일 작은거 * 제일 큰거 )
*/
using namespace std;
// temp함수는 내림차순을 위한 함수 -> a > b가 false면 교환
int temp(int a, int b) {
    return a > b;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end()); // 오름차순 정렬
    sort(B.begin(), B.end(), temp); // 내림차순 정렬
    for (int i = 0;i < A.size(); i++) {
        answer += A[i] * B[i];
    }
    return answer;
}
