/* 9095. 1,2,3 더하기 Silver 3
 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램
 https://www.acmicpc.net/problem/9095
 -> DP
  v01: 18.09.26
 */

#include<iostream>
#include<queue>
using namespace std;

int main(){
    int t;
    cin >> t;
    queue<int> n;
    int tmp;
    for (int i = 0; i < t; i++){
        cin >> tmp;
        n.push(tmp);
    }
    int ans[11]; //각 수에 대한 정답이 들어있는 배열
    /*
     1을 만드는 방법: 1 -> 1개
     2를 만드는 방법: 1+1, 2 -> 2개
     3을 만드는 방법: 1+1+1, 2+1, 1+2 -> 3개
     = 1을 만드는 방법에 2를 붙인 것 + 2를 만드는 방법에 1을 붙인 것 = 3개
     */
    //초기값 설정
    ans[1] = 1; //1을 만드는 방법의 수
    ans[2] = 2;
    ans[3] = 4;
    
    
    for (int i = 4; i < 11; i++){ //4부터
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
    }
    while (!n.empty()){
        cout << ans[n.front()] << '\n';
        n.pop();
    }
    
}
