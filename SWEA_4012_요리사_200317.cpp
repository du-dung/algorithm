/* 4012. [모의 SW 역량테스트] 요리사
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeUtVakTMDFAVH&categoryId=AWIeUtVakTMDFAVH&categoryType=CODE
 -> 완탐 with 조합(절반만!)
 */
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int synergy[16][16];
int answer;
bool choose[16];

void comb(int num, int count) {
    if (count == N / 2) { //조합 구함
        for (int i=0; i<N; i++) {
            cout << choose[i] << ' ';
        }
        cout << '\n';
        
        int f1 = 0, f2 = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (choose[i] == choose[j]) { //같은 그룹
                    if (choose[i]) //f1에 속함
                        f1 += synergy[i][j] + synergy[j][i];
                    else //f2
                        f2 += synergy[i][j] + synergy[j][i];
                }
            }
        }
        if (abs(f1 - f2) < answer)  answer = abs(f1 - f2);
        return;
    }
    
    count++;
    for (int i=num+1; i<N; i++) { //다음 조합으로
        choose[i] = true;
        comb(i, count);
        choose[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int TC;
    cin >> TC;
    choose[0] = true;
    for (int testCase = 1; testCase <= TC; testCase++) {
        cin >> N;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                cin >> synergy[i][j];
            }
        } //end of input
        
        answer = 0x3f3f3f3f; //initialize
        comb(0, 1);  //0은 항상 true
        
        //output
        cout << '#' << testCase << ' ' << answer << '\n';
    }
}
