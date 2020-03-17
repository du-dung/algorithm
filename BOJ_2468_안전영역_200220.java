/* 2468. 안전영역 Silver 2
https://www.acmicpc.net/problem/2468
-> DFS
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1}; //사방 탐색 용

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        map = new int[N][N];
        boolean[] heights = new boolean[101]; //땅의 높이들 저장
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                heights[map[i][j]] = true;
            }
        }
        //end of input
        int answer = 1;

        //dfs
        for (int h = 1; h <= 100; h++) {
            if (!heights[h]) continue; //땅 높이가 있는 경우에만 (물에 잠기는 땅이 늘어나는 경우) 탐색
            visited = new boolean[N][N];
            int tans = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (map[i][j] <= h) visited[i][j] = true; //방문하지 못하도록
                }
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (!visited[i][j]) {
                        visited[i][j] = true;
                        dfs(i, j);
                        tans++;
                    }
                }
            }
            if (tans > answer) answer = tans; //갱신
        }

        System.out.println(answer);
    }


    static void dfs(int r, int c) {
        //사방탐색
        for (int i = 0; i < 4; i++) {
            if (r + dx[i] >= 0 && c + dy[i] >= 0 && r + dx[i] < N && c + dy[i] < N && !visited[r + dx[i]][c + dy[i]]) { //바운더리 체크 & 방문 가능할 경우
                visited[r + dx[i]][c + dy[i]] = true;
                dfs(r + dx[i], c + dy[i]);
            }
        }
    }
}
