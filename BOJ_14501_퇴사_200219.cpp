/* 14501. 퇴사 Silver 4
https://www.acmicpc.net/problem/14501
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, T[16], P[16], answer = 0;

void dfs(int today, int p) {
	if (today > N) { //회사에 없음
		if (p > answer)	answer = p;
		return;
	}
	if (today + T[today] <= N+1)	dfs(today + T[today], p + P[today]); //오늘 상담을 하는 경우
	dfs(today + 1, p); //하지 않는 경우
}

int main() {
	//input
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}

	//solve
	dfs(1, 0);

	//output
	cout << answer;
}
