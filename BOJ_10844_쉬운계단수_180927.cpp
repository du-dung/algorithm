/* 10844. 쉬운 계단 수 Silver 1
 http://www.acmicpc.net/problem/10844
 -> DP
 v01. 18.09.27
 */

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    long int ans=0;
    long int arr[101][10] = { {}, { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, }; //초기값 부여
    for (int i = 2; i <= n; i++){
        for (int j = 0; j < 10; j++){ //j로 끝나는 i자리 수
            switch (j){
                case 0: //0으로 끝나는 수
                    arr[i][j] = arr[i - 1][j + 1] % 1000000000;
                    break;
                case 9:
                    arr[i][j] = arr[i - 1][j - 1] % 1000000000;
                    break;
                default:
                    arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
            }
        }
    }
    for (int i = 0; i < 10; i++)
        ans += arr[n][i];
    cout << ans % 1000000000;
}
