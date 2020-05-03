/*  17135. 캐슬 디펜스 Gold 4
 https://www.acmicpc.net/problem/17135
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static int N, M, D; // 공격 거리 제한
	static int answer; // 궁수의 공격으로 제거할 수 있는 적의 최대 수

	static void kill(int[] archer, int[][] map) { // 궁수가 archer[0],[1],[2] 위치에 있을 때 죽일 수 있는 적의 수를 반환
		int num = 0;
		ArrayList<Pair> diedEnemy = new ArrayList<>();
//	    vector<pair<int, int>> diedEnemy;
		for (int wall = map.length; wall > 0; wall--) { // wall은 궁수가 위치한 행. 즉 성벽. 적을 한 행씩 밑으로 내리는 대신 성벽을 위로 올림
			for (int i = 0; i < 3; i++) { // c1 : archer[i]
				// 죽일 적 찾기 -> 거리가 가장 가까운 적 & 가장 왼쪽
				// dx (d-dy) : 행 거리 (d ~ 1), dy : 열 거리 (0 ~ d-1)
				boolean flag = false;
				for (int d = 1; d <= D; d++) { // 최소 거리 1 ~ 최대 거리 D까지 탐색
					for (int dy = -d + 1; dy < 0; dy++) { // 가장 왼쪽인 적부터 -> 적이 궁수보다 왼쪽, x는 무조건 1 이상 차이나야 함
						int dx = d + dy;
						if (wall - dx >= 0 && archer[i] + dy >= 0 && archer[i] + dy < M
								&& map[wall - dx][archer[i] + dy] == 1) {
							flag = true;
							diedEnemy.add(new Pair(wall - (d + dy), archer[i] + dy));
							break;
						}
					}
					if (flag)
						break;
					for (int dy = 0; dy < d; dy++) {
						int dx = d - dy;
						if (wall - dx >= 0 && archer[i] + dy >= 0 && archer[i] + dy < M
								&& map[wall - dx][archer[i] + dy] == 1) {
							flag = true;
							diedEnemy.add(new Pair(wall - (d - dy), archer[i] + dy));
							break;
						}
					}
					if (flag)
						break;
				}
			} // end of for : archers

			for (int j = 0; j < diedEnemy.size(); j++) { // 적 죽이기
				if (map[diedEnemy.get(j).first][diedEnemy.get(j).second] == 1) {
					num++;
				}
				map[diedEnemy.get(j).first][diedEnemy.get(j).second] = 0; // 죽엇어
			}
			diedEnemy.clear(); //초기화
		}

		if (num > answer)
			answer = num; // 갱신
	}
	
	static int[][] copy(int[][] arr){
		int[][] ret = new int[N][M];
		for (int i = 0; i < N; i++) {
			ret[i] = Arrays.copyOf(arr[i], M);
		}
		return ret;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// input
		N = sc.nextInt();
		M = sc.nextInt();
		D = sc.nextInt();
		int[][] map = new int[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = sc.nextInt();
			}
		}

		// solve
		// 궁수는 셋, 궁수를 배치할 수 있는 방법의 수만큼 반복, 최댓값 갱신
		// 궁수를 배치할 수 있는 방법의 수 -> NC3 = N!/3!(N-3)!
		for (int i = 0; i < M - 2; i++) {
			for (int j = i + 1; j < M - 1; j++) {
				for (int k = j + 1; k < M; k++) {
					int[] arc = { i, j, k };
					kill(arc, copy(map));
				}
			}
		}

		// output
		System.out.println(answer);
	}
}

class Pair {
	int first, second;

	Pair(int a, int b) {
		first = a;
		second = b;
	}
}
