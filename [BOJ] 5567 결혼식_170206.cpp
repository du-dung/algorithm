#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef struct node{
	int data = 0;
	node *next = NULL;
};

int main(){
	int numFriends, numList;
	scanf("%d %d", &numFriends, &numList);

	node *friends[501]; //동기들
	memset(friends, NULL, sizeof(nullptr)*(numFriends + 1));
	
	for (int i = 0; i < numList; ++i){ //리스트 값 입력
		int a, b;
		scanf("%d %d", &a, &b);
		
		node *tmp1 = new node;
		node *tmp2 = new node;
		tmp1->data = b;
		tmp2->data = a;

		tmp1->next = friends[a];
		friends[a] = tmp1;
		tmp2->next = friends[b];
		friends[b] = tmp2;
	}

	bool isDiscovered[501];
	memset(isDiscovered, false, numFriends + 1);
	isDiscovered[1] = true;

	queue<int> q; //친구
	for (node *tmp = friends[1]; tmp != NULL; tmp = tmp->next){
		q.push(tmp->data);
		isDiscovered[tmp->data] = true;
	}

	while (!q.empty()){
		for (node *tmp = friends[q.front()]; tmp != NULL; tmp = tmp->next){
			isDiscovered[tmp->data] = true;
		}
		q.pop();
	}

	int num = 0;
	for (int i = 2; i <= numFriends; ++i){
		if (isDiscovered[i])
			++num;
	}
	printf("%d", num);
}