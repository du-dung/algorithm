/* 11050. 이항계수 1 Bronze 1
 https://www.acmicpc.net/problem/11050
 */
#include<iostream>
using namespace std;

int factorial(int n){
	if (n == 0){
		return 1;
	}
	else{
		return n*factorial(n - 1);
	}
}
int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	int comb = factorial(n) / factorial(n - k) / factorial(k);
	printf("%d", comb);
}
