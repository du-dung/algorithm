/* 1062. 가르침 Gold 4
https://www.acmicpc.net/problem/1062
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, K;
    static char[][] words;
    static boolean[] select = new boolean[26]; //a-z
    static boolean[] selectable = new boolean[26]; //a-z, 단어에 포함되는 문자
    static int answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        words = new char[N][];
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine().trim();
            words[i] = tmp.substring(4, tmp.length() - 4).toCharArray();
        }
        //end of input

        if (K < 5) { //아무 것도 못 읽는다!
            System.out.println(0);
            return;
        } else if (K >= 26) {
            System.out.println(N);
            return;
        }

        K -= 5; //a 0, c 2, i 8, n 13, t 19는 필수
        select[0] = select[2] = select[8] = select[13] = select[19] = true;

        //단어에 포함되는 문자 찾기
        for (char[] word : words) {
            for (char c : word) {
                if (!select[c - 'a']) { //a, c, i, n, t인 경우는 제외
                    selectable[c - 'a'] = true;
                }
            }
        }

        //배울 필요가 있는 문자 개수?
        int tmp = 0;
        for (int i = 1; i < 26; i++) {
            if (selectable[i]) tmp++;
        }

        if (tmp > K) //조합 필요
            comb(K, 1);
        else { //다 배울 수 있음
            answer = N;
        }
        System.out.println(answer);
    }

    static void comb(int cnt, int start) { //공부할 K-5개 문자 고르기
        if (start + cnt > 26) return; //남은 문자가 모자라
        if (cnt == 0) { //K개 다 고름
            run();
            return;
        }

        for (int i = start; i < 26; i++) {
            if (!select[i] && selectable[i]) {
                select[i] = true;
                comb(cnt - 1, i + 1);
                select[i] = false;
            }
        }
    }

    static void run() {
        int readableCnt = 0;
        f:
        for (char[] word : words) {
            for (char c : word) {
                if (!select[c - 'a']) { //읽을 수 없음 -> 다음 단어로
                    continue f;
                }
            }
            readableCnt++;
        }
        if (readableCnt > answer) answer = readableCnt;
    }
}