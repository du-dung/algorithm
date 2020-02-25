/* 1260. DFS와 BFS Silver 1
https://www.acmicpc.net/problem/1260
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main{
    static int N;
    static boolean[] visited;
    static boolean[][] map;
    static StringBuilder sb;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        int M =Integer.parseInt(st.nextToken()), V = Integer.parseInt(st.nextToken());
        map = new boolean[N+1][N+1];

        for (int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
            map[r][c] = map[c][r] = true;
        }
        //end of input

        visited = new boolean[N+1];
        visited[V] = true;
        sb = new StringBuilder();
        dfs(V);

        sb.append('\n');
        visited = new boolean[N+1];
        bfs(V);
        System.out.println(sb);
    }

    static void dfs(int v){
       sb.append(v).append(' ');
        for (int i = 1; i <= N; i++) {
            if (map[v][i] && !visited[i]) {
                visited[i] = true;
                dfs(i);
            }
        }
    }

    static void bfs(int v)
    {
        Queue<Integer> q = new LinkedList<>();
        q.offer(v);
        visited[v] = true;
        while (!q.isEmpty()) {
            int u = q.poll();
            sb.append(u).append(' ');
            for (int i = 1; i <= N; i++) {
                if (map[u][i] && !visited[i]) {
                    visited[i] = true;
                    q.offer(i);
                }
            }
        }
    }
}