/* https://www.acmicpc.net/problem/2178
	18.09.18 v.01
	-입력받기
	-현재 queue에 있는 원소 뽑아내기 까지.

	18.09.20 v.02
	- bfs 알고리즘 마저 짜기
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	int arr[101][101]; //최대 size: 100*100
	int n; int m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = str[j-1]-'0';
		}
	}

	/* 제대로 입력됐는지 확인
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	*/

	//BFS 알고리즘 사용
	queue<pair<int, int> > q;
	bool check[101][101] = { {false,} };

	pair<int, int> dir[4];
	dir[0] = make_pair(-1, 0); //위
	dir[1] = make_pair(0, -1); //왼쪽
	dir[2] = make_pair(1, 0); //아래
	dir[3] = make_pair(0, 1); //오른쪽
	
	int count = 1;
	check[1][1] = true;
	q.push(make_pair(1, 1));
	while (!q.empty()) {
		int size_q = q.size(); //현재 queue 사이즈
		for (int i = 1; i <= size_q; i++) {
			int x = q.front().first, y = q.front().second; q.pop(); //현재 queue에 있는 원소
			if (x == n && y == m) {
				cout << count;
				return 0; //마지막 칸에 도달한 경우 return
			}
			for (int j = 0; j < 4; j++) {
				int nx = x + dir[j].first, ny = y + dir[j].second; //순서대로 위, 왼쪽, 아래, 오른쪽 원소를 탐색
				if ((nx > 0 && nx <= n) && (ny > 0 && ny <= m)) { //원소가 미로 안에 존재하고
					if (arr[nx][ny] == 1) {//이동할 수 있는 칸이고
						if (check[nx][ny] == false) { //check하지 않았다면
							q.push(make_pair(nx, ny)); //queue에 추가
							check[nx][ny] = true; //queue에 넣었으므로 방문할 예정, 따라서 중복으로 큐에 넣지 않도록 체크 완료라고 표시해주자.
						}

					}
				}
			}
			
		}
		count++; //깊이 추가
	}
}