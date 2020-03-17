/* 1266. [S/W 문제해결 응용] 9일차 - 소수 완제품 확률 D6
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18Sx36IwACFAZN&categoryId=AV18Sx36IwACFAZN&categoryType=CODE
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int[] primeNumber = { 2, 3, 5, 7, 11, 13, 17 }; // 만들 수 있는 완제품의 최대 개수 : 18 -> 이 이하인
	// 소수들의 목록
	static double skillOfMasterA, skillOfMasterB;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for (int testCase = 1; testCase <= T; testCase++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			skillOfMasterA = Double.parseDouble(st.nextToken()) / 100;
			skillOfMasterB = Double.parseDouble(st.nextToken()) / 100; // 5분 안에 완제품을 만들 확률
			// end of input

//			만들 기회 -> 각 18회
//			2개를 완제품으로 만들 확률 = skillOfMasterA^2 * (1-skillOfMasterA^16)
			double answer = 1 - calculatePercentage();
			// output
			sb.append('#').append(testCase).append(' ').append(String.format("%.6f", answer)).append('\n');
		}
		System.out.print(sb);
	}

	static double calculatePercentage() {
		double A = 0, B = 0;
		for (int i = 0; i < primeNumber.length; i++) {
			A += Math.pow(skillOfMasterA, primeNumber[i]) * Math.pow(1 - skillOfMasterA, 18 - primeNumber[i])
					* comb(18, primeNumber[i]);
			B += Math.pow(skillOfMasterB, primeNumber[i]) * Math.pow(1 - skillOfMasterB, 18 - primeNumber[i])
					* comb(18, primeNumber[i]);
		}
		return (1-A) * (1-B);
	}

	static int comb(int n, int r) { // nCr 구하기
		if (r > n)
			return 0;
		if (r == 0 || n == r)
			return 1;
		return comb(n - 1, r - 1) + comb(n - 1, r);
	}
}
