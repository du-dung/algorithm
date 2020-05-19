/* 2636. 치즈 Gold 5
https://www.acmicpc.net/problem/2636
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    static int N, M;
    static boolean[][] map, visited;
    static int time, cnt; //치즈가 모두 녹아 없어지는 데 걸리는 시간, 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken()); //행의 수
        M = Integer.parseInt(st.nextToken()); //열의 수

        map = new boolean[N][M];
        visited = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                if (st.nextToken().equals("1")) {
                    map[i][j] = true;
                    cnt++;
                }
            }
        }
        //end of input

        while (true) {
            time++;
            int tempCnt = cnt;
            for (boolean[] v : visited) {
                Arrays.fill(v, false);
            }

            //치즈 녹이기
            Queue<Node> queue = new LinkedList<>();
            queue.add(new Node(0, 0)); //치즈가 놓여 있지 않은 곳
            visited[0][0] = true;
            while (!queue.isEmpty()) {
                int x = queue.peek().x, y = queue.poll().y;
                for (int[] d : dir) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M //바운더리 체크
                            || visited[nx][ny]) continue; //이미 방문함
                    if (map[nx][ny]) {
                        tempCnt--; //치즈 녹는다
                        map[nx][ny] = false;
                    } else {
                        queue.add(new Node(nx, ny));
                    }
                    visited[nx][ny] = true;
                }
            }

            if (tempCnt == 0) break;
            cnt = tempCnt;
        }

        System.out.println(time);
        System.out.println(cnt);
    } //end of main

    static class Node {
        int x, y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
} //end of class
