/* 15666. N과 M(12) Silver 2
 https://www.acmicpc.net/problem/15666
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int num[8], res[8];
vector<vector<int>> s;

bool findDuplicate(vector<int> &v){
    for (auto i : s) {
        bool flag = true;
        for (int j = 0; j < i.size(); j++) {
            if (i[j] != v[j]) {
                flag = false;
            }
        }
        if (flag)   return true; //중복됨
    }
    return false;
}

void perm(int r, int k) { //r은 고른 숫자 개수
    if (M == r) { //중복 체크
        vector<int> l(M);
        for (int i = 0; i < M; i++) {
            l[i] = res[i];
        }
        if (findDuplicate(l))    return; //해당 원소가 이미 있음 -> 출력 x
        s.push_back(l);
        for (int i = 0; i < M; i++) { //출력
            printf("%d ", res[i]);
        }
        printf("\n");
        return;
    }
    for (int i = k; i < N; i++) { //k보다 작은 건 출력 x
        res[r] = num[i];
        perm(r + 1, i); //i 그대로 전달 -> 중복으로 골라도 ok
    }
}

int main() {
    //input
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }
    
    //solve
    sort(num, num + N);
    s.reserve(N<<M);
    perm(0, 0);
}
