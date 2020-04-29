/* 5658. [모의 SW 역량테스트] 보물상자 비밀번호
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo&categoryId=AWXRUN9KfZ8DFAUo&categoryType=CODE
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int TC = Integer.parseInt(br.readLine());
        for (int testCase = 1; testCase <= TC; testCase++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            String num = br.readLine();

            HashSet<String> set = new HashSet<>();
            int len = N / 4;
            num += num.substring(0, len - 1);
            for (int i = 0; i < len; i++) { //0 ~ len-1회전
                for (int j = 0; j < 4; j++) {
                    set.add(num.substring(i + j * len, i + (j + 1) * len));
                }
            }

            Object[] list = set.toArray();
            Arrays.sort(list);

            System.out.println("#" + testCase + " " + Integer.parseInt((String)list[list.length-K], 16));
        } //end of for testcase
    } //end of main
} //end of class
