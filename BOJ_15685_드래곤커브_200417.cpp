/* 15685. 드래곤 커브 Gold 4
https://www.acmicpc.net/problem/15685
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool map[101][101];
int dirR[4] = {0, -1, 0, 1}, dirC[4] = {1, 0, -1, 0};
int dir[2<<10];

void curve(int c, int r, int d, int g){
    //0세대
    int cnt = 1;
    dir[0] = d;
    map[r][c] = true;
    r += dirR[d]; c += dirC[d];
    map[r][c] = true;
    
    //1~d세대
    for (int k=1; k<=g; k++) {
        for (int i=cnt-1; i>=0; i--) {
            int nd =(dir[i]+1)%4;
            dir[cnt++] = nd;
            r += dirR[nd]; c += dirC[nd];
            map[r][c] = true;
        }
    }
}

int main() {
    int N;
    cin >> N;
    int x, y, d, g;
    for (int i=0; i<N; i++) {
        cin >> x >> y >> d >> g;
        curve(x, y, d, g);
    }

    //사각형 개수 찾기
    int answer = 0;
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1])    answer++;
        }
    }
    cout << answer;
}
