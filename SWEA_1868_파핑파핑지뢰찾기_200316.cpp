/* 1868. 파핑파핑 지뢰찾기 D4
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LwsHaD1MDFAXc&categoryId=AV5LwsHaD1MDFAXc&categoryType=CODE
 -> dfs
 */
#include <iostream>
#include <algorithm>
using namespace std;

int dx[8] = {-1,-1,-1,0,0,1,1,1}, dy[8] = {-1,0,1,-1,1,-1,0,1};
int N;
int map[300][300]; //주위 8방향에 있는 폭탄 개수 배열

void dfs(int i, int j){ //i, j위치의 0을 눌렀을 때 공개되는 수 찾기
    map[i][j] = -1;
    for (int k=0; k<8; k++) {
        int nx = i+dx[k], ny = j+dy[k];
        if(nx<0 || ny<0 || nx>=N || ny>=N || map[nx][ny] < 0)  continue;
        if(map[nx][ny] == 0)    dfs(nx, ny);
        else    map[nx][ny] = -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int TC;
    cin >> TC;
    for (int testCase = 1; testCase <= TC; testCase++) {
        cin >> N;
        fill(&map[0][0], &map[N-1][N], 0); //initialize
        char tmp;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                cin>>tmp;
                if(tmp == '*'){
                    map[i][j] = -1; //폭탄 위치
                    for (int k=0; k<8; k++) { //8방향에 1씩 더해줌
                        int nx = i+dx[k], ny = j+dy[k];
                        if(nx<0 || ny<0 || nx>=N || ny>=N || map[nx][ny] < 0)  continue;
                        map[nx][ny]++;
                    }
                }
            }
        }
        
        int answer = 0;
        //0과 인접한 칸 제외하기
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if(map[i][j] == 0){
                    answer++;
                    dfs(i, j);
                }
            }
        }
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if(map[i][j] < 0) answer++;
            }
        }
        
        //output
        cout << '#' << testCase << ' ' << answer << '\n';
    }
}
