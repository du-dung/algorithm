/* 4366. 정식이의 은행업무 D4
 https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWMeRLz6kC0DFAXd
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());
        for (int testCase = 1; testCase <= TC; testCase++) {
            char[] bin = br.readLine().trim().toCharArray();
            char[] ten = br.readLine().trim().toCharArray();

            int answer = 0;

            f:
            for (int b = 0; b < bin.length; b++) { //bin의 b번째 수가 잘못됨
                bin[b] = bin[b] == '0' ? '1' : '0'; //2진수는 무조건 0 아니면 1 -> 잘못되었으면 무조건 다른 수
                for (int t = 0; t < ten.length; t++) { //ten의 t번째 수가 잘못됨
                    char origin = ten[t];
                    for (int i = 0; i < 3; i++) { //3진수는 0, 1, 2
                        if (i == origin - '0') continue;
                        ten[t] = (char) (i + '0');
                        if (binaryToDecimal(bin) == tenaryToDecimal(ten)) {
                            answer = binaryToDecimal(bin);
                            break f;
                        }
                    }
                    ten[t] = origin;
                }
                bin[b] = bin[b] == '0' ? '1' : '0'; //원상복구
            }

            System.out.printf("#%d %d\n", testCase, answer);
        }
    }

    static int binaryToDecimal(char[] s) {
        int ret = 0;
        for (int i = s.length - 1, mul = 1; i >= 0; i--, mul *= 2) {
            ret += (s[i] - '0') * mul;
        }
        return ret;
    }

    static int tenaryToDecimal(char[] s) {
        int ret = 0;
        for (int i = s.length - 1, mul = 1; i >= 0; i--, mul *= 3) {
            ret += (s[i] - '0') * mul;
        }
        return ret;
    }
}
