//https://www.acmicpc.net/problem/9935

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
	stack<char> st;
	string input;
	string bomb;
	cin >> input >> bomb;
	int bomb_offset = bomb.size() - 1;
	for (int i = 0; i < (int)input.size(); i++){
		if (input[i] == bomb[bomb_offset]){
			int k;
			for (k = bomb_offset-1; k >= 0; k--){
				if (!st.empty()){
					if (bomb[k] == st.top())
						st.pop();
					else{
						for (k++; k < (int)bomb.size(); k++)
							st.push(bomb[k]);
						break;
					}
				}
				else{
					for (k++; k < (int)bomb.size(); k++)
						st.push(bomb[k]);
					break;
				}
			}
		}
		else{
			st.push(input[i]);
		}
	}
	if (st.empty()){
		cout << "FRULA";
		return 0;
	}
	stack<char> print;
	while (!st.empty()){
		print.push(st.top());
		st.pop();
	}
	while (!print.empty()){
		cout << print.top();
		print.pop();
	}
}