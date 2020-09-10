/* 14891. 톱니바퀴 Silver 1
https://www.acmicpc.net/problem/14891
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int K;
	static char[][] wheels;
	static int[] up = {0, 0, 0, 0};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		wheels = new char[4][];
		for (int i = 0; i < 4; i++) {
			wheels[i] = br.readLine().toCharArray();
		}
		st = new StringTokenizer(br.readLine());
		K = Integer.parseInt(st.nextToken());
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int no = Integer.parseInt(st.nextToken()) - 1;
			int dir = Integer.parseInt(st.nextToken());
			// 반시계 (-1) => 12시의 번호 + 1
			// 시계 (+1) => 12시 번호 + 7
			turn(no, dir == 1 ? 7 : 1, true, true);
		}

		//calculate score
		int score = 0;
		for (int i = 0; i < 4; i++) {
			if (wheels[i][up[i]] == '1')
				score += Math.pow(2, i);
		}
		System.out.print(score);
	}

	static void turn(int no, int dir, boolean go_left, boolean go_right) {
		int nd = dir == 1 ? 7 : 1;
		if (go_left && no > 0) { //왼쪽 돌릴 수 있음
			if (wheels[no - 1][(up[no - 1] + 2) % 8] != wheels[no][(up[no] + 6) % 8]) {
				turn(no - 1, nd, true, false);
			}
		}
		if (go_right && no < 3) { //오른 쪽 돌릴 수 있음
			if (wheels[no][(up[no] + 2) % 8] != wheels[no + 1][(up[no + 1] + 6) % 8]) {
				turn(no + 1, nd, false, true);
			}
		}
		up[no] = (up[no] + dir) % 8;
	}
}