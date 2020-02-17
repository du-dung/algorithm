//https://www.acmicpc.net/problem/1010

#include <iostream>
#include <vector>
using namespace std;

void noc(int a, int b) {
	int x = b - a;
	unsigned long long ans = 1;
	if (x) { //n>=1
		if (x > a) {
			for (int i = b; i > x; i--) {
				ans *= i;
			}

			for (int i = 1; i <= a; i++) {
				ans /= i;
			}
		}
		else {
			for (int i = b; i > a; i--) {
				ans *= i;
			}

			for (int i = 1; i <= x; i++) {
				ans /= i;
			}
		}

		cout << ans << '\n';
	}
	else {
		cout << "1\n";
	}
}

int main() {
	int T;
	cin >> T;
	vector<int> N(T), M(T);
	for (int i = 0; i < T; i++) {
		cin >> N[i] >> M[i];
	}

	for (int i = 0; i < T; i++) {
		noc(N[i], M[i]);
	}
	
}