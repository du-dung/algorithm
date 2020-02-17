import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/* 17406. 배열 돌리기 4 Gold V
https://www.acmicpc.net/problem/17406
- 가능한 회전 연산 실행 순서를 모두 실행하며 최솟값 갱신하기
	-> 연산 수행 순서에 따라 배열의 모양이 다르다 
*/

public class BOJ_17406_배열돌리기4 {

	static int N, M, K;
	static ArrayList<Tuple> turnOp = new ArrayList<>();
	static int answer = Integer.MAX_VALUE;

	static int[][] turn(Tuple t, int[][] arr) { // 회전시키기 -> 매개변수 arr 변화시키기
		int r = t.a, c = t.b, s = t.c;
		// 가장 왼쪽 윗 칸이 (r-s, c-s), 가장 오른쪽 아랫 칸이 (r+s, c+s)인 정사각형을 시계 방향으로 한 칸씩 돌린다
		// -> 반시계방향으로 진행하며 값을 가져온다
		for (int n = 0; n < s; n++) { // 바깥 쪽 사각형부터 회전 -> s는 사각형 개수
			int len = 2 * (s - n); // 정사각형의 한 변의 길이 -1
			int x = r - s + n, y = c - s + n; // 가장 왼쪽 윗 칸의 좌표
			int leftTop = arr[x][y]; // 가장 왼쪽 윗 칸의 값

			// 좌변
			for (int i = 0; i < len; i++, x++) {
				arr[x][y] = arr[x + 1][y];
			}
			// 밑변
			for (int i = 0; i < len; i++, y++) {
				arr[x][y] = arr[x][y + 1];
			}
			// 우변
			for (int i = 0; i < len; i++, x--) {
				arr[x][y] = arr[x - 1][y];
			}
			// 윗변
			for (int i = 0; i < len - 1; i++, y--) { // 마지막 한 칸은 저장해둔 값으로 지정
				arr[x][y] = arr[x][y - 1];
			}
			arr[x][y] = leftTop;
		}
		return arr;
	}

	static int getMinSum(int[][] arr) {
		int min = Integer.MAX_VALUE;
		for (int i = 1; i < arr.length; i++) {
			int s = 0;
			for (int j = 0; j < arr[0].length; j++) {
				s += arr[i][j];
			}
			if (s < min)
				min = s;
		}
		return min;
	}

	/** 2차원 배열 깊은 복사 */
	static int[][] copy(int[][] arr) {
		int[][] ret = new int[arr.length][arr[0].length];
		for (int i = 0; i < arr.length; i++) {
			ret[i] = Arrays.copyOf(arr[i], arr[0].length);
		}
		return ret;
	}

	static void dfs(int n, boolean[] turned, int[][] arr) {
		// n은 현재까지 수행한 연산의 개수, turned & arr - call by value
		if (n == K) { // 연산 수행 끝 -> 계산
			int tmp = getMinSum(arr);
			if (tmp < answer)
				answer = tmp;
			return;
		}
		for (int i = 0; i < K; i++) {
			if (!turned[i]) { // 아직 안돌았어
				turned[i] = true;
				dfs(n + 1, Arrays.copyOf(turned, K), turn(turnOp.get(i), copy(arr)));
				turned[i] = false;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// input
		N = sc.nextInt();
		M = sc.nextInt();
		K = sc.nextInt();
		int[][] arr = new int[N + 1][M + 1]; // index는 1~N * 1~M
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				arr[i][j] = sc.nextInt();
			}
		}

		for (int i = 0; i < K; i++) {
			turnOp.add(new Tuple(sc.nextInt(), sc.nextInt(), sc.nextInt()));
		}

		// solve
		// 가능한 연산 실행 순서의 모든 경우의 수 구하기 -> 순열 (재귀)
		boolean[] turned = new boolean[K];
		dfs(0, turned, arr);

		// output
		System.out.println(answer);
	}
}

class Tuple {
	int a, b, c;

	public Tuple(int a, int b, int c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}
}