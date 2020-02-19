/* 15649. N과 M(1) Silver 3
https://www.acmicpc.net/problem/15649
- 결과 배열을 int로 해서 for문으로 출력했을 때 32ms
- (다른 사람들 코드를 보고) char 배열로 바꿔 한 번에 출력했더니 8ms로 감소!
- 위에서 참고한 코드와 로직이 똑같은데, 이분은 4ms가 나와있다. 난 왜,,? 
*/

#include <iostream>
using namespace std;

char res[20];
bool used[8];
int N, M;

void perm(int r) {
	if (M == r) {
		printf("%s", res);
		//cout << res;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (used[i])	continue;//같은 값이 있으면(중복이면) continue
		res[r*2] = i + '1';
		used[i] = true;
		perm(r + 1);
		used[i] = false;
	}
}

int main() {
	//input
	scanf("%d %d", &N, &M);
	//cin >> N >> M;

	//solve
	for (int i = 1; i < 2 * M; i+=2) res[i] = ' ';
	res[2 * M] = '\n';
	perm(0); //N개중에 M개 고르고, 각각의 모든 순열 출력하기 -> 사전순 !!!
}
