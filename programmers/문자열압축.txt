#include <string>
#include <vector>
//완전탐색
using namespace std;
int Min(int a, int b) {
    return a > b ? b : a;
}
int solution(string s) {
    int answer = s.size(); // 최대 사이즈 
    int len; //길이 카운팅
    string re_Str = ""; // 결과
    string all_Str = ""; // 총 문자 (차곡차곡 쌓이도록)
    string sub_Str = ""; // 자른 문자열
    string ch_Str = ""; // 체크 문자열
    //최대 압축한 것은 절반이므로 길이/2만큼 반복한다.
    
    for (int i = 0; i < s.size() / 2; i++) { 
        all_Str += s[i]; // 총 문자 카운팅
        ch_Str = all_Str; // 총 문자를 체크해주는 string에 저장해준다.
        len = 1; //처음에 길이는 무조건 1
        
        //문자를 탐색하는데 문자열을 1..2..3씩 끊어서 하므로 j를 all size만큼 증가시켜줘야한다.
        for (int j = i + 1; j < s.size(); j+=ch_Str.size()) { 
            sub_Str = s.substr(j, i + 1); //문자열을 j번째 인덱스에서 (i+1)개수만큼 자른다.
            if (ch_Str == sub_Str) { // 두 문자열이 같으면 체크
                len++; //길이 증가
            }
            //두 문자열이 길이가 다르면 다른 경우이므로 변경
            else if(ch_Str != sub_Str) {
                if (len != 1) //길이가 1이 아닐떄만 숫자 넣기
                    re_Str += to_string(len); // 정수를 문자로 형 변환
                
                re_Str += ch_Str; //문자열 붙이기
                len = 1;
                ch_Str = sub_Str; //문자열 덧씌우기
            }
        }
        //모든 문자열이 탐색이 끝났을 떄 나머지 문자열을 넣는 것(똑같은 방법으로 넣기)
        if (len != 1)
            re_Str += to_string(len); // 정수를 문자로 형 변환
        
        re_Str += ch_Str; //문자열 붙이기
        len = 1; //길이 초기화
        ch_Str = sub_Str; //문자열 덧씌우기
        answer = Min(answer, re_Str.size()); //최소값 구하기
        re_Str = ""; //초기화
    }
    return answer;
}
