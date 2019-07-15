//https://www.acmicpc.net/problem/1158

#include<iostream>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int circle[5000] = { 0, };
	int i = 0;
	int tmp;
	while (i < n){
		circle[i] = i + 1; i++;
	}
	i = 0;
	int pos = 1, del = 0;
	cout << "<";
	while (del < n){
		while (pos < m){
			pos++;
			if (i + 1 == n - del)
				i = 0;
			else
				i++;
		}
		cout << circle[i];
		tmp = i;
		while (i < n - del -1){
			circle[i] = circle[i + 1];
			i++;
		}
		del++;
		if (del != n)
			cout << ", ";
		if (tmp >= n - del)
			i = 0;
		else
			i = tmp;	
		pos = 1;
	}
	cout << ">";
}