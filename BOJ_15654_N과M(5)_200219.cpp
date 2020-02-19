/* 15654. N과 M(5) Silver 3
https://www.acmicpc.net/problem/15654
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[8], res[8];
bool used[8];

void perm(int r) { //r은 고른 숫자 개수
	if (M == r) {
		for (int i = 0; i < M; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		if (used[i])	continue;	//같은 값이 있으면(중복이면) continue
		res[r] = num[i];
		used[i] = true;
		perm(r + 1);
		used[i] = false;
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
