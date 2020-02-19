/* 11723. 집합 Silver 5
https://www.acmicpc.net/problem/11723
cin, cout 쓰면 시간 초과 ㅠ
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	//input
	int M = 0;
	scanf("%d", &M);

	bool S[21] = { false, }; //공집합 S로 시작
	char com[10]; int x;
	//solve
	for (; M > 0; M--) {
		scanf("%s", com); //명령어 입력
		switch (com[1]) //두번째 글자로 명령어 구분
		{
		case 'd': //add
			scanf("%d", &x);
			S[x] = true;
			break;
		case 'e': //remove
			scanf("%d", &x);
			S[x] = false;
			break;
		case 'h': //check
			scanf("%d", &x);
			if (S[x])	printf("1\n");
			else printf("0\n");
			break;
		case 'o': //toggle
			scanf("%d", &x);
			S[x] = !S[x];
			break;
		case 'l': //all
			fill(S, S+21, true);
			break;
		case 'm': //empty
			fill(S, S+21, false);
		}
	}
}
