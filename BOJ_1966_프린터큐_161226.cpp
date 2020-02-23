/* 1966. 프린터 큐 Silver 3
 https://www.acmicpc.net/problem/1966
*/
#include<iostream>
#include<utility>
#include<queue>
using namespace std;

int main(){
	int test_case;
	int n, m;
	int count; 
	int x;
	pair<int, int> data, tmp;
	queue< pair<int, int> > q, q_cmp;
	cin >> test_case;
	for(; test_case>0; --test_case){
		cin >> n >> m;
		count=0;
		for(int i=0; i<n; ++i){ 
			cin >> x;
			data = make_pair(x, i);
			q.push(data);
			q_cmp.push(data);
		}

		while(!q.empty()){ 
			data = q.front();
			q.pop();
			for(int i=0; i<n; i++){
				tmp=q_cmp.front();
				q_cmp.pop();
				q_cmp.push(tmp);
				if(data.first<tmp.first){
					q.push(data);
					break;
				}
			}
			if(n!=q.size()){
				++count;
				if(data.second==m){
					cout << count << endl;
					break;
				}
				for(int i=0; i<n; i++){
					tmp=q_cmp.front();
					q_cmp.pop();
					if(tmp.second!=data.second)
						q_cmp.push(tmp);
				}
				--n;
			}
		}
		while(!q.empty()) 
			q.pop();
		while(!q_cmp.empty())
			q_cmp.pop();
	}
}
