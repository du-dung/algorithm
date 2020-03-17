/* 1231. [S/W 문제해결 기본] 9일차 - 중위순회 D4
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV140YnqAIECFAYD&categoryId=AV140YnqAIECFAYD&categoryType=CODE
 */
import java.util.Scanner;

public class Solution {
	static String answer;
	static int N;
	static char[] tree;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int testCase = 1; testCase <= 10; testCase++) {
			N = Integer.parseInt(sc.nextLine()); // 트리가 갖는 정점의 총 수
			tree = new char[N + 1];
			answer = "";
			for (int i = 1; i <= N; i++) {
				String s = sc.nextLine(); // 각각의 정점 정보
				String[] ss = s.split(" ");
				tree[i] = ss[1].charAt(0);
			}
			inorder(1);
			System.out.println("#" + testCase + " " + answer);
		} // end of for testcases
		sc.close();
	}

	static void inorder(int v) {
		if (v > N)
			return;
		inorder(v * 2);
		answer += tree[v];
		inorder(v * 2 + 1);
	}
}
