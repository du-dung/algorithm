/* 7453. 합이 0인 네 정수 Gold 2
https://www.acmicpc.net/problem/7453
*/
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        arr = new int[4][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 4; j++) {
                arr[j][i] = Integer.parseInt(st.nextToken());
            }
        }

        int len = N*N;
        int[] s1 = new int[len];
        int[] s2 = new int[len];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                s1[i*N + j] = arr[0][i] + arr[1][j];
                s2[i*N + j] = arr[2][i] + arr[3][j];
            }
        }
        Arrays.sort(s1);
        Arrays.sort(s2);

        int idx1 = 0, idx2 = len-1;
        long answer = 0;
        while (idx1<len && idx2>=0){
            long sum = s1[idx1] + s2[idx2];
            if(sum < 0) idx1++;
            else if(sum > 0) idx2--;
            else{
                int cnt1=1, cnt2=1;
                while(idx1+cnt1 < len && s1[idx1] == s1[idx1+cnt1]) cnt1++;
                while(idx2-cnt2 >= 0 && s2[idx2] == s2[idx2-cnt2]) cnt2++;
                answer += (long)cnt1*cnt2;
                idx1 += cnt1;
                idx2 -= cnt2;
            }
        }

        bw.write("" + answer);
        bw.flush();
    }
}