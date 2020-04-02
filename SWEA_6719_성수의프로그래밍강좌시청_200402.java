/* 6719. 성수의 프로그래밍 강좌 시청 D4
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWd7sgDatsMDFAUh&categoryId=AWd7sgDatsMDFAUh&categoryType=CODE
*/

import java.io.*;
import java.util.*;

public class Solution {
    static int[] courses;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int TC = Integer.parseInt(br.readLine());
        for(int testCase=1; testCase<=TC; testCase++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            courses = new int[N];
            for (int i=0; i<N; i++){
                courses[i] = Integer.parseInt(st.nextToken());
            } //end of input
            Arrays.sort(courses);
            float answer = 0;
            for (int i=N-K; i<N; i++){
                answer = (answer + courses[I])/(float)2;
            }
            System.out.printf("#%d %.6f\n", testCase, answer);
        }
    }
}