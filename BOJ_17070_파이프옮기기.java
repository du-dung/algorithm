import java.util.Scanner;

/* 17070. ������ �ű�� 
	https://www.acmicpc.net/problem/17070
	*/
public class BOJ_17070_�������ű�� {
	enum Pipe {
		horizontal, vertical, diagonal
	};

	static int answer; // ����� ��
	static int N; // ���� ũ��
	static int[][] map = new int[18][18]; // ���� ����. �ε����� 1~N, N+1�� ������ ��

	static void dfs(Pipe p, int r, int c) {
		if (r == N && c == N) {
			answer++;
			return;
		}
		switch (p) { // �� ĭ���� üũ �� �̵�
		case horizontal: // ���� or �밢�� �̵�
			if (map[r][c + 1] == 0)
				dfs(Pipe.horizontal, r, c + 1);
			if (map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)
				dfs(Pipe.diagonal, r + 1, c + 1);
			break;
		case vertical: // ���� or �밢�� �̵�
			if (map[r + 1][c] == 0)
				dfs(Pipe.vertical, r + 1, c);
			if (map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)
				dfs(Pipe.diagonal, r + 1, c + 1);
			break;
		case diagonal: // ���� or ���� or �밢�� �̵�
			if (map[r][c + 1] == 0)
				dfs(Pipe.horizontal, r, c + 1);
			if (map[r + 1][c] == 0)
				dfs(Pipe.vertical, r + 1, c);
			if (map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)
				dfs(Pipe.diagonal, r + 1, c + 1);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// input
		N = sc.nextInt();
		for (int i = 1; i <= N; i++) { // �� ���� �Է�
			for (int j = 1; j <= N; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		sc.close();

		// �ٿ���� -> �����̶� �ϴ� ���� ������ ok
		for (int i = 1; i <= N; i++) {
			map[N + 1][i] = 1;
			map[i][N + 1] = 1;
		}
		map[N + 1][N + 1] = 1;

		// solve
		dfs(Pipe.horizontal, 1, 2); // �ʱ� ���� (1,2)

		// output
		System.out.println(answer);
	}
}
