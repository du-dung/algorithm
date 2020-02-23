/* 1260. DFS와 BFS Silver 1
 https://www.acmicpc.net/problem/1260
 */

#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool map[1001][1001] = {
    false,
};
bool visited[1001] = {
    false,
};

void dfs(int v)
{
    cout << v << " ";
    for (int i = 1; i <= N; i++) {
        if (map[v][i] && !visited[i]) {
            visited[i] = true;
            dfs(i);
        }
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (map[u][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int V;
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int r, c;
        cin >> r >> c;
        map[r][c] = map[c][r] = true;
    }
    
    visited[V] = true;
    dfs(V);
    cout << '\n';
    //visited 초기화
    for (int i = 1; i <= N; i++) {
        visited[i] = false;
    }
    bfs(V);
}
