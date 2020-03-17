/* 1863. 종교 Advanced
 http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1136&sca=40
 */
import java.util.Scanner;

public class Main {
	static int[] tree; // 0번 인덱스는 사용하지 x
	static int[] rank;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt(), m = sc.nextInt();

		tree = new int[n + 1];
		rank = new int[n + 1];

		for (int i = 1; i <= n ; i++) {
			tree[i] = i; //자기 자신을 부모로 (makeSet(i)
		}
		
		int numOfSet = n;
		for (int k = 0; k < m; k++) {
			int i = sc.nextInt(), j = sc.nextInt();
			if(union(i, j))	numOfSet--;
		}
		System.out.println(numOfSet);
		sc.close();
	}

	static int findSet(int x) {
		if (tree[x] == x) {
			return x;
		} else
			return findSet(tree[x]);
	}

	/** 일반 멤버 x, 일반 멤버 y를 포함하는 두 집합을 통합 */
	static boolean union(int x, int y) {
		int px = findSet(x), py = findSet(y); // 대표자 찾아오기

		if (px != py) { // 다른 집합일 때만 합치기
			link(px, py); // 랭크가 깊어지지 않도록 합치기
			return true;
		}
		return false;
	}

	/**
	 * x의 대표자 집합과 y의 대표자 집합의 rank값을 기준으로 합친다 rank값이 작은 집합을 큰 집합에 편입시킨다.
	 */
	static void link(int px, int py) {
		if (rank[px] > rank[py]) {
			tree[py] = px; // 작은 쪽을 큰 쪽에 붙인다
		} else {
			tree[px] = py;
			if (rank[px] == rank[py]) {
				rank[py]++;
			}
		}
	}
}
