/* 14889. 스타트와 링크 Silver 3
https://www.acmicpc.net/problem/14889
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int answer = 0x3f3f3f3f;
vector<vector<int>> S;
int N;

void diff(vector<int>& perm){
    int team[2] = {0,};
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            if(perm[i] == perm[j]) team[perm[i]] += S[i][j] + S[j][i];
        }
    }
    if(abs(team[0]-team[1]) < answer) answer = abs(team[0]-team[1]);
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    S.assign(N, vector<int>(N));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> S[i][j];
        }
    }
    
    vector<int> perm(N, 1);
    for (int i=0; i<N/2; i++) {
        perm[i] = 0;
    }
    do{
        diff(perm);
    }while(next_permutation(perm.begin(), perm.end()));
    
    cout << answer;
}
