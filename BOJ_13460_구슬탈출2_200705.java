/* 13460. 구슬 탈출 2 Gold 2
https://www.acmicpc.net/problem/13460
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[][] d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    static char[][] map;
    static int answer = 11;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new char[N][];
        for (int i = 0; i < N; i++) {
            map[i] = br.readLine().toCharArray();
        }

        Pos red = null, blue = null; //빨간구슬 파란구슬
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if (map[i][j] == 'R') {
                    red = new Pos(i, j);
                } else if (map[i][j] == 'B') {
                    blue = new Pos(i, j);
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            tilt(i, 1, new Pos(red), new Pos(blue));
        }

        System.out.println(answer == 11 ? -1 : answer);
    }

    static void tilt(int dir, int cnt, Pos red, Pos blue) {
        if (cnt >= answer || cnt > 10) return;

        //어떤 구슬이 먼저 굴러가는지
        boolean flag = (dir == 0 && red.x < blue.x) || (dir == 2 && red.x > blue.x) ||
                (dir == 1 && red.y > blue.y) || (dir == 3 && red.y < blue.y);

        if (move(dir, blue)) return; //파란 공 빠지면 실패
        else if (move(dir, red) && cnt < answer) {
            answer = cnt;
            return;
        }

        if (blue.equals(red)) { //구슬은 겹칠 수 없다
            if (flag) { //빨간 구슬을 먼저 굴렸음 -> 파란 구슬이 한 칸 뒤로
                blue.x -= d[dir][0];
                blue.y -= d[dir][1];
            } else {
                red.x -= d[dir][0];
                red.y -= d[dir][1];
            }
        }

        for (int i = 0; i < 4; i++) {
            if (dir != i) tilt(i, cnt + 1, new Pos(red), new Pos(blue));
        }
    }

    static boolean move(int dir, Pos p) {
        do {
            p.x += d[dir][0];
            p.y += d[dir][1];
            if (map[p.x][p.y] == 'O') return true;
        } while (map[p.x][p.y] != '#');

        p.x -= d[dir][0];
        p.y -= d[dir][1]; //한 칸 더 갔으니까 뒤로 돌려주기
        return false;
    }

    static class Pos {
        int x, y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Pos(Pos p) {
            this.x = p.x;
            this.y = p.y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pos pos = (Pos) o;
            return x == pos.x && y == pos.y;
        }
    }
}