/* 3190. 뱀 Silver 1
https://www.acmicpc.net/problem/3190
 */

#include <iostream>
#include <deque>
using namespace std;

class Snake {
public:
    int x, y, dir;
    Snake(int _x, int _y, int _dir)
    {
        x = _x;
        y = _y;
        dir = _dir;
    }
};

int main()
{
    // input
    int N, K, L; //L은 방향 변환 횟수
    int map[101][101] = {
        0,
    };
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        map[r][c] = 2; //사과는 2
    }
    cin >> L;

    // solve
    int dx[4] = { 0, 1, 0, -1 }; //오른쪽, 아래, 왼쪽, 위
    int dy[4] = { 1, 0, -1, 0 };

    map[1][1] = 1; //뱀은 1
    deque<Snake> deq; //front는 머리, back은 꼬리
    deq.push_front(Snake(1,1,0));
    Snake head = deq.front();

    int time = 0; //게임이 끝날 때까지 걸리는 시간

    int x;
    char c;
    cin >> x >> c;
    L--;

    while (true) {
        time++;
        deq.push_front(Snake(head.x + dx[head.dir], head.y + dy[head.dir], head.dir));
        head = deq.front(); //머리를 다음 칸으로
        if (head.x == 0 || head.y == 0 || head.x == N + 1 || head.y == N + 1 || map[head.x][head.y] == 1) { //범위초과 or 몸에 부딪힘
            break; //게임 끝
        } else if (map[head.x][head.y] == 2) { //사과
            map[head.x][head.y] = 1; //사과 없어지고 꼬리 움직 x
        } else { //사과 x
            map[head.x][head.y] = 1; //사과 없어지고 꼬리 움직 x
            map[deq.back().x][deq.back().y] = 0; //꼬리 한 칸 앞으로
            deq.pop_back();
        }

        if (x == time) { //회전
            if (c == 'D')
                head.dir = (head.dir + 1) % 4; //오른쪽 90도
            else if (head.dir == 0)
                head.dir = 3; //왼쪽 90도
            else
                head.dir--; //왼쪽 90도
            if (L > 0) { //다음 회전 정보 받아옴
                cin >> x >> c;
                L--;
            }
        }
    }
    
    if(L-->0)
        cin >> x >> c; //입력 계속 받아주기
    
    // output
    cout << time;
}
