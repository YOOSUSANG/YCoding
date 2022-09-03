#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int Max(int a, int b) {
    return a > b ? a : b;
}
int** check = new int* [101]; //방문 체크를 확인하는 것 (이미 갔던 길 방문x) 2차원으로 만들기
queue<pair<int, int>>que; // 큐 생성 (bfs을 적용하기 위해서)
vector<vector<int >> vec; // 전역으로 사용하기 위해서 쓰임
int x[4] = { 0,0,-1,1 }; //좌, 우  
int y[4] = { -1,1,0,0 };// 상, 하
int bfs(int a, int b, int m,int n) {
    int cnt = 1;//카운팅
    check[a][b] = 1; //방문체크
    que.push(make_pair(a, b)); //queue에 넣기
    while (!que.empty()) {
        int p = que.front().first; // y
        int q = que.front().second;// x
        que.pop();
        for (int i = 0; i < 4; i++) {
            int neY = p + y[i];
            int neX = q + x[i];
            if ((0 <= neY && neY < m) && (0 <= neX && neX < n)) { // 들어갈 범위에 속하고
                if ((vec[p][q] == vec[neY][neX]) && check[neY][neX] == 0){ // 인접한 값과 같고 중복하지 않은 곳이면 들어가기
                    cnt++; //카운팅 증가 
                    check[neY][neX] = 1; // 중복 체크
                    que.push(make_pair(neY,neX));
                }
                
            }
        }
    }
    
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
//전역으로 사용하기 위한 크기 재조정 및 복사
    vec.resize(m, vector<int>(n)); 
    copy(picture.begin(), picture.end(), vec.begin());
//2차원 배열인 check을 동적할당하고 0으로 초기화하기(memset 사용)
    for (int i = 0; i < 101; i++) { 
        check[i] = new int[101];
        memset(check[i], 0, sizeof(int) * 101);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && check[i][j] == 0) { //색 영역이 존재하고 방문하지 않은 곳이면 영역임
            //bfs 들어간 후에 각 영역개수와 max_size_of_one_area와 비교해서 큰 값 저장하기
                max_size_of_one_area = Max(max_size_of_one_area, bfs(i, j, m, n));
                number_of_area++; //색 영역 증가
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
