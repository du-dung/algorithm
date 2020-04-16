/* 11726. 2xn 타일링 Silver 3
https://www.acmicpc.net/problem/11726
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] fibo = new int[n + 1];
        fibo[0] = 1;
        fibo[1] = 1;
        for (int i = 2; i <= n; i++) {
            fibo[i] = (fibo[i - 2] + fibo[i - 1]) % 10007;
        }
        System.out.println(fibo[n]);
    }
}
