/* 16234. 인구 이동 Gold 5
 https://www.acmicpc.net/problem/16234
1. 각 나라의 연합 여부 탐색 (맵 범위: 1~N * 1~N)
		-> 각각에서 bfs
		-> 중복 체크(이미 연합에 포함되었을 경우 탐색하지 않음) 필요
2. 연합의 인구수 조정
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, L, R;
	cin >> N >> L >> R;
	vector<vector<int>> map(N+2, vector<int>(N+2)); //초기화: N+2 * N+2 크기의 배열 (바운더리 추가)
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
		vector<vector<bool>>(N + 2, vector<bool>(N + 2, false)).swap(isChecked); //새로 채우기
		for (int i = 1; i <= N; i++) { //바운더리는 이미 체크한 것으로 표시 -> 조회하지 않도록
			isChecked[0][i] = isChecked[N + 1][i] = isChecked[i][0] = isChecked[i][N + 1] = true;
		} //바운더리 end
		isEnd = true;

		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (!isChecked[r][c]) { //탐색하지 않음 -> 연합 체크
					int population = 0, num = 0; //초기화
					q.push({ r,c });
					myUnion.push_back({ r,c });
					

					while (!q.empty()) { //연합 모두 찾기 (BFS)
						int x = q.front().first, y = q.front().second;
						q.pop();
						if (isChecked[x][y])	continue;
						isChecked[x][y] = true;
						population += map[x][y]; num++;

						//4방향 탐색 -> 중복체크
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

					population /= num; //재조정할 각 칸의 인구 수
					for (int i = 0; i < myUnion.size(); i++) { //연합에 속한 모든 원소들의 값 재설정 -> 인구 이동
						map[myUnion[i].first][myUnion[i].second] = population;
					}
					if (myUnion.size() > 1)	isEnd = false; //연합에 나 말고 뭔가 있으면 이동한 것
					myUnion.clear(); //연합 비우기
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
