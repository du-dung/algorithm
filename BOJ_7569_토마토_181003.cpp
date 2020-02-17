/*
https://www.acmicpc.net/problem/7569
*문제
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자모양 상자의 칸에 하나씩 넣은 다음, 상자들을 수직으로 쌓아 올려서 창고에 보관한다.
창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 

보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 
하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토를 의미한다. 
대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 

철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 알고 싶어 한다.
토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

*입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N과 쌓아올려지는 상자의 수를 나타내는 H 가 주어진다. 
M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 이다. 

둘째 줄부터는 가장 밑의 상자부터 가장 위의 상자까지에 저장된 토마토들의 정보가 주어진다. 
즉, 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다. 

각 줄에는 상자 가로줄에 들어있는 토마토들의 상태가 M개의 정수로 주어진다. 
정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 
이러한 N개의 줄이 H 번 반복하여 주어진다.

*출력
여러분은 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해서 출력해야 한다. 
만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1 을 출력해야 한다.
*/

/*
v01. 18.10.03

*/

#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int box[100][100][100]; //box[m][n][h]

int main() {
	int m, n, h;
	
	queue < tuple<int, int, int> > ripen_tomato;
	
	//input
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				cin >> box[i][j][k]; //h층의 가로m, 세로n 위치
				if (box[i][j][k] == 1)
					ripen_tomato.push(make_tuple(i, j, k)); //익은 토마토는 queue에 추가
			}
		}
	}

	//calculate days
	int ans=-1; //모든 토마토가 익는 데 걸리는 날, 
	tuple<int, int, int>  dir[]
		= { make_tuple(0, 0, -1), make_tuple(0, 0, 1), make_tuple(-1, 0, 0), make_tuple(1, 0, 0), make_tuple(0, -1, 0), make_tuple(0, 1, 0) }; //dirrection

	while (!ripen_tomato.empty()) {
		ans++; //0번째 날부터 시작
		int size_q = ripen_tomato.size();
		for (; size_q != 0; size_q--) {
			int x = get<0>(ripen_tomato.front()), y = get<1>(ripen_tomato.front()), z = get<2>(ripen_tomato.front());
			ripen_tomato.pop();

			for (int i = 0; i < 6; i++) { //6방향 탐색
				int nx = x + get<0>(dir[i]), ny = y + get<1>(dir[i]), nz = z + get<2>(dir[i]);
				if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h) //상자 범위를 벗어났을 경우
					continue;
				if (box[nx][ny][nz] != 0) //토마토가 익었거나 없을 경우
					continue;

				box[nx][ny][nz] = 1; //토마토 익음
				ripen_tomato.push(make_tuple(nx, ny, nz)); //익은 토마토에 추가
			}
		}
	}
	
	//check all tomato ripe
	for (int k = 0; k < h; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				if (box[i][j][k] == 0) { //익지 않은 토마토를 발견했을 경우
					cout << -1; return 0; //-1 출력, 프로그램 종료
				}
			}
		}
	}

	cout << ans; //익지 않은 토마토가 없을 경우 걸린 날 출력
	
}