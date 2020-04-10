/* 1786. 찾기 Gold 2
https://www.acmicpc.net/problem/1786
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        String T = br.readLine(), P = br.readLine();

        int[] pi = new int[P.length()];
        int j = 0;
        for (int i = 1; i < P.length(); i++) {
            while (j > 0 && P.charAt(i) != P.charAt(j)) {
                j = pi[j - 1];
            }
            if (P.charAt(i) == P.charAt(j)) {
                pi[i] = ++j;
            }
        }

        int cnt = 0;
        j = 0;
        for (int i = 0; i < T.length(); i++) {
            while (j > 0 && T.charAt(i) != P.charAt(j)) {
                j = pi[j - 1];
            }
            if (T.charAt(i) == P.charAt(j)) {
                if (j == P.length() - 1) {
                    cnt++;
                    sb.append(i - j + 1).append(' ');
                    j = pi[j];
                } else {
                    j++;
                }
            }
        }

        System.out.println(cnt);
        System.out.print(sb.toString());
    }
}
