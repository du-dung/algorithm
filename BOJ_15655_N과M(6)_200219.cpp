/* 15655. N과 M(6) Silver 3
https://www.acmicpc.net/problem/15655
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[8], res[8];

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
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	//solve
	sort(num, num + N);
	comb(0, 0);
}
