/* 15663. N과 M(9) Silver 2
https://www.acmicpc.net/problem/15663
- unordered_set (hash set을 사용하려고 했는데 이걸로 바꾸라고 하더라) 사용해서 중복 검사!
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
 
int N, M;
int num[8], res[8];
bool used[8];
unordered_set<int> s;
 
void perm(int r) { //r은 고른 숫자 개수
	if (M == r) {
		int k = 0;
		for (int i = 0; i < M; i++) {
			k *= 10;
			k += res[i];
		}
		if (s.end() != s.find(k))	return; //해당 원소가 이미 있음 -> 출력 x
		for (int i = 0; i < M; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		s.insert(k);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (used[i])	continue;	//이미 골랐으면(중복이면) continue
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
