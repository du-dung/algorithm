/* 16236. 아기 상어 Gold 5
 https://www.acmicpc.net/problem/16236
 -> BFS, 시뮬레이션
 */

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

#define INF 0x3f3f3f3f

struct {
    int x, y;
}typedef lo;

struct cmp {
    bool operator()(lo a, lo b) {
        if (a.x == b.x)
            return a.y > b.y;
        else
            return a.x > b.x;
    }
};

//left=0 up=1 right=2 down=3
int dirx[4] = { 0,-1,0,1 };
int diry[4] = { -1,0,1,0 };

int main() {
    int N = 0;
    int map[22][22];
    int size = 2, x = 0, y = 0; //size and location of baby shark
    int ans = 0; //answer; time to eat fish (seconds)
    
    
    //input
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) { //baby shark
                x = i; y = j; map[i][j] = 0;
            }
        }
    }
    memset(&map[0][0], INF, sizeof(map[0]));
    memset(&map[N+1][0], INF, sizeof(map[0]));
    for (int i = 1; i <= N; i++) {
        map[i][0] = INF; map[i][N+1] = INF;
    }
    
    //search
    queue<lo> fish;
    priority_queue<lo, vector<lo>, cmp> fish_level;
    bool found_fish = false;
    int sizeq, nx, ny, dist = -1; //initial
    
    int check[22][22] = { {0,} }; //don't work twice
    int ate = 0; //number of fish eaten by the baby shark of current level(size)
    
    fish.push({ x, y }); //push first location of the baby shark
    check[x][y] = 1;
    while (!fish.empty()) { //BFS
        sizeq = fish.size(); dist++;
        for (; sizeq; sizeq--) {
            x = fish.front().x; y = fish.front().y; fish.pop();
            
            if (map[x][y] > 0 && map[x][y] < size) { //can eat
                fish_level.push({ x,y }); found_fish = true;
                continue;
            }
            
            if (found_fish) continue;
            
            for (int i = 0; i < 4; i++) { //search 4 direction
                nx = x + dirx[i]; ny = y + diry[i];
                if (size >= map[nx][ny] && !check[nx][ny]) //can go
                    fish.push({ nx,ny }); check[nx][ny] = 1;
            }
        }
        
        //end of the level
        if (found_fish) {
            //eat fish
            x = fish_level.top().x; y = fish_level.top().y;
            ans += dist; ate++;
            map[x][y] = 0; //eat
            
            if (ate == size && size < 8) { //fishes are smaller than 7
                size++; ate = 0;
            }
            
            //initialize
            found_fish = false;
            
            queue<lo> emt;    fish.swap(emt);
            priority_queue<lo, vector<lo>, cmp> emtt;  fish_level.swap(emtt);
            memset(check, 0, sizeof(check));
            
            dist = -1;
            fish.push({ x,y });
            check[x][y] = 1;
        }
    }
    
    cout << ans;
}
