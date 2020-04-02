/* 5607. [Professional] 조합 D3
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXGKdbqczEDFAUo&categoryId=AWXGKdbqczEDFAUo&categoryType=CODE
 */
import java.io.*;
import java.util.*;

public class Solution {
    static long answer;
    static long[] fact = new long[1000001];
    final static int DIV = 1234567891;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        calculateFactorial();
        int TC = Integer.parseInt(br.readLine());
        for(int testCase=1; testCase<=TC; testCase++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()), R = Integer.parseInt(st.nextToken());
            // N comb R % DIV
            answer = comb(N, R);
            System.out.printf("#%d %d\n", testCase, answer);
        }
    }

    static void calculateFactorial(){
        //n! 구해놓기 -> 1000000까지 (최대범위)
        fact[1] = 1; fact[2] = 2;
        for (int i=3; i<=1000000; i++){
            fact[i] = (fact[i-1] * i) % DIV;
        }
    }

    static long comb(int n, int r){ // return nCr % DIV
        long ret = fact[n] % DIV; //n! % DIV
        ret *= powcal(fact[n-r] * fact[r] % DIV, DIV-2) % DIV; //((n-r)! ^ DIV-2) % DIV -> 역원
        return ret % DIV;
    }

    public static long powcal(long num, long p) {
        if(p == 0) return 1;

        long result = (powcal(num, p / 2)) % DIV;
        result = (result * result) % DIV;
        if(p % 2 == 1) {
            result = (result * num) % DIV;
        }

        return result;
    }
}