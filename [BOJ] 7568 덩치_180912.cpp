/*
18.09.12
���۸��ع����� ����
*/

#include<iostream>
using namespace std;

int main(){
	int n;
	int data[2][51]; //height, weight ������ 2��, 2<=n<=50
	int rank[51];

	//������ �Է�
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> data[0][i] >> data[1][i];
	}

	//������ data�� ���� �ֱ�
	int count = 1; //�ʱ� ����:1
	for (int i = 0; i < n; i++){
		for (int k = 0; k < n; k++){
			if (data[0][i] < data[0][k] && data[1][i] < data[1][k]) //���� Ű&�����԰� �ٸ� �����ͺ��� ������
				count++;
		}
		rank[i] = count;
		count = 1; //�ʱ�ȭ
	}

	//���
	for (int i = 0; i < n; i++)
		cout << rank[i] << ' ';
}