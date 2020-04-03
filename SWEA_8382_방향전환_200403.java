/* 8382. 방향 전환 D4
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWyNQrCahHcDFAVP&categoryId=AWyNQrCahHcDFAVP&categoryType=CODE
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        for (int testCase = 1; testCase <= TC; testCase++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            //end of input
            sb.append('#').append(testCase).append(' ').append(func(Math.abs(x2 - x1), Math.abs(y2 - y1))).append('\n');
        } //end of testCases
        System.out.print(sb.toString());
    } //end of main

    static int func(int x, int y) {
        int abs = Math.abs(x - y);
        if (abs <= 1) {
            return x + y;
        }
        int ret = ((x < y ? x : y) + abs) * 2;
        if (abs % 2 == 1) ret--;
        return ret;
    }
} //end of class