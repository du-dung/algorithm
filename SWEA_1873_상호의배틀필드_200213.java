/* 1873. 상호의 배틀필드 D3
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LyE7KD2ADFAXc&categoryId=AV5LyE7KD2ADFAXc&categoryType=CODE
 */
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int testCase = 1; testCase <= T; testCase++) {
			int H = sc.nextInt(), W = sc.nextInt();
			char[][] map = new char[H][W];
			for (int i = 0; i < H; i++) {
				String tmp = sc.next();
				for (int j = 0; j < W; j++) {
					map[i][j] = tmp.charAt(j);
				}
			}
			int N = sc.nextInt();
			String command = sc.next();

			// solve
			int x = 0, y = 0; // 전차의 위치 찾기
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					switch (map[i][j]) {
					case '^':
					case 'v':
					case '>':
					case '<':
						x = i;
						y = j;
					default:
						// do nothing
					}
				}
			}

			for (int i = 0; i < N; i++) {
				switch (command.charAt(i)) {
				case 'U':
					map[x][y] = '^';
					if (x - 1 >= 0 && map[x - 1][y] == '.') {
						map[x][y] = '.';
						x--;
						map[x][y] = '^';
					}
					break;
				case 'D':
					map[x][y] = 'v';
					if (x + 1 < H && map[x + 1][y] == '.') {
						map[x][y] = '.';
						x++;
						map[x][y] = 'v';
					}
					break;
				case 'L':
					map[x][y] = '<';
					if (y - 1 >= 0 && map[x][y - 1] == '.') {
						map[x][y] = '.';
						y--;
						map[x][y] = '<';
					}
					break;
				case 'R':
					map[x][y] = '>';
					if (y + 1 < W && map[x][y + 1] == '.') {
						map[x][y] = '.';
						y++;
						map[x][y] = '>';
					}
					break;
				case 'S':
					boolean flag = false;
					switch (map[x][y]) {
					case '^':
						for (int cannon = -1; x + cannon >= 0 && !flag; cannon--) {
							switch (map[x + cannon][y]) {
							case '*':
								map[x + cannon][y] = '.';
							case '#':
								flag = true;
							}
						}
						break;
					case 'v':
						for (int cannon = 1; x + cannon < H && !flag; cannon++) {
							switch (map[x + cannon][y]) {
							case '*':
								map[x + cannon][y] = '.';
							case '#':
								flag = true;
							}
						}
						break;
					case '<':
						for (int cannon = -1; y + cannon >= 0 && !flag; cannon--) {
							switch (map[x][y + cannon]) {
							case '*':
								map[x][y + cannon] = '.';
							case '#':
								flag = true;
							}
						}
						break;
					case '>':
						for (int cannon = 1; y + cannon < W && !flag; cannon++) {
							switch (map[x][y + cannon]) {
							case '*':
								map[x][y + cannon] = '.';
							case '#':
								flag = true;
							}
						}
						break;
					default:
						// do nothing
					} // end of switch cannon
				}// end of switch command
			} // end of for commands

			// print answer
			System.out.print("#" + testCase + " ");
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					System.out.print(map[i][j]);
				}
				System.out.println();
			}

		} // end of for test cases
		sc.close();
	}
}
