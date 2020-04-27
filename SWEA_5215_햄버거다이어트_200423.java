/* 5215. 햄버거 다이어트 D3
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWT-lPB6dHUDFAVT&categoryId=AWT-lPB6dHUDFAVT&categoryType=CODE
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for (int testCase = 1; testCase <= T; testCase++) {
            st  = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()), L = Integer.parseInt(st.nextToken());
            int[] score = new int[N+1], kal = new int[N+1];
            for (int i = 1; i <= N; i++) {
                st = new StringTokenizer(br.readLine());
                score[i] = Integer.parseInt(st.nextToken());
                kal[i] = Integer.parseInt(st.nextToken());
            }

            int[][] res = new int[N+1][L+1];
            for (int i = 1; i <= N; i++) {
                for (int j = 0; j < kal[i]; j++) {
                    res[i][j] = res[i-1][j];
                }
                for (int j = kal[i]; j <= L; j++) {
                    res[i][j] = Math.max(res[i-1][j], res[i-1][j-kal[i]]+score[i]);
                }
            }

            System.out.println("#" + testCase + " " + res[N][L]);
        }
    }
}
