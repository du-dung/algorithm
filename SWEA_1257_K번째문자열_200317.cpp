/* 1257. [S/W 문제해결 응용] 6일차 - K번째 문자열 D6
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18KWf6ItECFAZN&categoryId=AV18KWf6ItECFAZN&categoryType=CODE
 -> 완탐.. 273ms
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int TC;
    cin >> TC;
    for (int testCase = 1; testCase <= TC; testCase++) {
        int K;
        cin >> K; //K번째 수 출력
        string str;
        cin >> str; //end of input

        string answer = "none";
        set<string> words[26]; //중복 제거용 -> 배열로 나눈 이유 : 구냥 .. 정렬 오래 걸리지 말라고
        for (int pos = 0; pos < str.length(); pos++) {
            for (int count = 1; count <= str.length() - pos; count++) {
                words[str[pos] - 'a'].insert(str.substr(pos, count)); //문자열 다 자르기
            }
        }
        int n = 0, index = -1;
        for (int i=0; i<26; i++) {
            if(words[i].size() == 0)    continue;
            n += words[i].size();
            index = i;
            if(n > K) break;
        }
        
        if(n <= K){ //K번째 단어가 없음
            cout << '#' << testCase << " none\n";
            continue;
        }
        n -= words[index].size();
        for(string s : words[index]){
            if(++n == K){
                answer = s;
            }
        }
        
        //output
        cout << '#' << testCase << ' ' << answer<< '\n';
    }
}
