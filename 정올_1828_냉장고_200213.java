/* 1828. 냉장고 Intermediate
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1101&sca=99&sfl=wr_hit&stx=1828
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static class Frige {
		int low, high;

		public Frige(int low, int high) {
			this.low = low;
			this.high = high;
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int[][] temp = new int[N][3];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			temp[i][0] = Integer.parseInt(st.nextToken());
			temp[i][1] = Integer.parseInt(st.nextToken());
			temp[i][2] = temp[i][1] - temp[i][0]; // 온도 범위
		} // end of input

		boolean[] checked = new boolean[N]; // 냉장고에 넣은 시약
		int frigeNum = 0; // 냉장고 대수
		int n = 0; // 냉장고에 넣은 시약 개수
		while (n < N) {
			// 가장 온도 범위가 좁은 시약의 온도로 설정
			int low = 0, high = 0, size = 10271, index = -1;
			for (int i = 0; i < checked.length; i++) {
				if (!checked[i] && temp[i][2] < size) {
					index = i;
					low = temp[i][0];
					high = temp[i][1];
					size = temp[i][2];
				}
			}
			checked[index] = true;
			frigeNum++;
			n++;

			// 해당 온도 범위 내에 들어가는 시약들 찾기
			for (int i = 0; i < temp.length; i++) {
				if(checked[i])	continue; //이미 넣음
				if (high < temp[i][0] || low > temp[i][1]) { //안들어감
					continue;
				}
				if(low < temp[i][0])	low = temp[i][0];
				if(high > temp[i][1])	high = temp[i][1];
				checked[i] = true;
				n++;
			}
		}
		System.out.println(frigeNum);
	}
}
