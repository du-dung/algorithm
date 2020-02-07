import java.util.Scanner;

/* 16637. ��ȣ �߰��ϱ�
https://www.acmicpc.net/problem/16637
 - �� �����ڴ� ��ȣ�� �ϴ� ���� ���� �ʴ� ���, 2���� ����� �� ����
 - �պ��� ���� ���� �ʿ� -> ���� �����ڿ� ��ȣ�� ���� ��츦 ����ؾ�
	-> �����ڴ� �ִ� 8�� : 2^8 ȸ ����
*/
public class BOJ_16637_��ȣ�߰��ϱ� {
	static int answer = Integer.MIN_VALUE;
	static String str;

	static int cal(int a, char op, int b) {
		switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		}
		return -1;
	}

	static void dfs(int res, int index) { // res: ���� ��, index: ���� ������
		if (index + 2 >= str.length()) { // ���� ������ ���� -> ��� ��
			int r = cal(res, str.charAt(index), str.charAt(index + 1) - '0');
			if (r > answer)
				answer = r; // ��� ������Ʈ
			return; // �� ���� ���� �� index out of range ����
		} else
			dfs(cal(res, str.charAt(index), str.charAt(index + 1) - '0'), index + 2); // ��ȣ x
		if (index + 4 >= str.length()) { // �ٴ��� ������ ���� -> ��� ��
			int r = cal(res, str.charAt(index),
					cal(str.charAt(index + 1) - '0', str.charAt(index + 2), str.charAt(index + 3) - '0')); // ���� �����ڿ� ��ȣ o
			if (r > answer)
				answer = r; // ��� ������Ʈ
		} else
			dfs(cal(res, str.charAt(index),
					cal(str.charAt(index + 1) - '0', str.charAt(index + 2), str.charAt(index + 3) - '0')), index + 4); // ���� �����ڿ� ��ȣ o
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//input
		int N = sc.nextInt();
		str = sc.next();

		//solve
		if (str.length() == 1) { //���� ó��
			System.out.println(str.charAt(0) - '0');
			return;
		}
		dfs(str.charAt(0) - '0', 1);

		//output
		System.out.println(answer);;
	}

}
