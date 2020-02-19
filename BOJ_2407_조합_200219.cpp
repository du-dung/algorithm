/* 2407. 조합 Silver 2
https://www.acmicpc.net/problem/2407
- 숫자로 저장하면 틀린다 (unsigned long long 범위도 초과한다고 함) ㅠ string으로 변환할 것
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string dp[101][101];

string add(string a, string b) {
	string res;
	int idxA = a.length() - 1, idxB = b.length() - 1;
	int sum = 0;// , carry = 0;
	while (idxA >= 0 || idxB >= 0 || sum) { //idx는 끝났어도 sum이 남아있을 경우 대비
		if (idxA >= 0)	sum += (a[idxA--] - '0');
		if (idxB >= 0)	sum += (b[idxB--] - '0');
		res += (sum % 10 + '0');
		sum /= 10;
	}
	reverse(res.begin(), res.end()); //뒤에서부터 더했으므로 뒤집는다
	return res;
}

string comb(int n, int r) {
	if (n < r)	return 0;
	if (n == r || r == 0)	return "1";
	if (dp[n][r] == "")
		dp[n][r] = add(comb(n - 1, r - 1), comb(n - 1, r));
	return dp[n][r];
}

int main() {
	int N, M;
	cin >> N >> M;
	cout << comb(N, M);
}
