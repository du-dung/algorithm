/*
18.09.12
구글링해벌엿다 으악
*/

#include<iostream>
using namespace std;

int main(){
	int n;
	int data[2][51]; //height, weight 데이터 2개, 2<=n<=50
	int rank[51];

	//데이터 입력
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> data[0][i] >> data[1][i];
	}

	//각각의 data에 순위 주기
	int count = 1; //초기 순위:1
	for (int i = 0; i < n; i++){
		for (int k = 0; k < n; k++){
			if (data[0][i] < data[0][k] && data[1][i] < data[1][k]) //나의 키&몸무게가 다른 데이터보다 작을때
				count++;
		}
		rank[i] = count;
		count = 1; //초기화
	}

	//출력
	for (int i = 0; i < n; i++)
		cout << rank[i] << ' ';
}