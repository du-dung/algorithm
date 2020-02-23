/* 2293. 동전 Silver 1
 https://www.acmicpc.net/problem/2293
 -> DP
 */
#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int coin[101];
int value[10001];

int main(){
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", &coin[i]);
	}
	sort(coin + 1, coin + n + 1);

	for (int i = 1; i <= n; i++){
		if (coin[i] <= k){
			value[coin[i]]++;
			for (int j = coin[i] + 1; j <= k; j++){
				value[j] += value[j - coin[i]];
			}
		}
	}

	printf("%d", value[k]);
}

/*
int getNum(int v, int i){
	if (v == 0) return 1;
	else if (i == n) return 0;
	else {
		for (int x = v / coin[i]; x >= 0; x--){
			result += getNum(v - coin[i] * x, i + 1);
		}
		return 0;
	}
}
*/
