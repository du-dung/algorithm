/* 11726. 2xn 타일링 2 Silver 3
https://www.acmicpc.net/problem/11727
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] tile = new int[n + 2]; //n==1일 때 런타임 에러 방지
        tile[1] = 1;
        tile[2] = 3;
        for (int i = 3; i <= n; i++) {
            tile[i] = tile[i-1] * 2 % 10007;
            if(i%2 == 0)    tile[i]++;
            else            tile[i]--;
        }
        System.out.println(tile[n]);
    }
}
