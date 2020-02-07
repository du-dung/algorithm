import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/* 17406. �迭 ������ 4 Gold V
https://www.acmicpc.net/problem/17406
- ������ ȸ�� ���� ���� ������ ��� �����ϸ� �ּڰ� �����ϱ�
	-> ���� ���� ������ ���� �迭�� ����� �ٸ��� 
*/

public class BOJ_17406_�迭������4 {

	static int N, M, K;
	static ArrayList<Tuple> turnOp = new ArrayList<>();
	static int answer = Integer.MAX_VALUE;

	static int[][] turn(Tuple t, int[][] arr) { // ȸ����Ű�� -> �Ű����� arr ��ȭ��Ű��
		int r = t.a, c = t.b, s = t.c;
		// ���� ���� �� ĭ�� (r-s, c-s), ���� ������ �Ʒ� ĭ�� (r+s, c+s)�� ���簢���� �ð� �������� �� ĭ�� ������
		// -> �ݽð�������� �����ϸ� ���� �����´�
		for (int n = 0; n < s; n++) { // �ٱ� �� �簢������ ȸ�� -> s�� �簢�� ����
			int len = 2 * (s - n); // ���簢���� �� ���� ���� -1
			int x = r - s + n, y = c - s + n; // ���� ���� �� ĭ�� ��ǥ
			int leftTop = arr[x][y]; // ���� ���� �� ĭ�� ��

			// �º�
			for (int i = 0; i < len; i++, x++) {
				arr[x][y] = arr[x + 1][y];
			}
			// �غ�
			for (int i = 0; i < len; i++, y++) {
				arr[x][y] = arr[x][y + 1];
			}
			// �캯
			for (int i = 0; i < len; i++, x--) {
				arr[x][y] = arr[x - 1][y];
			}
			// ����
			for (int i = 0; i < len - 1; i++, y--) { // ������ �� ĭ�� �����ص� ������ ����
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

	/** 2���� �迭 ���� ���� */
	static int[][] copy(int[][] arr) {
		int[][] ret = new int[arr.length][arr[0].length];
		for (int i = 0; i < arr.length; i++) {
			ret[i] = Arrays.copyOf(arr[i], arr[0].length);
		}
		return ret;
	}

	static void dfs(int n, boolean[] turned, int[][] arr) {
		// n�� ������� ������ ������ ����, turned & arr - call by value
		if (n == K) { // ���� ���� �� -> ���
			int tmp = getMinSum(arr);
			if (tmp < answer)
				answer = tmp;
			return;
		}
		for (int i = 0; i < K; i++) {
			if (!turned[i]) { // ���� �ȵ��Ҿ�
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
		int[][] arr = new int[N + 1][M + 1]; // index�� 1~N * 1~M
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				arr[i][j] = sc.nextInt();
			}
		}

		for (int i = 0; i < K; i++) {
			turnOp.add(new Tuple(sc.nextInt(), sc.nextInt(), sc.nextInt()));
		}

		// solve
		// ������ ���� ���� ������ ��� ����� �� ���ϱ� -> ���� (���)
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