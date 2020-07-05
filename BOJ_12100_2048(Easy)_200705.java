/* 13460. 구슬 탈출 2 Gold 2
https://www.acmicpc.net/problem/13460
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
    static int[][] d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    static int N;
    static int max;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());

        int[][] map = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < 4; i++) {
            move(i, 1, copyArray(map));
        }
        System.out.println(max);
    }

    static int[][] copyArray(int[][] arr) {
        int[][] narr = new int[N][N];
        for (int i = 0; i < N; i++)
            System.arraycopy(arr[i], 0, narr[i], 0, N);
        return narr;
    }

    static void move(int dir, int cnt, int[][] map) {
        if (dir == UP) {
            moveVertical(map, 1, 0);
        } else if (dir == RIGHT) {
            moveHorizontal(map, -1, N - 1);
        } else if (dir == DOWN) {
            moveVertical(map, -1, N - 1);
        } else { //LEFT
            moveHorizontal(map, 1, 0);
        }

//        System.out.println("dir: " + dir + " cnt: " + cnt + "--------------");
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                System.out.print(map[i][j] + " ");
//            }
//            System.out.println();
//        }
//        System.out.println();

        if (cnt == 5) {
            max = Math.max(max, findMax(map));
            return;
        }

        for (int i = 0; i < 4; i++) {
            move(i, cnt + 1, copyArray(map));
        }
    }

    static void moveVertical(int[][] map, int var, int init) {
        for (int j = 0; j < N; j++) { //열
            int f = init, c, a;
            while (true) {
                c = f;
                while (c >= 0 && c < N && map[c][j] == 0) c += var;
                if (c < 0 || c >= N) break;

                a = c + var;
                while (a >= 0 && a < N && map[a][j] == 0) a += var;

                int tmp = map[c][j];
                if (a >= 0 && a < N && map[c][j] == map[a][j]) {
                    map[c][j] = map[a][j] = 0;
                    map[f][j] = tmp * 2;
                } else {
                    map[c][j] = 0;
                    map[f][j] = tmp;
                }
                f += var;
            }
        }
    }

    static void moveHorizontal(int[][] map, int var, int init) {
        for (int i = 0; i < N; i++) { //행
            int f = init, c, a;
            while (true) {
                c = f;
                while (c >= 0 && c < N && map[i][c] == 0) c += var;
                if (c < 0 || c >= N) break;

                a = c + var;
                while (a >= 0 && a < N && map[i][a] == 0) a += var;

                int tmp = map[i][c];
                if (a >= 0 && a < N && map[i][c] == map[i][a]) {
                    map[i][c] = map[i][a] = 0;
                    map[i][f] = tmp * 2;
                } else {
                    map[i][c] = 0;
                    map[i][f] = tmp;
                }
                f += var;
            }
        }
    }

    static int findMax(int[][] map) {
        int max = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (max < map[i][j]) max = map[i][j];
            }
        }
        return max;
    }
}