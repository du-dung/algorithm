/* 2579. 계단 오르기 Silver 3
https://www.acmicpc.net/problem/2579
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] stairs = new int[N];
        for (int i = 0; i < N; i++) {
            stairs[i] = Integer.parseInt(br.readLine());
        }

        if (N < 3) { //예외처리 -> index out of bound 방지
            if (N == 0) System.out.println(0);
            else if (N == 1) System.out.println(stairs[0]);
            else System.out.println(stairs[0] + stairs[1]);
            System.exit(0);
        }

        int[] scores = new int[N];
        scores[0] = stairs[0];
        scores[1] = stairs[0] + stairs[1];
        scores[2] = Math.max(stairs[1] + stairs[2], stairs[0] + stairs[2]);
        for (int i = 3; i < N; i++) {
            scores[i] = Math.max(scores[i - 3] + stairs[i - 1] + stairs[i], scores[i - 2] + stairs[i]);
        }

        System.out.println(scores[N-1]);
    } //end of main
}
