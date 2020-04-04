/* 5582. 공통 부분 문자열 Gold V
https://www.acmicpc.net/problem/5582
 */

#include <iostream>
#include <string>
using namespace std;

int dp[4001][4001];

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    
    int answer = 0;
    for (int i=1; i<=str1.length(); i++) {
        for (int j=1; j<=str2.length(); j++) {
            if (str1[i-1] == str2[j-1]) { //주의! 1 크게 잡았다 !
                dp[i][j] = dp[i-1][j-1] + 1;
                if (answer < dp[i][j])  answer = dp[i][j]; //갱신
            }
        }
    }
    
    cout << answer;
}
