/* 1949. [모의 SW 역량테스트] 등산로 조성
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq
*/
import java.io.*;
import java.util.*;

public class Solution {
    public static int N, K;
    static int[][] map;
    static boolean[][] visited;
    static int answer;
    static int[][] dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());;
        int TC = Integer.parseInt(st.nextToken());
        for (int testCase = 1; testCase <= TC; testCase++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            map = new int[N][N];
            int max = 0;
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    if (max < map[i][j]) max = map[i][j];
                }
            }

            //solve
            answer = 0;
            visited = new boolean[N][N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (map[i][j] == max) {
                        visited[i][j] = true;
                        dfs(i, j, 1, false);
                        visited[i][j] = false;
                    }
                }
            }
            System.out.println("#" + testCase + " " + answer);
        }
    }

    static void dfs(int x, int y, int len, boolean did) { //len은 등산로 길이, did는 지형을 깎았는지
        if (len > answer) answer = len;

        for (int i = 0; i < 4; i++) {
            int nx = x+dir[i][0], ny = y+dir[i][1];
            if (nx < 0 || ny < 0 || nx>= N || ny >= N || visited[nx][ny]) continue; //범위 초과
            if (map[nx][ny] < map[x][y]){ //내려갈 수 있음
                visited[nx][ny] = true;
                dfs(nx, ny, len+1, did);
                visited[nx][ny] = false;
            }else if(!did && map[nx][ny] - map[x][y] < K){ //지형을 아직 깎은 적이 없고, 깎으면 내려갈 수 있음!
                int temp = map[nx][ny];
                map[nx][ny] = map[x][y]-1; //임시로 깎기
                visited[nx][ny] = true;
                dfs(nx, ny, len+1, true);
                map[nx][ny] = temp; //원상복구
                visited[nx][ny] = false;
            }
        }
    }
}