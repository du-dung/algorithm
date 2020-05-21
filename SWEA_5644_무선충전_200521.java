/* 5644. [모의 SW 역량테스트] 무선 충전
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRDL1aeugDFAUo&categoryId=AWXRDL1aeugDFAUo&categoryType=CODE
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution {
    static int M, A;
    static int[][] route = new int[2][100];
    static BC[] chargers = new BC[8];

    static int[][] dir = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    static int ax, ay, bx, by;
    static PriorityQueue<Integer> pqA = new PriorityQueue<>(new BC_Comparator()), pqB = new PriorityQueue<>(new BC_Comparator());
    static int answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int TC = Integer.parseInt(br.readLine());
        for (int testCase = 1; testCase <= TC; testCase++) {
            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            A = Integer.parseInt(st.nextToken());

            //사용자 이동 정보
            for (int i = 0; i < 2; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < M; j++) {
                    route[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            //BC 정보
            for (int i = 0; i < A; i++) {
                st = new StringTokenizer(br.readLine());
                chargers[i] = new BC(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            }
            //end of input

            answer = 0;
            ax = 1;
            ay = 1;
            bx = 10;
            by = 10;
            int t = 0;
            do {
                pqA.clear();
                pqB.clear();

                //접근 가능한 BC 찾기
                for (int i = 0; i < A; i++) {
                    if (chargers[i].isAccessible(ax, ay)) pqA.add(i);
                    if (chargers[i].isAccessible(bx, by)) pqB.add(i);
                }

                if (!pqA.isEmpty() && !pqB.isEmpty() && pqA.peek().equals(pqB.peek())) { //BC 겹침
                    answer += chargers[pqA.poll()].power;
                    pqB.poll();
                    if (pqA.isEmpty()) {
                        if (!pqB.isEmpty()) answer += chargers[pqB.poll()].power;
                    } else if (pqB.isEmpty()) {
                        answer += chargers[pqA.poll()].power;
                    } else { //사이즈가 같음 (0이 아님)
                        answer += Math.max(chargers[pqA.poll()].power, chargers[pqB.poll()].power);
                    }
                } else { //안겹침
                    if (!pqA.isEmpty()) answer += chargers[pqA.poll()].power;
                    if (!pqB.isEmpty()) answer += chargers[pqB.poll()].power;
                }
            } while (move(t++));

            System.out.printf("#%d %d\n", testCase, answer);
        }
    }

    static boolean move(int t) {
        if (t >= M) return false;
        ax += dir[route[0][t]][0];
        ay += dir[route[0][t]][1];
        bx += dir[route[1][t]][0];
        by += dir[route[1][t]][1];
        return true;
    }

    static class BC {
        int x, y, range, power;

        public BC(int y, int x, int range, int power) {
            this.x = x;
            this.y = y;
            this.range = range;
            this.power = power;
        }

        boolean isAccessible(int x, int y) {
            return range >= Math.abs(this.x - x) + Math.abs(this.y - y);
        }
    }

    static class BC_Comparator implements Comparator<Integer> {
        @Override
        public int compare(Integer o1, Integer o2) {
            return chargers[o2].power - chargers[o1].power;
        }
    }
}