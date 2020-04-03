/* 9659. 다항식 계산 D4
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXCjsn0KJzcDFAX0&categoryId=AXCjsn0KJzcDFAX0&categoryType=CODE
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    static final int DIV = 998244353;
    static int N, M;
    static int[] t = new int[51], a = new int[51], b = new int[51];
    static long[] fn = new long[51];
    static long x;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        fn[0] = 1;
        for (int testCase = 1; testCase <= TC; testCase++) {
            sb.append('#').append(testCase);
            N = Integer.parseInt(br.readLine()); // 2 <= N <= 50
            for (int i = 2; i <= N; i++) {
                st = new StringTokenizer(br.readLine());
                t[i] = Integer.parseInt(st.nextToken());
                a[i] = Integer.parseInt(st.nextToken());
                b[i] = Integer.parseInt(st.nextToken()); //ti, ai, bi 입력
            }
            M = Integer.parseInt(br.readLine()); //1 <= M <= 50
            st = new StringTokenizer(br.readLine()); //M개의 정수
            for (int i = 0; i < M; i++) {
                sb.append(' ');
                x = Long.parseLong(st.nextToken());
                fn[1] = x;
                for (int j = 2; j <= N; j++) {
                    switch (t[j]){
                        case 1:
                            fn[j] = (fn[a[j]] + fn[b[j]]) % DIV;
                            break;
                        case 2:
                            fn[j] = a[j] * fn[b[j]] % DIV;
                            break;
                        case 3:
                            fn[j] = fn[a[j]] * fn[ b[j]] % DIV;
                    }
                }
                sb.append(fn[N]);
            }
            sb.append('\n');
        } //end of testCases
        System.out.print(sb.toString());
    } //end of main
} //end of class