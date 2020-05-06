/* 6987. 월드컵 Silver 3
https://www.acmicpc.net/problem/6987
 */
#include <iostream>
using namespace std;

int t1[] = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
int t2[] = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};
int teams[6][3];
int answer;

void func(int idx){ //idx는 몇 번째 경기인지
    if (answer == 1) return;
    if (idx > 14) { //모든 경기 끝 : 가능!
        answer = 1;
        return;
    }
    
    //t1이 이김
    if (teams[t1[idx]][0] > 0 && teams[t2[idx]][2] > 0) { //t1의 승리 횟수, t2의 패배 횟수가 0보다 커야 함
        teams[t1[idx]][0]--;
        teams[t2[idx]][2]--;
        func(idx+1);
        teams[t1[idx]][0]++;
        teams[t2[idx]][2]++;
    }
    //무승부
    if (teams[t1[idx]][1] > 0 && teams[t2[idx]][1] > 0) { //t1, t2의 무승부 횟수가 0보다 커야 함
        teams[t1[idx]][1]--;
        teams[t2[idx]][1]--;
        func(idx+1);
        teams[t1[idx]][1]++;
        teams[t2[idx]][1]++;
    }
    
    //t1이 짐
    if (teams[t1[idx]][2] > 0 && teams[t2[idx]][0] > 0) { //t1의 패배 횟수, t2의 승리 횟수가 0보다 커야 함
        teams[t1[idx]][2]--;
        teams[t2[idx]][0]--;
        func(idx+1);
        teams[t1[idx]][2]++;
        teams[t2[idx]][0]++;
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i=0; i<4; i++) {
        int sum[3] = {0}; //전체 승, 무, 패 의 합
        for (int j=0; j<6; j++) {
            cin >> teams[j][0] >> teams[j][1] >> teams[j][2];
            sum[0] += teams[j][0];
            sum[1] += teams[j][1];
            sum[2] += teams[j][2];
        }
        
        //전체 승, 패 횟수는 동일해야 하고 무승부는 30(전체 경기 수) - 승, 패 횟수여야 함
        if (sum[0] != sum[2] || 30-sum[0]*2 != sum[1]) {
            cout << 0 << ' ';
            continue;
        }
        
        answer = 0;
        func(0);
        cout << answer << ' ';
    }
}
