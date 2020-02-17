/*
18.11.15 2251 물통
https://www.acmicpc.net/problem/2251
물을 붓는 경우는 a->b, a->c, b->a, b->c, c->a, c->b 여섯가지
모든 경우에 대해 탐색하고 a가 비었을 때 c의 용량 출력
*/

#include <iostream>
#include <queue>
using namespace std;

struct water {
	int a, b, c;
};
int main() {
	//input
	int A, B, C;
	cin >> A >> B >> C;

	//search
	bool check[201][201] = { {false,} };
	bool ans[201] = { false, };
	queue<water> q;
	q.push({ 0,0,C });

	while (!q.empty()) {
		water now = q.front();
		q.pop();

		if (check[now.a][now.b])
			continue;
		check[now.a][now.b] = true;

		if (now.a == 0)
			ans[now.c] = true;
		
		//a->b
		if (now.a + now.b > B)
			q.push({ now.a - (B - now.b), B, now.c });
		else //a+b<B
			q.push({ 0,now.a + now.b,now.c });


		//a->c
		if (now.a + now.c > C)
			q.push({ now.a - (C - now.c), now.b, C });
		else //a+c<C
			q.push({ 0,now.b,now.a + now.c });


		//b->a
		if (now.b + now.a > A)
			q.push({ A,(now.b + now.a) - A,now.c });
		else
			q.push({ now.b + now.a, 0, now.c });

		//b->c
		if (now.b + now.c > C)
			q.push({ now.a,(now.b + now.c) - C,C });
		else
			q.push({ now.a, 0, now.b + now.c });

		//c->a
		if (now.c + now.a > A)
			q.push({ A,now.b,(now.c + now.a) - A });
		else
			q.push({ now.c + now.a,now.b,0 });

		//c->b
		if (now.c + now.b > B)
			q.push({ now.a,B,(now.c + now.b) - B });
		else
			q.push({ now.a,now.c + now.b,0 });
	
	}

	//print
	for (int i = 0; i <= C; i++) {
		if (ans[i])
			cout << i << " ";
	}
}