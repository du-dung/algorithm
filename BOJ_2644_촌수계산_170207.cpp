#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;

int main(){
	int numP, input1, input2, numRe;
	scanf("%d %d %d %d", &numP, &input1, &input2, &numRe);
	
	bool relation[101][101];
	memset(relation, false, 101 * 101);
	for (; numRe; --numRe){
		int a, b;
		scanf("%d %d", &a, &b);
		relation[a][b] = true;
		relation[b][a] = true;
	}

	bool isSearched[101];
	memset(isSearched, false, 101);
	isSearched[input1] = true;
	queue<pair<int,int>> q;
	for (int j = 1; j <= numP; ++j){
		if (relation[input1][j]){
			pair<int, int> p(j, 1);
			q.push(p);
			isSearched[j] = true;
		}
	}
	while (!q.empty()){
		int i = q.front().first;
		if (i == input2){
			printf("%d", q.front().second);
			return 0;
		}
		for (int j = 1; j <= numP; ++j){
			if (relation[i][j]){
				if (!isSearched[j]){
					pair<int, int> p(j, q.front().second + 1);
					q.push(p);
					isSearched[j] = true;
				}
			}
		}
		q.pop();
	}
	printf("-1");
}