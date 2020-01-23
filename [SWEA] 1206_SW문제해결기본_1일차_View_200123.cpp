#include <iostream>
#include <algorithm>
using namespace std;

#define max4(a, b, c, d){ max(a,b) > max(c,d) ? max(a,b) : max(c,d) }

int main() {
	int N, map[1000]; //���� ���̴� �׻� 1000 ����
	int answer;
	for (int testCase = 1; testCase <= 10; testCase++) {
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> map[i];
		}//end of input

		//solve
		answer = 0;
		int around;
		for (int i = 2; i < N-2; i++) {
			around = max4(map[i - 2], map[i - 1], map[i + 1], map[i + 2]); //�¿� 4ĭ �� ���� ���� ������ ����
			if(map[i]>around){ //������ Ȯ��
				answer += map[i] - around;
				i += 2; //���� �� ĭ�� ������ Ȯ�� �Ұ�
			}
		}

		//answer
		cout << "#" << testCase << " " << answer << '\n';
	}
} //end of main