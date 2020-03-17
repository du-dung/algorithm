/* 1244. [S/W 문제해결 응용] 2일차 - 최대 상금 D3
 https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD&categoryId=AV15Khn6AN0CFAYD&categoryType=CODE
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int answer;
	static int n;
	static char[] nums;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());
		for (int testCase = 1; testCase <= T; testCase++) {
			// input
			st = new StringTokenizer(br.readLine());
			String s = st.nextToken(); // 숫자판의 정보
			n = Integer.parseInt(st.nextToken()); // 최대 교환 횟수

			nums = s.toCharArray();
			answer = 0;
			change(0, 0);

			// output
			System.out.println("#" + testCase + " " + answer);
		}
	}

	public static void change(int k, int r) { // r은 교환 횟수
		if (r == n) {
			int c = calculate();
			if (answer < c) {
				answer = c;
			}
			return;
		}
		for (int i = k; i < nums.length; i++) {
			for (int j = i + 1; j < nums.length; j++) {
				if (nums[i] <= nums[j]) {
					swap(i, j);
					change(i, r + 1);
					swap(i, j);
				}
			}
		}
	}

	public static void swap(int k, int i) {
		char tmp = nums[k];
		nums[k] = nums[i];
		nums[i] = tmp;
	}

	static int calculate() { // nums의 상금 계산
		int num = 0;
		for (int i = 0; i < nums.length; i++) {
			num *= 10;
			num += nums[i] - '0';
		}
		return num;
	}
}
