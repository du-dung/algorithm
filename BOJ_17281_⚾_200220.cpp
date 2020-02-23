/* 17281. ⚾ Gold 4
 https://www.acmicpc.net/problem/17281
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N; //이닝 수
int players[50][10];
int answer = 0; //가장 많은 득점 기록

void game(int order[])
{
    int tanswer = 0; //이번 게임에서의 점수
    bool runner[4] = { 0, }; //초기 : 주자 x , 1,2,3루 주자가 있으면 1, 없으면 0
    int out = 0; //out이 3이 되면 주자를 비운다
    int i = 0; //이닝
    while(i<N){
        bool flag = false;
        for (int j = 0; j < 8; j++) { //타순 -> j가 3일 때는(4번 타자) 따로!
            int index = order[j];
            if (j == 3 && !flag) { //4번타자 -> 0번 인덱스 참조
                index = 0;
                j--;
                flag = true;
            }
            switch (players[i][index]) {
                case 1: //안타
                    if(runner[3])  tanswer++; //3루에 있었던 주자 득점
                    for (int k = 3; k > 1; k--) { //한 루씩 진루
                        runner[k] = runner[k - 1];
                    }
                    runner[1] = true; //타자 1루로 진루
                    break;
                case 2: //2루타
                    if (runner[3]) tanswer++; //3루에 있었던 주자 득점
                    if (runner[2]) tanswer++; //2루에 있었던 주자 득점
                    runner[3] = runner[1]; //1루에 있던 주자 3루로 진루
                    runner[2] = true; //타자 2루로 진루
                    runner[1] = false; //1루는 빈다
                    break;
                case 3: //3루타
                    if (runner[3]) tanswer++; //3루에 있었던 주자 득점
                    if (runner[2]) tanswer++; //2루에 있었던 주자 득점
                    if (runner[1]) tanswer++; //1루에 있었던 주자 득점
                    runner[3] = true; //타자 3루로 진루
                    runner[2] = runner[1] = false; //1, 2루는 빈다
                    break;
                case 4: //홈런
                    if (runner[3]) tanswer++; //3루에 있었던 주자 득점
                    if (runner[2]) tanswer++; //2루에 있었던 주자 득점
                    if (runner[1]) tanswer++; //1루에 있었던 주자 득점
                    tanswer++; //타자 득점
                    runner[3] = runner[2] = runner[1] = false; //1, 2, 3루는 빈다
                    break;
                case 0: //아웃
                    if (++out == 3) {
                        runner[3] = runner[2] = runner[1] = false; //1, 2, 3루는 빈다
                        out = 0; //다음 이닝으로
                        if(i++ == N){
                            j=8; //for문 빠져나오게 -> while도 빠져나옴
                        }
                    }
            } //end of switch
        } //end of for players
    } //end of for innings
    
    if(answer < tanswer)    answer = tanswer;//갱신
}

int main()
{
    // input
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> players[i][j];
        }
    }
    
    // solve
    int perm[8] = { 1, 2, 3, 4, 5, 6, 7, 8 }; // 1번 선수(인덱스 0)는 항상 4번 타자
    do{
        game(perm);
    } while (next_permutation(perm, perm+8));
    
    // output
    cout << answer;
}
