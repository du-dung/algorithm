/* 11051. 이항 계수 2 Silver 1
 https://www.acmicpc.net/problem/11051
 -> DP
 */
#include<iostream>
using namespace std;

int comb[1001][1001];

int getComb(int n, int k){
	if (n < k){
		return 0;
	}
	else if (k == 0 || k == n){
		comb[n][k] = 1;
		return 1;
	}
	else{
		if (comb[n][k] == 0){
			comb[n][k] = (getComb(n - 1, k - 1) + getComb(n - 1, k)) % 10007;
		}
		return comb[n][k];
	}
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	int ans = getComb(n, k);
	printf("%d", ans);
}
