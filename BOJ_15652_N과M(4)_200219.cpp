/* 15652. N과 M(4) Silver 3
https://www.acmicpc.net/problem/15652
*/

#include <iostream>
using namespace std;

int N, M;
char res[20];

void perm(int r, int k) { //r은 고른 숫자 개수
	if (M == r) {
		printf("%s", res);
		return;
	}
	for (int i = k; i < N; i++) { //k보다 작은 건 출력 x
		res[r*2] = i + '1';
		perm(r + 1, i);
	}
}

int main() {
	//input
	scanf("%d %d", &N, &M);

	//solve
	for (int i = 1; i < 2 * M; i+=2) res[i] = ' ';
	res[2 * M] = '\n';
	perm(0, 0);
}
