#include<iostream>
using namespace std;

int main(){
	int num;
	cin >> num;

	int count;
	if (num < 100){ //100���� ���� ���� ��� �Ѽ�
		count = num;
	}
	else {
		//num�� ���ڸ� �� �̹Ƿ� (1000�̸�), �� �ڸ��� ���� ���Ͽ� ������������ �˾Ƴ���.
		count = 99; //�ʱⰪ
		int a, b, c; //������� 100,10,1�� �ڸ���
		for (int i = 100; i <= num; i++){
			a = i / 100; b = i / 10 % 10; c = i % 10;
			if (a - b == b - c) //��������
				count++;
		}
	}

	cout << count;
}