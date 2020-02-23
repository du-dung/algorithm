/* 7569. 토마토 Silver 1
 https://www.acmicpc.net/problem/7569
 v01. 18.10.03
 */

#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int box[100][100][100]; //box[m][n][h]

int main() {
    int m, n, h;
    
    queue < tuple<int, int, int> > ripen_tomato;
    
    //input
    cin >> m >> n >> h;
    for (int k = 0; k < h; k++) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                cin >> box[i][j][k]; //h층의 가로m, 세로n 위치
                if (box[i][j][k] == 1)
                    ripen_tomato.push(make_tuple(i, j, k)); //익은 토마토는 queue에 추가
            }
        }
    }
    
    //calculate days
    int ans=-1; //모든 토마토가 익는 데 걸리는 날,
    tuple<int, int, int>  dir[]
    = { make_tuple(0, 0, -1), make_tuple(0, 0, 1), make_tuple(-1, 0, 0), make_tuple(1, 0, 0), make_tuple(0, -1, 0), make_tuple(0, 1, 0) }; //dirrection
    
    while (!ripen_tomato.empty()) {
        ans++; //0번째 날부터 시작
        int size_q = ripen_tomato.size();
        for (; size_q != 0; size_q--) {
            int x = get<0>(ripen_tomato.front()), y = get<1>(ripen_tomato.front()), z = get<2>(ripen_tomato.front());
            ripen_tomato.pop();
            
            for (int i = 0; i < 6; i++) { //6방향 탐색
                int nx = x + get<0>(dir[i]), ny = y + get<1>(dir[i]), nz = z + get<2>(dir[i]);
                if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h) //상자 범위를 벗어났을 경우
                    continue;
                if (box[nx][ny][nz] != 0) //토마토가 익었거나 없을 경우
                    continue;
                
                box[nx][ny][nz] = 1; //토마토 익음
                ripen_tomato.push(make_tuple(nx, ny, nz)); //익은 토마토에 추가
            }
        }
    }
    
    //check all tomato ripe
    for (int k = 0; k < h; k++) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (box[i][j][k] == 0) { //익지 않은 토마토를 발견했을 경우
                    cout << -1; return 0; //-1 출력, 프로그램 종료
                }
            }
        }
    }
    
    cout << ans; //익지 않은 토마토가 없을 경우 걸린 날 출력
    
}
