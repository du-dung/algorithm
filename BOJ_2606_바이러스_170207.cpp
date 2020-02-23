/* 2606. 바이러스 Silver 2
 https://www.acmicpc.net/problem/2606
 
 */
#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;

int main(){
	int numComp, numConn;
	scanf("%d %d", &numComp, &numConn);

	int comp[101][101];
	memset(comp, 0, sizeof(int)* 101 * 101);

	for (; numConn; --numConn){
		int a, b;
		scanf("%d %d", &a, &b);
		comp[a][b] = 1;
		comp[b][a] = 1;
	}

	bool isInfected[101];
	memset(isInfected, false, 101);
	isInfected[1] = true;
	queue<int> q;
	for (int i = 2; i <= numComp; ++i){
		if (comp[1][i]){
			q.push(i);
			isInfected[i] = true;
		}
	}
	while (!q.empty()){
		int i = q.front();
		for (int j = 1; j <= numComp; ++j){
			if (comp[i][j]){
				if (!isInfected[j]){
					isInfected[j] = true;
					q.push(j);
				}
			}
		}
		q.pop();
	}

	int infectedComp = 0;
	for (int i = 2; i <= numComp; ++i){
		if (isInfected[i])
			++infectedComp;
	}
	printf("%d", infectedComp);
}
