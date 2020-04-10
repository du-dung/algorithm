/* 16916. 부분 문자열 Gold 3
 * https://www.acmicpc.net/problem/16916
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine(), P = br.readLine();
        //P가 S의 부분 문자열인가?
        System.out.println(KMP(S, P)? 1 : 0);
    } //end of main

    static int[] getPi(String pattern){
        int[] pi = new int[pattern.length()];
        int j=0;
        for (int i = 1; i < pattern.length(); i++) {
            while (j > 0 && pattern.charAt(i) != pattern.charAt(j)) {
                j = pi[j - 1];
            }
            if (pattern.charAt(i) == pattern.charAt(j)) {
                pi[i] = ++j;
            }
        }
        return pi;
    }

    static boolean KMP(String origin, String pattern){
        int[] pi = getPi(pattern);
        int j=0;
        for (int i = 0; i < origin.length(); i++) {
            while(j>0 && origin.charAt(i) != pattern.charAt(j)){
                j = pi[j-1];
            }
            if (origin.charAt(i) == pattern.charAt(j)){
                if (j == pattern.length()-1){
                    return true;
                }
                j++;
            }
        }
        return false;
    }
} //end of class
