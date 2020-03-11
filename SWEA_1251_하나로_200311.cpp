/* 1251. 하나로 D4
 https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15StKqAQkCFAYD&categoryId=AV15StKqAQkCFAYD&categoryType=CODE
 -> MST, Prim 이용
 */
#include <iostream>
#include <cmath>
using namespace std;

int islandsX[1000], islandsY[1000]; //섬 목록
unsigned long long dist[1000][1000];
bool visited[1000];

int main() {
    int TC;
    cin >> TC;
    for (int testCase = 1; testCase <= TC; testCase++) {
        int N; //섬의 개수
        cin >> N;
        for (int i=0; i<N; i++) {
            cin >> islandsX[i];
        }
        for (int i=0; i<N; i++) {
            cin >> islandsY[i];
        }
        double E;
        cin >> E;
        //end of input
        
        //distance 찾기
        for (int i=0; i<N; i++) {
            for(int j=i; j<N; j++){
                dist[i][j] = dist[j][i] = pow(islandsX[i] - islandsX[j],2) + pow(islandsY[i] - islandsY[j],2);
            }
        }
        
        long long answer = 0; // E * L^2를 더해준다
        fill(&visited[1], &visited[N], false);
        visited[0] = true;
        
        unsigned long long *res = dist[0];
        for (int n=1; n<N; n++) { //섬 개수 -1 만큼 반복
            unsigned long long nextDist = 0xffffffffffffffff; int nextIsland = 0;
            for (int ni = 0; ni<N; ni++) { //가장 간선 길이가 짧은 섬 찾기
                if(visited[ni])  continue;
                if(nextDist > res[ni]){
                    nextDist = res[ni];
                    nextIsland = ni;
                }
            }
            answer += nextDist;
            visited[nextIsland] = true;
            for (int i=0; i<N; i++) { //거리 갱신
                if(res[i] > dist[nextIsland][i])
                    res[i] = dist[nextIsland][i];
            }
        }
        
        answer = round(answer * E); //반올림
        cout << '#' << testCase << ' ' << answer << '\n';
    }
}
