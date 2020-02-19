/* 15656. N과 M(7) Silver 3
https://www.acmicpc.net/problem/15656
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[8], res[8];

void perm(int r) { //r은 고른 숫자 개수
	if (M == r) {
		for (int i = 0; i < M; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		res[r] = num[i];
		perm(r + 1);
	}
}

int main() {
	//input
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	//solve
	sort(num, num + N);
	perm(0);
}
