/* 14888. 연산자 끼워넣기 Silver 1
https://www.acmicpc.net/problem/14888
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, num[11];
char oper[10];
int ansMin = 1000000000, ansMax = -1000000000;

void calculate() {
	int ans = num[0];
	int index = 0;
	for (int i = 1; i < N; i++) { //앞에서부터 계산
		switch (oper[index++])
		{
		case '+':
			ans += num[i];
			break;
		case '-':
			ans -= num[i];
			break;
		case '*':
			ans *= num[i];
			break;
		case '/':
			ans /= num[i];
			break;
		}
	}

	//결과 갱신
	if (ansMax < ans)	ansMax = ans;
	if (ansMin > ans)	ansMin = ans;
}

int main() {
	//input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	//배열에 연산자 끼워넣기
	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;
	for (int i = 0; i < N - 1; i++)
	{
		//아스키 코드 번호 작은 것부터
		oper[i] = (mul-- > 0 ? '*' : (plus-- > 0 ? '+' : (minus-- > 0 ? '-' : (div-- > 0 ? '/' : 'x'))));
	}

	//solve
	do {
		calculate();
	} while (next_permutation(oper, oper + N - 1));

	//output
	cout << ansMax << '\n' << ansMin;
}
