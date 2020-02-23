/* 5427. 불 Gold 4
 https://www.acmicpc.net/problem/5427
 v01. 18.09.29~18.09.30
 -> BFS
 */

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
using namespace std;

int escape(int w, int h, vector < vector<int> > fire_run, vector< vector<int> > sangun_run, queue< pair<int, int> > fire, queue< pair<int, int> > sangun) {
    /*
     w: width    , h: height
     fire_run: 불이 확산되는 데 걸리는 시간을 저장하는 2차원 배열
     sangun_run: 상근이가 도망치는 데 걸리는 시간을 저장하는 2차원 배열
     fire: BPS에 필요한 queue, 불의 위치가 pair로 들어감
     sangun: BPS에 필요한 queue, 상근이의 위치가 pair로 들어감
     */
    
    pair<int, int> dir[4]; //상하좌우
    dir[0] = make_pair(0, -1);
    dir[1] = make_pair(1, 0);
    dir[2] = make_pair(-1, 0);
    dir[3] = make_pair(0, 1);
    
    //불이 확산되는 데 걸리는 시간 구하기
    int time_fire = 0;
    while (!fire.empty()) {
        int size_f = fire.size();
        time_fire++; //depth
        for (int k = 0; k < size_f; k++) {
            int x = fire.front().first, y = fire.front().second;
            fire.pop();
            
            for (int i = 0; i < 4; i++) {//네 방향 탐색
                int nx = x + dir[i].first, ny = y + dir[i].second;
                if (nx < 0 || ny < 0 || nx == h || ny == w) //배열 범위를 벗어났을 경우
                    continue;
                if (fire_run[nx][ny] == -1) //벽일 경우
                    continue;
                if (fire_run[nx][ny] <= time_fire) //이미 탐색한 칸일 경우
                    continue;
                fire_run[nx][ny] = time_fire;
                fire.push(make_pair(nx, ny));
            }
        }
    }
    
    //상근이 출발지점 저장
    queue<pair<int, int> > next_run;
    next_run.push(make_pair(sangun.front().first, sangun.front().second));
    
    //상근이가 도망치는 데 걸리는 시간 구하기
    int time_sangun = 0;
    while (!sangun.empty()) {
        int size_s = sangun.size();
        time_sangun++; //depth
        for (int k = 0; k < size_s; k++) {
            int x = sangun.front().first, y = sangun.front().second;
            sangun.pop();
            
            for (int i = 0; i < 4; i++) {//네 방향 탐색
                int nx = x + dir[i].first, ny = y + dir[i].second;
                if (nx < 0 || ny < 0 || nx == h || ny == w) //배열 범위를 벗어났을 경우
                    continue;
                if (sangun_run[nx][ny] == -1) //벽일 경우
                    continue;
                if (sangun_run[nx][ny] <= time_sangun) //이미 탐색한 칸일 경우
                    continue;
                sangun_run[nx][ny] = time_sangun;
                sangun.push(make_pair(nx, ny));
            }
        }
    }
    
    //두 배열 비교
    vector< vector<bool> > searched(h, vector<bool>(w, false)); //탐색 여부
    
    while (!next_run.empty()) {
        int x = next_run.front().first, y = next_run.front().second;
        next_run.pop();
        
        for (int i = 0; i < 4; i++) {//네 방향 탐색
            int nx = x + dir[i].first, ny = y + dir[i].second;
            if (nx < 0 || ny < 0 || nx == h || ny == w) //배열 범위를 벗어났을 경우
                return sangun_run[x][y] + 1; //탈출!
            if (searched[nx][ny] == true) //이미 탐색했을 경우
                continue;
            if (sangun_run[nx][ny] == -1) //벽일 경우
                continue;
            if (fire_run[nx][ny] <= sangun_run[nx][ny]) //상근이보다 불이 빠르게 번졌거나, 동시에 도착할 경우
                continue;
            next_run.push(make_pair(nx, ny));
            searched[nx][ny] = true;
        }
    }
    
    return -1; //빠져나오지 못했을 경우
}

int main() {
    int tnum; //number of test case
    int width, height; //너비와 높이
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
                    case '#': //wall, 이동 불가
                        tmp_fire.push_back(-1);
                        tmp_sangun.push_back(-1);
                        break;
                    case '@': //상근이 시작위치
                        tmp_fire.push_back(INT_MAX); //최댓값
                        tmp_sangun.push_back(0); //시작지점
                        sangun_start.push(make_pair(i, j));
                        break;
                    case '*': //불 시작 위치
                        tmp_fire.push_back(0);
                        tmp_sangun.push_back(INT_MAX); //최댓값
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
        
        //초기화
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
