/*
https://www.acmicpc.net/problem/5427
����̴� �� ������ ������ �̷���� �ǹ��� �����ִ�. �ǹ��� �Ϻο��� ���� ����, ����̴� �ⱸ�� ���� �ٰ� �ִ�.
�� �ʸ���, ���� �������� �������� ������ �� �������� ����������. ������ ���� ���� �ʴ´�. ����̴� �������� ������ ĭ���� �̵��� �� ������, 1�ʰ� �ɸ���.
����̴� ���� ����� �� ����, ���� �Ű��� ĭ �Ǵ� ���� ���� �������� ĭ���� �̵��� �� ����. ����̰� �ִ� ĭ�� ���� �ŰܿȰ� ���ÿ� �ٸ� ĭ���� �̵��� �� �ִ�.
������ ������ �־����� ��, �󸶳� ���� ������ Ż���� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �׽�Ʈ ���̽��� �ִ� 100���̴�.
�� �׽�Ʈ ���̽��� ù° �ٿ��� ���� ������ �ʺ�� ���� w�� h�� �־�����. (1 �� w,h �� 1000)
���� h�� �ٿ��� w���� ����, ������ ������ �־�����.
'.': �� ����
'#': ��
'@': ������� ���� ��ġ
'*': ��
�� ������ @�� ������ �ϳ��̴�.

���
�� �׽�Ʈ ���̽����� ������ Ż���ϴµ� ���� ���� �ð��� ����Ѵ�. ������ Ż���� �� ���� ��쿡�� "IMPOSSIBLE"�� ����Ѵ�.
*/

/*
v01. 18.09.29~18.09.30
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
using namespace std;

int escape(int w, int h, vector < vector<int> > fire_run, vector< vector<int> > sangun_run, queue< pair<int, int> > fire, queue< pair<int, int> > sangun) {
	/* 
	w: width	, h: height
	fire_run: ���� Ȯ��Ǵ� �� �ɸ��� �ð��� �����ϴ� 2���� �迭
	sangun_run: ����̰� ����ġ�� �� �ɸ��� �ð��� �����ϴ� 2���� �迭
	fire: BPS�� �ʿ��� queue, ���� ��ġ�� pair�� ��
	sangun: BPS�� �ʿ��� queue, ������� ��ġ�� pair�� ��
	*/

	pair<int, int> dir[4]; //�����¿�
	dir[0] = make_pair(0, -1);
	dir[1] = make_pair(1, 0);
	dir[2] = make_pair(-1, 0);
	dir[3] = make_pair(0, 1);

	//���� Ȯ��Ǵ� �� �ɸ��� �ð� ���ϱ�
	int time_fire = 0;
	while (!fire.empty()) {
		int size_f = fire.size();
		time_fire++; //depth
		for (int k = 0; k < size_f; k++) {
			int x = fire.front().first, y = fire.front().second;
			fire.pop();

			for (int i = 0; i < 4; i++) {//�� ���� Ž��
				int nx = x + dir[i].first, ny = y + dir[i].second;
				if (nx < 0 || ny < 0 || nx == h || ny == w) //�迭 ������ ����� ���
					continue;
				if (fire_run[nx][ny] == -1) //���� ���
					continue;
				if (fire_run[nx][ny] <= time_fire) //�̹� Ž���� ĭ�� ���
					continue;
				fire_run[nx][ny] = time_fire;
				fire.push(make_pair(nx, ny));
			}
		}
	}

	//����� ������� ����
	queue<pair<int, int> > next_run;
	next_run.push(make_pair(sangun.front().first, sangun.front().second)); 

	//����̰� ����ġ�� �� �ɸ��� �ð� ���ϱ�
	int time_sangun = 0;
	while (!sangun.empty()) {
		int size_s = sangun.size();
		time_sangun++; //depth
		for (int k = 0; k < size_s; k++) {
			int x = sangun.front().first, y = sangun.front().second;
			sangun.pop();

			for (int i = 0; i < 4; i++) {//�� ���� Ž��
				int nx = x + dir[i].first, ny = y + dir[i].second;
				if (nx < 0 || ny < 0 || nx == h || ny == w) //�迭 ������ ����� ���
					continue;
				if (sangun_run[nx][ny] == -1) //���� ���
					continue;
				if (sangun_run[nx][ny] <= time_sangun) //�̹� Ž���� ĭ�� ���
					continue;
				sangun_run[nx][ny] = time_sangun;
				sangun.push(make_pair(nx, ny));
			}
		}
	}

	//�� �迭 ��
	vector< vector<bool> > searched(h, vector<bool>(w, false)); //Ž�� ����

	while (!next_run.empty()) {
		int x = next_run.front().first, y = next_run.front().second; next_run.pop();

		for (int i = 0; i < 4; i++) {//�� ���� Ž��
			int nx = x + dir[i].first, ny = y + dir[i].second;
			if (nx < 0 || ny < 0 || nx == h || ny == w) //�迭 ������ ����� ���
				return sangun_run[x][y] + 1; //Ż��!
			if (searched[nx][ny] == true) //�̹� Ž������ ���
				continue;
			if (sangun_run[nx][ny] == -1) //���� ���
				continue;
			if (fire_run[nx][ny] <= sangun_run[nx][ny]) //����̺��� ���� ������ �����ų�, ���ÿ� ������ ���
				continue;
			next_run.push(make_pair(nx, ny));
			searched[nx][ny] = true;
		}
	}

	return -1; //���������� ������ ���
}
	
int main() {
	int tnum; //number of test case
	int width, height; //�ʺ�� ����
	vector< vector<int> > map_fire;
	vector< vector<int> > map_sangun;
	queue< pair<int, int> > sangun_start;
	queue< pair<int, int> > fire_start;
	queue<int> ans;

	cin >> tnum;
	while (tnum != 0) {
		tnum--;

		//input
		cin >> width >> height;
		for (int i = 0; i < height; i++) {
			string input;
			cin >> input;

			vector<int> tmp_fire;
			vector<int> tmp_sangun;
			for (int j = 0; j < width; j++) {
				switch (input[j]) {
				case '#': //wall, �̵� �Ұ�
					tmp_fire.push_back(-1);
					tmp_sangun.push_back(-1);
					break;
				case '@': //����� ������ġ
					tmp_fire.push_back(INT_MAX); //�ִ�
					tmp_sangun.push_back(0); //��������
					sangun_start.push(make_pair(i, j));
					break;
				case '*': //�� ���� ��ġ
					tmp_fire.push_back(0);
					tmp_sangun.push_back(INT_MAX); //�ִ�
					fire_start.push(make_pair(i, j));
					break;
				default: //input == '.'
					tmp_fire.push_back(INT_MAX);
					tmp_sangun.push_back(INT_MAX);
				}
			}
			map_fire.push_back(tmp_fire);
			map_sangun.push_back(tmp_sangun);
		}

		/*
		//input test
		cout << "map_fire" << endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cout << map_fire[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "fire_start" << endl;
		while (!fire_start.empty()) {
			cout << fire_start.front().first << ',' << fire_start.front().second << endl;
			fire_start.pop();
		}

		cout << "map_sangun" << endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cout << map_sangun[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "sangun_start" << endl;
		while (!sangun_start.empty()) {
			cout << sangun_start.front().first << ',' << sangun_start.front().second << endl;
			sangun_start.pop();
		}
		*/
		//search	
		ans.push(escape(width, height, map_fire, map_sangun, fire_start, sangun_start));
	
		//�ʱ�ȭ
		vector< vector<int> >().swap(map_fire);
		vector< vector<int> >().swap(map_sangun);
		queue< pair<int, int> >().swap(fire_start);
		queue< pair<int, int> >().swap(sangun_start);

	} //end of while

	//output
	while (!ans.empty()) {
		if (ans.front() == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ans.front() << endl;
		ans.pop();
	}
}