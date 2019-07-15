/* https://www.acmicpc.net/problem/2178
	18.09.18 v.01
	-�Է¹ޱ�
	-���� queue�� �ִ� ���� �̾Ƴ��� ����.

	18.09.20 v.02
	- bfs �˰��� ���� ¥��
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	int arr[101][101]; //�ִ� size: 100*100
	int n; int m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = str[j-1]-'0';
		}
	}

	/* ����� �Էµƴ��� Ȯ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	*/

	//BFS �˰��� ���
	queue<pair<int, int> > q;
	bool check[101][101] = { {false,} };

	pair<int, int> dir[4];
	dir[0] = make_pair(-1, 0); //��
	dir[1] = make_pair(0, -1); //����
	dir[2] = make_pair(1, 0); //�Ʒ�
	dir[3] = make_pair(0, 1); //������
	
	int count = 1;
	check[1][1] = true;
	q.push(make_pair(1, 1));
	while (!q.empty()) {
		int size_q = q.size(); //���� queue ������
		for (int i = 1; i <= size_q; i++) {
			int x = q.front().first, y = q.front().second; q.pop(); //���� queue�� �ִ� ����
			if (x == n && y == m) {
				cout << count;
				return 0; //������ ĭ�� ������ ��� return
			}
			for (int j = 0; j < 4; j++) {
				int nx = x + dir[j].first, ny = y + dir[j].second; //������� ��, ����, �Ʒ�, ������ ���Ҹ� Ž��
				if ((nx > 0 && nx <= n) && (ny > 0 && ny <= m)) { //���Ұ� �̷� �ȿ� �����ϰ�
					if (arr[nx][ny] == 1) {//�̵��� �� �ִ� ĭ�̰�
						if (check[nx][ny] == false) { //check���� �ʾҴٸ�
							q.push(make_pair(nx, ny)); //queue�� �߰�
							check[nx][ny] = true; //queue�� �־����Ƿ� �湮�� ����, ���� �ߺ����� ť�� ���� �ʵ��� üũ �Ϸ��� ǥ��������.
						}

					}
				}
			}
			
		}
		count++; //���� �߰�
	}
}