/* 1228. [S/W 문제해결 기본] 8일차 - 암호문1 D3
 https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14w-rKAHACFAYD&categoryId=AV14w-rKAHACFAYD&categoryType=CODE
 */
import java.util.LinkedList;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int testCase = 1; testCase <= 10; testCase++) {
			//input & solve
			int lengthOfPassword= sc.nextInt(); //원본 암호문의 길이
			LinkedList<Integer> password = new LinkedList<>(); //원본 암호문
			for (int i = 0; i < lengthOfPassword; i++) {
				password.add(i, sc.nextInt());
			}
			int numOfCommands = sc.nextInt();
			for (int i = 0; i < numOfCommands; i++) {
				char command = sc.next().charAt(0); //무조건 l
				int index = sc.nextInt(); //index의 위치 바로 다음에
				int numOfInsertions = sc.nextInt(); //numOfInsertions개의 숫자를 삽입
				for (int j = 0; j < numOfInsertions; j++) {
					int insert = sc.nextInt();
					password.add(index++, insert);
				}
			}
			
			//output
			System.out.print("#" + testCase);
			for (int i = 0; i < 10; i++) {
				System.out.print(" " + password.get(i));
			}
			System.out.println();
		}
	}
}
