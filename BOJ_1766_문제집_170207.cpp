/* 1766. 문제집 Gold 2
https://www.acmicpc.net/problem/1766
*/
#include<iostream>
#include<queue>
#include<functional>
using namespace std;

typedef struct node{
	int data = 0;
	node *next = NULL;
};

node *prob[32001];
int numPre[32001];

int main(){
	int numProb, numInfo;
	scanf("%d %d", &numProb, &numInfo);

	for (; numInfo; --numInfo){
		int a, b;
		scanf("%d %d", &a, &b);
		node *tmp = new node;
		tmp->data = b;
		tmp->next = prob[a];
		prob[a] = tmp;
		++numPre[b];
	}

	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 1; i <= numProb; ++i){
		if (numPre[i]==0){
			q.push(i);
		}
	}

	while (!q.empty()){
		int x = q.top();
		q.pop();
		printf("%d ", x);
		for (node *p = prob[x]; p != NULL; p=p->next){
			int i = p->data;
			--numPre[i];
			if (numPre[i]==0){
				q.push(i);
			}
		}
	}
}
