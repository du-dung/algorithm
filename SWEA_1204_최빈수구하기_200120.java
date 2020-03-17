/* 1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기 D2
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV13zo1KAAACFAYh&categoryId=AV13zo1KAAACFAYh&categoryType=CODE

점수 별 학생 수를 기록하는 배열 생성
	-> 입력받은 숫자(점수)를 index로 해서 배열 값 1씩 증가시키기
	=> 가장 값이 큰 index가 정답
*/
import java.util.Scanner;
 
class Solution {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T;
        T=sc.nextInt();
         
        for(int test_case = 1; test_case <= T; test_case++)
        {
            test_case = sc.nextInt();
            int[] score = new int[101];
            int temp;
            for (int i = 0; i < 1000; i++) {
                temp = sc.nextInt();
                score[temp]++;
            }
      
            int ans = 0, num = 0; //ans: 최빈수, num: 최빈수가 등장한 횟수
            for (int i = 0; i < 101; i++) {
                if (score[i] >= num) {
                    num = score[i];
                    ans = i;
                }
            }
            System.out.println("#"+test_case+" "+ans);
        }
    }
}
