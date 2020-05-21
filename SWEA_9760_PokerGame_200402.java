/* 9760. Poker Game D4
https://swexpertacademy.com/main/code/userProblem/userProblemDetail.do?contestProbId=AXEN3aEKDrsDFAVX&categoryId=AXEN3aEKDrsDFAVX&categoryType=CODE
*/
import java.io.*;
import java.util.*;

public class Solution {
    static int[] shoot, rank;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int TC = Integer.parseInt(br.readLine());
        for(int testCase=1; testCase<=TC; testCase++) {
            st = new StringTokenizer(br.readLine());
            String tmp;
            shoot = new int[4]; //S, D, H, C
            rank = new int[13]; //A, 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K
            for (int i=0; i<5; i++){
                tmp = st.nextToken();
                switch (tmp.charAt(0)){
                    case 'S':
                        shoot[0]++;
                        break;
                    case 'D':
                        shoot[1]++;
                        break;
                    case 'H':
                        shoot[2]++;
                        break;
                    case 'C':
                        shoot[3]++;
                }
                switch (tmp.charAt(1)){
                    case 'A':
                        rank[0]++;
                        break;
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        rank[tmp.charAt(1) - '1']++;
                        break;
                    case 'T':
                        rank[9]++;
                        break;
                    case 'J':
                        rank[10]++;
                        break;
                    case 'Q':
                        rank[11]++;
                        break;
                    case 'K':
                        rank[12]++;
                        break;
                }
            } //end of input
            System.out.println("#" + testCase + " " + findHand());
        }
    }
    static String findHand(){
        boolean isFlush = false, isStraight = false, isFourCard = false, isTriple = false;
        int pair=0; //pair 개수
        for (int i=0; i<4; i++){ //flush 판별
            if (shoot[i] == 5)  isFlush = true;
        }
        for (int i=0; i<13; i++){ //포카드 & 트리플 & 페어 판별
            switch (rank[i]){
                case 4:
                    isFourCard = true;
                    break;
                case 3:
                    isTriple = true;
                    break;
                case 2:
                    pair++;
            }
        }
        if (!isFourCard && !isTriple && pair == 0){ //스트레이트 판별
            int n = 0;
            for (int i = 0; i<13; i++){
                if (rank[i] == 1){
                    n=1;
                    for (int j=i+1; j<13 && j<i+5; j++){
                        if (rank[j] == 1){
                            n++;
                        }
                    }
                    if(n == 5)  isStraight = true; //5개가 연속 -> 스트레이트
                    break;
                }
            }
            //TJQKA 판별
            if(rank[0] == 1){ //A 있고
                n=0;
                for (int i=9; i<13; i++){
                    if (rank[i] == 1){
                        n++;
                    }
                }
                if(n==4) isStraight = true; //TJQK 있음
            }
        }
        if (isFlush && isStraight)  return "Straight Flush";
        if (isFourCard) return "Four of a Kind";
        if (isTriple && pair==1)    return "Full House";
        if (isFlush)    return "Flush";
        if (isStraight) return "Straight";
        if (isTriple)   return "Three of a kind";
        if (pair == 2)  return "Two pair";
        if (pair == 1)  return "One pair";
        return "High card";
    }
}