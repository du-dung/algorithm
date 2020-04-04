/* 자물쇠와 열쇠 Level 3
https://programmers.co.kr/learn/courses/30/lessons/60059
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock.size(), M = key.size();
    vector<vector<int>> newLock(N + (M-1)*2, vector<int>(N+(M-1)*2, 0));
    for (int i=0; i<N; i++) { //실제 lock -> newLock에 채우기
        for (int j=0; j<N; j++) {
            newLock[i+M-1][j+M-1] = lock[i][j];
        }
    }
    
    for (int turn = 0; turn < 4; turn++) {
        //열쇠를 자물쇠에 갖다댈 수 있는 모든 경우 조회
        for (int x=0; x<N+M-1; x++) {
            for (int y=0; y<N+M-1; y++) { //x, y는 열쇠 왼쪽 상단 좌표
                
                //열쇠 끼워넣기
                for (int i=0; i<M; i++) {
                    for (int j=0; j<M; j++) {
                        if (key[i][j] == 1) {
                            newLock[i+x][j+y]++;
                        }
                    }
                }
                
                //열 수 있는지 확인
                bool flag = true;
                for (int i=M-1; i<M-1+N; i++) { //실제 lock만큼 조회
                    for (int j=M-1; j<M-1+N; j++) {
                        if (newLock[i][j] != 1) {
                            flag = false;
                            break;
                        }
                    }
                    if(!flag)   break;
                }
                if (flag) {
                    return true;
                }
                
                //열쇠 다시 빼기
                for (int i=0; i<M; i++) {
                    for (int j=0; j<M; j++) {
                        if (key[i][j] == 1) {
                            newLock[i+x][j+y]--;
                        }
                    }
                }
            }
        }

        //열쇠 90도 돌리기
        vector<vector<int>> tmp(M, vector<int>(M));
        for (int i=0; i<M; i++) {
            for (int j=0; j<M; j++) {
                tmp[j][M-1-i] = key[i][j];
            }
        }
        key.swap(tmp);
    }
    return false;
}

int main() {
    cout << solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
}
