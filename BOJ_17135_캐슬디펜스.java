import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/*
17135. ĳ�� ���潺
https://www.acmicpc.net/problem/17135
*/

public class BOJ_17135_ĳ�����潺 {
	static int N, M, D; // ���� �Ÿ� ����
	static int answer; // �ü��� �������� ������ �� �ִ� ���� �ִ� ��

	static void kill(int[] archer, int[][] map) { // �ü��� archer[0],[1],[2] ��ġ�� ���� �� ���� �� �ִ� ���� ���� ��ȯ
		int num = 0;
		ArrayList<Pair> diedEnemy = new ArrayList<>();
//	    vector<pair<int, int>> diedEnemy;
		for (int wall = map.length; wall > 0; wall--) { // wall�� �ü��� ��ġ�� ��. �� ����. ���� �� �྿ ������ ������ ��� ������ ���� �ø�
			for (int i = 0; i < 3; i++) { // c1 : archer[i]
				// ���� �� ã�� -> �Ÿ��� ���� ����� �� & ���� ����
				// dx (d-dy) : �� �Ÿ� (d ~ 1), dy : �� �Ÿ� (0 ~ d-1)
				boolean flag = false;
				for (int d = 1; d <= D; d++) { // �ּ� �Ÿ� 1 ~ �ִ� �Ÿ� D���� Ž��
					for (int dy = -d + 1; dy < 0; dy++) { // ���� ������ ������ -> ���� �ü����� ����, x�� ������ 1 �̻� ���̳��� ��
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

			for (int j = 0; j < diedEnemy.size(); j++) { // �� ���̱�
				if (map[diedEnemy.get(j).first][diedEnemy.get(j).second] == 1) {
					num++;
				}
				map[diedEnemy.get(j).first][diedEnemy.get(j).second] = 0; // �׾���
			}
			diedEnemy.clear(); //�ʱ�ȭ
		}

		if (num > answer)
			answer = num; // ����
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
		// �ü��� ��, �ü��� ��ġ�� �� �ִ� ����� ����ŭ �ݺ�, �ִ� ����
		// �ü��� ��ġ�� �� �ִ� ����� �� -> NC3 = N!/3!(N-3)!
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