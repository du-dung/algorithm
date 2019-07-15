/*
10844 쉬운 계단 수
http://www.acmicpc.net/problem/10844

v01. 18.09.27
45656이란 수를 보자.
이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.
세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.
N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.
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