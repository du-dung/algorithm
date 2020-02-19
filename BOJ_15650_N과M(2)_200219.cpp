/* 15650. N과 M(2) Silver 3
https://www.acmicpc.net/problem/15650
*/

#include <iostream>
using namespace std;

int num[8] = { 1,2,3,4,5,6,7,8 };
int res[8];
int N, M;

void comb(int n, int r) {
	if (n > N || r > M)	return;
	if (n == N && r == M) {
		//print
		for (int i = 0; i < M; i++)
		{
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	res[r] = num[n];
	comb(n + 1, r + 1);
	comb(n + 1, r);
}

int main() {
	//input
	cin >> N >> M;

	//solve
	comb(0, 0); //N개중에 M개 고르고, 각각의 모든 순열 출력하기 -> 사전순 !!!
}
