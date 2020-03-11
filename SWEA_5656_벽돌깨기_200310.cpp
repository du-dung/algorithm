/* 5656. 벽돌 깨기 모의
 https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo&categoryId=AWXRQm6qfL0DFAUo&categoryType=CODE
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, W, H;
int answer;

void comb(int x, int n, vector<vector<int>> m){
    //구슬 떨구기
    int y = 0;
    while(y<H && m[y][x] == 0) y++;
    if(y < H){
        queue<pair<pair<int, int>, int>> q;
        q.push({{x, y},m[y][x]});
        m[y][x] = 0;
        while(!q.empty()){
            int x = q.front().first.first, y = q.front().first.second, v = q.front().second;
            q.pop();
            
            for (int k=1; k<v; k++) {
                if(x-k>=0){
                    if(m[y][x-k] > 1)   q.push({{x-k, y}, m[y][x-k]});
                    m[y][x-k] = 0;
                }
                if(x+k<W){
                    if(m[y][x+k] > 1)   q.push({{x+k, y}, m[y][x+k]});
                    m[y][x+k] = 0;
                }
                if(y-k>=0){
                    if(m[y-k][x] > 1)   q.push({{x, y-k}, m[y-k][x]});
                    m[y-k][x] = 0;
                }
                if(y+k<H){
                    if(m[y+k][x] > 1)   q.push({{x, y+k}, m[y+k][x]});
                    m[y+k][x] = 0;
                }
            }
        }
        
        //블록 아래로 내리기 (빈 공간 채우기)
        for (int i=0; i<W; i++) {
            int d = H-1, u;
            do{
                while(d>0 && m[d][i] != 0) d--;
                u = d-1;
                while(u>=0 && m[u][i] == 0) u--;
                if(d<=0 || u<0) break;
                m[d][i] = m[u][i];
                m[u][i] = 0;
            }while(d>u);
        }
    }
    
    if(n==N){ //구슬 n개 떨굼 -> 남은 블록 개수 체크
        int cnt = 0;
        for (int i=0; i<H; i++) {
            for (int j=0; j<W; j++) {
                if(m[i][j] != 0)  cnt++;
            }
        }
        if(cnt < answer) answer = cnt; //갱신
        return;
    }
    
    for (int i=0; i<W; i++) { //구슬을 0~W-1번 위치에 떨어트릴 수 있음
        comb(i, n+1, m);
    }
}

int main() {
    int TC;
    scanf("%d", &TC);
    for (int testCase = 1; testCase <= TC; testCase++) {
        scanf("%d %d %d", &N, &W, &H);
        vector<vector<int>> map(H, vector<int>(W));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                scanf("%d", &map[i][j]);
            }
        } //end of input

        answer = 0x3f3f3f3f; //initialize
        for (int i=0; i<W; i++) {
            comb(i, 1, map);
        }

        printf("#%d %d\n", testCase, answer);
    }
}
