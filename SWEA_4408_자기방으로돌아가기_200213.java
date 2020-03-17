/* 4408. 자기 방으로 돌아가기 D4
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWNcJ2sapZMDFAV8&categoryId=AWNcJ2sapZMDFAV8&categoryType=CODE
 */
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Solution {
	static boolean[] rooms;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int testCase = 1; testCase <= T; testCase++) {
			int N = sc.nextInt(); // 돌아가야 할 학생들의 수

			List<Pair> list = new ArrayList<>();
			for (int i = 0; i < N; i++) {
				list.add(new Pair(sc.nextInt(), sc.nextInt()));
			}

			Collections.sort(list); // 시작점과 도착점 중 작은 것 기준, 오름차순으로 정렬

			int n = 0; // 돌아간 학생의 수
			int answer = 0; // 회차
			while (n < N) { // 모든 학생이 돌아갈 때까지
				rooms = new boolean[200]; // 아직 점유되지 않음
				for (int i = 0; i < list.size(); i++) {
					if (isNotUsed(list.get(i))) { // 이동 가능하면
						for (int j = list.get(i).a; j <= list.get(i).b; j++) {
							rooms[j] = true; // 점유
						}
						list.remove(i);
						i--;
						n++;
					}
				} // end of for 한 회차
				answer++;
			}

			System.out.println("#" + testCase + " " + answer);
		} // end of for testCases
		sc.close();
	} // end of main

	/** 점유된 구간이 있으면 false, 모두 비어있으면 (이동 가능하면) true */
	static boolean isNotUsed(Pair p) {
		for (int i = p.a; i <= p.b; i++) {
			if (rooms[i])
				return false;
		}
		return true;
	}

	static class Pair implements Comparable<Pair> {
		int a, b;

		public Pair(int a, int b) { // a가 시작점, b가 도착점 -> b는 배열 인덱스 + 1
			super();
			if (a < b) { // 시작점의 방 번호가 앞쪽
				this.a = a % 2 == 0 ? (a - 1) / 2 : a / 2; // 방 번호를 배열에 맞게 해주기 위해서, 홀수방이면 그냥 /2, 짝수방이면 -1 해주고 /2
				this.b = b % 2 == 0 ? (b - 1) / 2 : b / 2;
			} else { // 시작점의 방 번호가 뒤쪽
				this.a = b % 2 == 0 ? (b - 1) / 2 : b / 2;
				this.b = a % 2 == 0 ? (a - 1) / 2 : a / 2;
				;
			}
		}

		/** a, b 중 작은 것 기준으로 오름차순 */
		@Override
		public int compareTo(Pair o) {
			if (a < b)
				if (a == o.a)
					return b < o.b ? -1 : 1;
			return a < o.a ? -1 : 1;
		}
	}
} // end of class
