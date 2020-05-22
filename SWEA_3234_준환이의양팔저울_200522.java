/* 3234. 준환이의 양팔저울 D4
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWAe7XSKfUUDFAUw&categoryId=AWAe7XSKfUUDFAUw&categoryType=CODE
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
    static int[] w = new int[9]; //각 무게추의 무게
    static int N;
    static int answer;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int TC = Integer.parseInt(br.readLine());
        for (int testCase = 1; testCase <= TC; testCase++) {
            N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                w[i] = Integer.parseInt(st.nextToken());

            }
            //end of input

            Arrays.sort(w, 0, N);
            answer = 0;
            //1. 순열 만들기
            do {
                //2. 각 순열에서 왼쪽, 오른쪽에 올리는 순서에 따른 경우의 수 구하기
                dfs(0, 0, 0);
            } while (next_permutation(0, N - 1));

            sb.append('#').append(testCase).append(' ').append(answer).append('\n');
        }
        System.out.print(sb.toString());
    } //end of main

    static boolean next_permutation(int begin, int end) {
        //1. 꼭대기 찾기
        int i = end;
        while (i > 0 && w[i - 1] >= w[i]) i--;
        if (i == 0) return false;

        //2. i-1과 바꿀 가장 큰 수 찾기
        int j = end;
        while (i < j && w[i - 1] >= w[j]) j--;

        //3. swap
        int tmp = w[i - 1];
        w[i - 1] = w[j];
        w[j] = tmp;

        //4. 내림차순 만들기
        while (i < end) {
            tmp = w[i];
            w[i] = w[end];
            w[end] = tmp;
            i++;
            end--;
        }

        return true;
    }

    static void dfs(int idx, int left, int right) {
        if (idx >= N) {
            answer++;
            return;
        }
        dfs(idx + 1, left + w[idx], right);
        if (left >= right + w[idx])
            dfs(idx + 1, left, right + w[idx]);
    }
} //end of class
