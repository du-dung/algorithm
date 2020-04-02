/* 6782. 현주가 좋아하는 제곱근 놀이 D5
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWgqsAlKr9sDFAW0&categoryId=AWgqsAlKr9sDFAW0&categoryType=CODE
*/

import java.io.*;
import java.util.*;

public class Solution {
    static int answer;
    static long N, target, nextN;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());
        for(int testCase=1; testCase<=TC; testCase++) {
            N = Long.parseLong(br.readLine());
            //N을 2로 만드는 것이 목표.. => 가장 가까운 제곱수를 찾아 증가 & sqrt 반복
            answer = 0;
            while(N != 2){
                nextN = (long) Math.ceil(Math.sqrt(N));
                target = (long) Math.pow(nextN, 2);
                answer += target - N + 1;
                N = nextN;
            }
            System.out.printf("#%d %d\n", testCase, answer);
        }
    }
}