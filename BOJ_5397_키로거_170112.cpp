/* 5397. 키로거 Silver 3
https://www.acmicpc.net/problem/5397
*/
#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int main(){
	int num;
	cin >> num;
	for (int i = 0; i < num; i++){
		stack<char> left;
		stack<char> right;
		char str[1000000];
		cin >> str;
		char tmp;
		int k = 0;
		int size = strlen(str);
		while(k<size){
			tmp = str[k];
			if (tmp == '<'){
				if (!left.empty()){
					tmp = left.top();
					left.pop();
					right.push(tmp);
				}	
			}
			else if (tmp == '>'){
				if (!right.empty()){
					tmp = right.top();
					right.pop();
					left.push(tmp);
				}
			}
			else if (tmp == '-'){
				if (!left.empty())
					left.pop();
			}
			else{
				left.push(tmp);
			}
			k++;
		}

		stack<char> print;
		while (!left.empty()){
			tmp = left.top();
			left.pop();
			print.push(tmp);
		}
		while (!print.empty()){
			cout << print.top();
			print.pop();
		}
		while (!right.empty()){
			cout << right.top();
			right.pop();
		}
		cout << endl;
	}
}
