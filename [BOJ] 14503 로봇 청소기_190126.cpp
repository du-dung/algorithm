/*
�κ� û�ұ� https://www.acmicpc.net/problem/14503
19.01.22~01.26 01:14
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> > dir = { {-1,0}, {0,1}, {1,0}, {0,-1} }; //����(0�� 1�� 2�� 3��)
//d=d+1%4; //�����������ΰ���

//vector< pair<int, int> > dir = { {0,-1}, {1,0}, {0,1}, {-1,0} };//�ϵ�����
void cleaner(bool &end, int ans, vector< vector<int> >room, vector< vector<bool> > cleaned, int r, int c, int d);

int main() {
	int N, M; //����, ����
	int r, c, d; //(r, c) : �κ�û�ұ��� ��ġ, d: �κ�û�ұⰡ �ٶ󺸴� ����(0�� 1�� 2�� 3��)

	cin >> N >> M;
	cin >> r >> c >> d;

	vector< vector<int> > room(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
		}
	}

	int ans = 0; //û���� ������ ��
	bool end = false;
	vector< vector<bool> > cleaned(N, vector<bool>(M, 0)); //û�ҵǾ����� true, �ƴϸ� false

	cleaner(end, ans, room, cleaned, r, c, d);
}

void cleaner(bool &end, int ans, vector< vector<int> >room, vector< vector<bool> > cleaned, int r, int c, int d) {
//	if (end)
//		return;
//	cout << "(" << r << ", " << c << "), d: " << d << endl;
	

	int nr, nc, nd=d; //next r,n,c
//	bool flag = false;

	if (!cleaned[r][c]) {
		cleaned[r][c] = true; ans++;//û���ϱ�
	}

	for (int i = 0; i < 4; i++) { //���ʺ��� üũ
		nd = (nd + 3) % 4;
		nr = r + dir[nd].first;
		nc = c + dir[nd].second;
		if (!(room[nr][nc] || cleaned[nr][nc])) { //û�Ҹ� ��������&���� �ƴϸ� (û�� ����)
			cleaner(end, ans, room, cleaned, nr, nc, nd); //���� ��������
			//flag = true;
			//break;
		}
	}

	//if (!flag) {
		//����� �� û�Ұ� �Ǿ��ְų� ���� ��� -> �Ĺ� üũ
		nd = (d + 2) % 4;
		nr = r + dir[nd].first;
		nc = c + dir[nd].second;

		if (room[nr][nc]) { //�Ĺ��� ���� ���
			cout << ans;
			exit(0);
			//end = true;
			//return;
		}
		else { //�Ĺ��� ���� �ƴ� ���
			cleaner(end, ans, room, cleaned, nr, nc, d); //������� ������ ä ����
		}
	//}
}

//int canIclean(vector< vector<int> >room, vector< vector<bool> > cleaned, int &r, int &c, int d) {
//	/*
//	�� ������ ��� û�ҵǾ� �ְų� ���� ��� 4
//
//	û�� ������ ���� ���� (0,1,2,3)-> ���� ���� �������� ���ʺ��� Ž��
//	*/
//	//bool front = (cleaned[r + dir[d].first][c + dir[d].second] || room[r + dir[d].first][c + dir[d].second]); d = (d + 1) % 4;
//	//bool right = (cleaned[r + dir[d].first][c + dir[d].second] || room[r + dir[d].first][c + dir[d].second]); d = (d + 1) % 4;
//	//bool back = (cleaned[r + dir[d].first][c + dir[d].second] || room[r + dir[d].first][c + dir[d].second]); d = (d + 1) % 4;
//	//bool left = (cleaned[r + dir[d].first][c + dir[d].second] || room[r + dir[d].first][c + dir[d].second]); d = (d + 1) % 4; //ó�� d�� ���ƿ�
//
//	//if (!left)
//	//	return (d + 3) % 4;
//	//if (!back)
//	//	return (d + 2) % 4;
//	//if (!right)
//	//	return (d + 1) % 4;
//	//if (!front)
//	//	return d;
//
//	int cur = (d + 3) % 4; //�������, ���ʺ��� ����
//	for(int i=4; i; --i){
//		if (!(cleaned[c + dir[cur].first][r + dir[cur].second] || room[c + dir[cur].first][r + dir[cur].second])) {
//			//û�ҵ� ���߰� ���� �ƴҶ�
//			return cur;
//		}
//	cur = (cur + 3) % 4;
//	}
//	
//	return 4;
//}
//
//void cleaner(int ans, vector< vector<int> >room, vector< vector<bool> > cleaned, int &r, int &c, int d) {
//
//	while (true) {
//		if (!cleaned[c][r]) { cleaned[c][r] = true; ans++; } //û��
//		cout << "(" << r << ", " << c << "), d: " << d << endl;
//
//		int go = canIclean(room, cleaned, r, c, d);
//
//		if (go == 4) { //û���� ���� ����
//			 //1. �� �ڰ� ����
//			int back = (d + 2) % 4;
//			if (room[c + dir[back].first][r + dir[back].second]) {
//				break;
//			}
//
//			//2. �ڷ� ��ĭ �̵� (���� ����)
//			c += dir[back].first; r += dir[back].second;
//		}
//		else { //û�� ����
//			d = go; //���� ��ȯ
//			c += dir[d].first; r += dir[d].second; //�ش� �������� �� ĭ �̵�
//		}
//	}
//
//	cout << ans;
//}