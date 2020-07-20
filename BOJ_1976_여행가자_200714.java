/* 1976. 여행 가자 Gold 4
https://www.acmicpc.net/problem/1976
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static boolean[][] city;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        city = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                city[i][j] = '1' == st.nextToken().charAt(0);
            }
        }

        connectCities();

        int[] route = new int[M];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            route[i] = Integer.parseInt(st.nextToken()) - 1; //입력은 도시 번호가 1부터 시작
        }

        bw.write(isPossible(route));
        bw.flush();
    }

    static void connectCities(){ //floyd
        for (int k = 0; k < N; k++) {
            city[k][k] = true;
            for (int i = 0; i < N; i++) {
                for (int j = i+1; j < N; j++) {
                    if(city[i][k] && city[k][j])
                        city[i][j] = city[j][i] = true;
                }
            }
        }
    }

    static String isPossible(int[] route){
        for (int i = 0; i < M-1; i++) {
            if(!isConnected(route[i], route[i+1])) return "NO";
        }
        return "YES";
    }

    static boolean isConnected(int a, int b){
        return city[a][b];
    }
}