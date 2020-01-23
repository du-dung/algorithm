/*
1. �� ������ ���� ���� Ž�� (�� ����: 1~N * 1~N)
		-> �������� bfs
		-> �ߺ� üũ(�̹� ���տ� ���ԵǾ��� ��� Ž������ ����) �ʿ�
2. ������ �α��� ����
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, L, R;
	cin >> N >> L >> R;
	vector<vector<int>> map(N+2, vector<int>(N+2)); //�ʱ�ȭ: N+2 * N+2 ũ���� �迭 (�ٿ���� �߰�)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	} 
	//end of input

	//solve
	int answer = -1;
	vector<vector<bool>> isChecked;
	queue<pair<int, int>> q;
	vector<pair<int, int>> myUnion;
	bool isEnd = false;
	
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };

	while (!isEnd) {
		answer++;
		vector<vector<bool>>(N + 2, vector<bool>(N + 2, false)).swap(isChecked); //���� ä���
		for (int i = 1; i <= N; i++) { //�ٿ������ �̹� üũ�� ������ ǥ�� -> ��ȸ���� �ʵ���
			isChecked[0][i] = isChecked[N + 1][i] = isChecked[i][0] = isChecked[i][N + 1] = true;
		} //�ٿ���� end
		isEnd = true;

		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (!isChecked[r][c]) { //Ž������ ���� -> ���� üũ
					int population = 0, num = 0; //�ʱ�ȭ
					q.push({ r,c });
					myUnion.push_back({ r,c });
					

					while (!q.empty()) { //���� ��� ã�� (BFS)
						int x = q.front().first, y = q.front().second;
						q.pop();
						if (isChecked[x][y])	continue;
						isChecked[x][y] = true;
						population += map[x][y]; num++;

						//4���� Ž�� -> �ߺ�üũ
						for (int i = 0; i < 4; i++) {
							int nx = x + dx[i], ny = y + dy[i];
							if (!isChecked[nx][ny]) {
								int diff = abs(map[x][y] - map[nx][ny]);
								if (diff >= L && diff <= R) {
									q.push({ nx,ny });
									myUnion.push_back({ nx,ny });
								}
							}
						}
						
					} //end of while q

					population /= num; //�������� �� ĭ�� �α� ��
					for (int i = 0; i < myUnion.size(); i++) { //���տ� ���� ��� ���ҵ��� �� �缳�� -> �α� �̵�
						map[myUnion[i].first][myUnion[i].second] = population;
					}
					if (myUnion.size() > 1)	isEnd = false; //���տ� �� ���� ���� ������ �̵��� ��
					myUnion.clear(); //���� ����
				} //end of if 
			}
		} //end of for all map[r][c]

		//print
		//cout << "*******\n";
		//for (int i = 0; i < map.size(); i++) {
		//	for (int j = 0; j < map.size(); j++) {
		//		cout << map[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}

	} //end of while true
	cout << answer;
} //end of main