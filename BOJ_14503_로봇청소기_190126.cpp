/* 14503. 로봇 청소기 Gold 5
 https://www.acmicpc.net/problem/14503
 -> 시뮬레이션
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> > dir = { {-1,0}, {0,1}, {1,0}, {0,-1} }; //방향(0북 1동 2남 3서)
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
    int nr, nc, nd=d; //next r,n,c

    if (!cleaned[r][c]) {
        cleaned[r][c] = true; ans++;//청소하기
    }
    
    for (int i = 0; i < 4; i++) { //왼쪽부터 체크
        nd = (nd + 3) % 4;
        nr = r + dir[nd].first;
        nc = c + dir[nd].second;
        if (!(room[nr][nc] || cleaned[nr][nc])) { //청소를 안했으면&벽이 아니면 (청소 가능)
            cleaner(end, ans, room, cleaned, nr, nc, nd); //다음 지역으로
        }
    }
    
    //사방이 다 청소가 되어있거나 벽일 경우 -> 후방 체크
    nd = (d + 2) % 4;
    nr = r + dir[nd].first;
    nc = c + dir[nd].second;
    
    if (room[nr][nc]) { //후방이 벽일 경우
        cout << ans;
        exit(0);
    }
    else { //후방이 벽이 아닐 경우
        cleaner(end, ans, room, cleaned, nr, nc, d); //현재방향 유지한 채 후진
    }
}
