#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
/*
점프와 순간 이동 재귀
*/
int jump(int n) {
    if (n==0)
        return 0;
    else if (n == 1 || n == 2) // 어차피 한칸, 2칸(순간이동)으로 모든 것이 반복됨
        return 0;
    else
        return jump(n / 2) + jump(n % 2); //한칸 갈건지 아니면 순간이동할지
}
int solution(int n) {   
    int ans = 0;
    ans = jump(n);
    return ans;
}
