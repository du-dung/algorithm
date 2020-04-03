/* 이항 계수 3 Gold 1
https://www.acmicpc.net/problem/11401
 */
import java.io.*;
import java.util.*;

public class Main {
    static long answer;
    static long[] fact = new long[4000001];
    final static int DIV = 1000000007;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());

        calculateFactorial(N);
        answer = comb(N, K);
        System.out.println(answer);
    }

    static void calculateFactorial(int n){
        //n! 구해놓기 -> N까지
        fact[0] = 1; fact[1] = 1;
        for (int i=2; i<=n; i++){
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