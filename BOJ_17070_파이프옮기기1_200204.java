import java.util.Scanner;

/* 17070. 파이프 옮기기 
	https://www.acmicpc.net/problem/17070
	*/
public class BOJ_17070_파이프옮기기 {
	enum Pipe {
		horizontal, vertical, diagonal
	};

	static int answer; // 방법의 수
	static int N; // 집의 크기
	static int[][] map = new int[18][18]; // 집의 상태. 인덱스는 1~N, N+1번 라인은 벽

	static void dfs(Pipe p, int r, int c) {
		if (r == N && c == N) {
			answer++;
			return;
		}
		switch (p) { // 빈 칸인지 체크 후 이동
		case horizontal: // 가로 or 대각선 이동
			if (map[r][c + 1] == 0)
				dfs(Pipe.horizontal, r, c + 1);
			if (map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)
				dfs(Pipe.diagonal, r + 1, c + 1);
			break;
		case vertical: // 세로 or 대각선 이동
			if (map[r + 1][c] == 0)
				dfs(Pipe.vertical, r + 1, c);
			if (map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)
				dfs(Pipe.diagonal, r + 1, c + 1);
			break;
		case diagonal: // 가로 or 세로 or 대각선 이동
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
		for (int i = 1; i <= N; i++) { // 집 상태 입력
			for (int j = 1; j <= N; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		sc.close();

		// 바운더리 -> 우측이랑 하단 벽만 있으면 ok
		for (int i = 1; i <= N; i++) {
			map[N + 1][i] = 1;
			map[i][N + 1] = 1;
		}
		map[N + 1][N + 1] = 1;

		// solve
		dfs(Pipe.horizontal, 1, 2); // 초기 상태 (1,2)

		// output
		System.out.println(answer);
	}
}
