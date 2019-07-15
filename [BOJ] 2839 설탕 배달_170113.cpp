//https://www.acmicpc.net/problem/2839

#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a, b, c = 0, d = 0;
	a = n / 5; b = 0;
	for (; a >= 0; a--){
		while (1){
			if (n == (a * 5 + b * 3)){
				c = a; d = b; break;
			}
			else{
				if (n>(a * 5 + b * 3)){
					b++;
				}
				else{
					break;
				}
			}
		}
		if (c != 0 || d != 0)
			break;
	}
	if (!(c==0&&d==0))
		cout << c + d;
	else
		cout << -1;
}