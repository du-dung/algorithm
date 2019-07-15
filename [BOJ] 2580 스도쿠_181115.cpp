/*
18.11.15 ������ - DFS
https://www.acmicpc.net/problem/2580
*/

#include <iostream>
#include <vector>
using namespace std;

bool check_Horizontal(int plate[9][9], pair<int, int> lo, int value) {
	for (int i = 0; i < 9; i++) {
		if (plate[lo.first][i] == value)
			return false;
	}
	return true;
}

bool check_Vertical(int plate[9][9], pair<int, int> lo, int value) {
	for (int i = 0; i < 9; i++) {
		if (plate[i][lo.second] == value)
			return false;
	}
	return true;
}

bool check_Box(int plate[9][9], pair<int, int> lo, int value) {
	int x = (lo.first / 3) * 3, y = (lo.second / 3) * 3; //���η� x��°, ���η� y��° �ڽ�
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (value == plate[i+x][j+y])
				return false;
		}
	}
	return true;
}

void print_Sudoku(int plate[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << plate[i][j] << " ";
		}
		cout << "\n";
	}
	exit(0);
}

void sudoku(int plate[9][9], vector< pair<int, int> > item, int now) {
	if (item.size() == now) //sudoku is full
		print_Sudoku(plate);
	for (int i = 1; i < 10; i++) {
		if (check_Horizontal(plate, item[now], i) && check_Vertical(plate, item[now], i) && check_Box(plate, item[now], i)) {
			plate[item[now].first][item[now].second] = i;
			//��� ��쿡 �����ϸ� �� �Է�
			sudoku(plate, item, now + 1);
			plate[item[now].first][item[now].second] = 0; //��� ã�� ���н� �ʱ�ȭ
		}
	}
}

int main() {
	vector< pair<int, int> > item; //ä���� �ϴ� ���� ��ġ
	int plate[9][9];

	//input
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> plate[i][j];
			if (plate[i][j] == 0)
				item.push_back(make_pair(i, j)); //0�� �ԷµǸ� queue�� ����
		}
	}

	sudoku(plate, item, 0);
}