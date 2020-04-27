/* 16234. 인구 이동 Gold 5
https://www.acmicpc.net/problem/16234
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());
        int[][] A = new int[N + 2][N + 2];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        //solve
        for (int i = 0; i < N + 2; i++) {
            A[i][0] = A[0][i] = A[i][N + 1] = A[N + 1][i] = -1;
        }
        int answer = -1;
        boolean flag = true;
        int[][] dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        List<Pair> union = new LinkedList<>();
        boolean[][] checked;
        while (flag) {
            flag = false;
            answer++;
            checked = new boolean[N + 2][N + 2];

            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (checked[i][j]) continue;
                    checked[i][j] = true;
                    int sum = A[i][j];
                    union.add(new Pair(i, j));

                    int index = 0;
                    while (index < union.size()) { // bfs 시작
                        Pair p = union.get(index++);
                        for (int k = 0; k < 4; k++) { //4방향 탐색
                            int nx = p.x + dir[k][0], ny = p.y + dir[k][1];
                            if (A[nx][ny] == -1 || checked[nx][ny]) continue; //바운더리 or 이미 체크
                            int diff = Math.abs(A[p.x][p.y] - A[nx][ny]);
                            if (diff >= L && diff <= R) {
                                checked[nx][ny] = true;
                                union.add(new Pair(nx, ny));
                                sum += A[nx][ny];
                            }
                        }
                    } //bfs 끝

                    if (union.size() > 1) flag = true; //국경선 열었음
                    int avg = sum / union.size();
                    for (Pair p : union) {
                        A[p.x][p.y] = avg;
                    }
//                    union.forEach(p -> A[p.x][p.y] = avg); 200ms 차이남;;
                    union.clear();
                }
            }
        }
        System.out.println(answer);
    }

    static class Pair {
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
