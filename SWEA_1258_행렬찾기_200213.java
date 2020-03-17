/* 1258. [S/W 문제해결 응용] 7일차 - 행렬찾기 D4
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18LoAqItcCFAZN&categoryId=AV18LoAqItcCFAZN&categoryType=CODE
 */
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int testCase = 1; testCase <= T; testCase++) {
			int n = sc.nextInt();
			int[][] map = new int[n + 1][n + 1];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					map[i][j] = sc.nextInt();
				}
			}

			// solve
			List<Matrix> sub = new ArrayList<>(20);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (map[i][j] != 0) { // 화학물질 찾음
						// -> 사각형 크기 탐색
						int r = 1, c = 1;
						while (map[i + r][j] != 0)
							r++;
						while (map[i][j + c] != 0)
							c++;
//						r--;
//						c--;
						sub.add(new Matrix(r, c));

						// 찾은 사각형은 또 체크하지 않도록
						for (int x = 0; x < r; x++) {
							for (int y = 0; y < c; y++) {
								map[i + x][j + y] = 0;
							}
						}
					}
				}
			}

			Comparator<Matrix> myComparator = new Comparator<Matrix>() {
				@Override
				public int compare(Matrix o1, Matrix o2) {
					if (o1.size < o2.size)
						return -1;
					else if (o1.size == o2.size) {
						return o1.r < o2.r ? -1 : 1;
					} else {
						return 1;
					}
				}
			};
			Collections.sort(sub, myComparator);

			// print answer
			System.out.print("#" + testCase + " " + sub.size() + " ");
			for (int i = 0; i < sub.size(); i++) {
				System.out.print(sub.get(i).r + " " + sub.get(i).c + " ");
			}
			System.out.println();
		} // end of for test cases
		sc.close();
	}

	static class Matrix {
		int r, c, size;

		Matrix(int r, int c) {
			this.r = r;
			this.c = c;
			this.size = r * c;
		}
	}
}
