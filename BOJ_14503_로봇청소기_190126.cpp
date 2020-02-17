/*
로봇 청소기 https://www.acmicpc.net/problem/14503
19.01.22~01.26 01:14
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> > dir = { {-1,0}, {0,1}, {1,0}, {0,-1} }; //방향(0북 1동 2남 3서)
//d=d+1%4; //다음방향으로가기

//vector< pair<int, int> > dir = { {0,-1}, {1,0}, {0,1}, {-1,0} };//북동남서
void cleaner(bool &end, int ans, vector< vector<int> >room, vector< vector<bool> > cleaned, int r, int c, int d);

int main() {
	int N, M; //세로, 가로
	int r, c, d; //(r, c) : 로봇청소기의 위치, d: 로봇청소기가 바라보는 방향(0북 1동 2남 3서)

	cin >> N >> M;
	cin >> r >> c >> d;

	vector< vector<int> > room(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
		}
	}

	int ans = 0; //청소한 공간의 수
	bool end = false;
	vector< vector<bool> > cleaned(N, vector<bool>(M, 0)); //청소되었으면 true, 아니면 false

	cleaner(end, ans, room, cleaned, r, c, d);
}

void cleaner(bool &end, int ans, vector< vector<int> >room, vector< vector<bool> > cleaned, int r, int c, int d) {
//	if (end)
//		return;
//	cout << "(" << r << ", " << c << "), d: " << d << endl;
	

	int nr, nc, nd=d; //next r,n,c
//	bool flag = false;

	if (!cleaned[r][c]) {
		cleaned[r][c] = true; ans++;//청소하기
	}

	for (int i = 0; i < 4; i++) { //왼쪽부터 체크
		nd = (nd + 3) % 4;
		nr = r + dir[nd].first;
		nc = c + dir[nd].second;
		if (!(room[nr][nc] || cleaned[nr][nc])) { //청소를 안했으면&벽이 아니면 (청소 가능)
			cleaner(end, ans, room, cleaned, nr, nc, nd); //다음 지역으로
			//flag = true;
			//break;
		}
	}

	//if (!flag) {
		//사방이 다 청소가 되어있거나 벽일 경우 -> 후방 체크
		nd = (d + 2) % 4;
		nr = r + dir[nd].first;
		nc = c + dir[nd].second;

		if (room[nr][nc]) { //후방이 벽일 경우
			cout << ans;
			exit(0);
			//end = true;
			//return;
		}
		else { //후방이 벽이 아닐 경우
			cleaner(end, ans, room, cleaned, nr, nc, d); //현재방향 유지한 채 후진
		}
	//}
}

//int canIclean(vector< vector<int> >room, vector< vector<bool> > cleaned, int &r, int &c, int d) {
//	/*
//	네 방향이 모두 청소되어 있거나 벽인 경우 4
//
//	청소 가능한 방향 리턴 (0,1,2,3)-> 현재 방향 기준으로 왼쪽부터 탐색
//	*/
//	//bool front = (cleaned[r + dir[d].first][c + dir[d].second] || room[r + dir[d].first][c + dir[d].second]); d = (d + 1) % 4;
//	//bool right = (cleaned[r + dir[d].first][c + dir[d].second] || room[r + dir[d].first][c + dir[d].second]); d = (d + 1) % 4;
//	//bool back = (cleaned[r + dir[d].first][c + dir[d].second] || room[r + dir[d].first][c + dir[d].second]); d = (d + 1) % 4;
//	//bool left = (cleaned[r + dir[d].first][c + dir[d].second] || room[r + dir[d].first][c + dir[d].second]); d = (d + 1) % 4; //처음 d로 돌아옴
//
//	//if (!left)
//	//	return (d + 3) % 4;
//	//if (!back)
//	//	return (d + 2) % 4;
//	//if (!right)
//	//	return (d + 1) % 4;
//	//if (!front)
//	//	return d;
//
//	int cur = (d + 3) % 4; //현재방향, 왼쪽부터 시작
//	for(int i=4; i; --i){
//		if (!(cleaned[c + dir[cur].first][r + dir[cur].second] || room[c + dir[cur].first][r + dir[cur].second])) {
//			//청소도 안했고 벽도 아닐때
//			return cur;
//		}
//	cur = (cur + 3) % 4;
//	}
//	
//	return 4;
//}
//
//void cleaner(int ans, vector< vector<int> >room, vector< vector<bool> > cleaned, int &r, int &c, int d) {
//
//	while (true) {
//		if (!cleaned[c][r]) { cleaned[c][r] = true; ans++; } //청소
//		cout << "(" << r << ", " << c << "), d: " << d << endl;
//
//		int go = canIclean(room, cleaned, r, c, d);
//
//		if (go == 4) { //청소할 구역 없음
//			 //1. 등 뒤가 벽임
//			int back = (d + 2) % 4;
//			if (room[c + dir[back].first][r + dir[back].second]) {
//				break;
//			}
//
//			//2. 뒤로 한칸 이동 (방향 유지)
//			c += dir[back].first; r += dir[back].second;
//		}
//		else { //청소 가능
//			d = go; //방향 전환
//			c += dir[d].first; r += dir[d].second; //해당 방향으로 한 칸 이동
//		}
//	}
//
//	cout << ans;
//}