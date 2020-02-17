//https://www.acmicpc.net/problem/11048

#include <iostream>
using namespace std;

int main() {
	int N, M;
	int map[1001][1001], ans[1001][1001];
	int max;

	scanf("%d %d", &N, &M);
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= M; ++c) {
			scanf("%d", &map[r][c]);
		}
	}

	//ù° �� (���� ��ȭ)
	ans[1][1] = map[1][1];
	for (int c = 2, c_=1; c <= M; ++c, ++c_) {
		ans[1][c] = ans[1][c_] + map[1][c];
	}

	//ù° �� (�ุ ��ȭ)
	for (int r = 2, r_ = 1; r <= N; ++r, ++r_) {
		ans[r][1] = ans[r_][1] + map[r][1];
	}

	//�� ��°���� ������
	for (int r = 2; r <= N; ++r) {
		for (int c = 2; c <= M; ++c) {

			//ans[r-1][c](��), ans[r-1][c-1](�밢��), ans[r][c-1](��) �� ���� ū �� ����
			if (ans[r - 1][c] > ans[r][c - 1]) {
				if (ans[r - 1][c] > ans[r - 1][c - 1])
					max = ans[r - 1][c];
				else
					max = ans[r - 1][c - 1];
			}
			else {
				if (ans[r][c - 1] > ans[r - 1][c - 1])
					max = ans[r][c - 1];
				else
					max = ans[r - 1][c - 1];
			}

			ans[r][c] = map[r][c] + max;
		}
	}

	printf("%d", ans[N][M]);
	
}