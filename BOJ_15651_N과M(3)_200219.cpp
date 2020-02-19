/* 15651. N과 M(3) Silver 3
https://www.acmicpc.net/problem/15651
*/

#include <iostream>
using namespace std;

char res[20];
int N, M;

void perm(int r) {
	if (M == r) {
		printf("%s", res);
		return;
	}
	for (int i = 0; i < N; i++) {
		res[r*2] = i + '1';
		perm(r + 1);
	}
}

int main() {
	//input
	scanf("%d %d", &N, &M);

	//solve
	for (int i = 1; i < 2 * M; i+=2) res[i] = ' ';
	res[2 * M] = '\n';
	perm(0);
}
