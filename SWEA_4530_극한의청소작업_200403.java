/* 4530. 극한의 청소 작업 D4
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWO6cgzKOIEDFAWw&categoryId=AWO6cgzKOIEDFAWw&categoryType=CODE
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    static long answer;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for (int testCase = 1; testCase <= TC; testCase++) {
            st = new StringTokenizer(br.readLine());
            long A = Long.parseLong(st.nextToken()), B = Long.parseLong(st.nextToken());
            //end of input

            if (A < 0 && B > 0) answer = func(Math.abs(A)) + func(Math.abs(B)) - 1; //0층은 없으니까 1 감소
            else if (A > 0 && B > 0) answer = func(Math.abs(B)) - func(Math.abs(A));
            else answer = func(Math.abs(A)) - func(Math.abs(B)); // A<0 && B<0
            System.out.println("#" + testCase + " " + answer);
        }
    } //end of main

    // 입력이 (10진수의 형태를 가진) 9진수라고 생각하고, 10진수로 변환시켜준다.
    static long func(long n) {
        long res = 0, ex = 1, tmp;
        while (n > 0) {
            tmp = n % 10; //가장 뒤의 자리 수 떼어내기
            if (tmp >= 4) tmp--; //4는 포함하지 않으니까 1 감소시켜주고
            res += tmp * ex;
            ex *= 9;
            n /= 10; //자리수 감소
        }
        return res;
    }
} //end of class