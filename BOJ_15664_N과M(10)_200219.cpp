/* 15664. N과 M(10) Silver 2
https://www.acmicpc.net/problem/15664
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int N, M;
int num[8], res[8];
unordered_set<int> s;

void perm(int r, int k) { //r은 고른 숫자 개수
	if (M == r) {
		int k = 0;
		for (int i = 0; i < M; i++) {
			k *= 10;
			k += res[i];
		}
		if (s.end() != s.find(k))	return; //해당 원소가 이미 있음 -> 출력 x
		s.insert(k);
		for (int i = 0; i < M; i++) { //출력
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	for (int i = k; i < N; i++) { //k보다 작은 건 출력 x
		res[r] = num[i];
		perm(r + 1, i+1);
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
	perm(0, 0);
}
