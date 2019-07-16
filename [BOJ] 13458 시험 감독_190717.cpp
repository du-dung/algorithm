//https://www.acmicpc.net/problem/13458

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    //input
    int N, B, C;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    cin >> B >> C;
    
    //solve
    unsigned long long ans=N; /* 각 시험장에 총감독관 한 명씩 */
    for(int i=0; i<N; i++){ //시험장
        A[i] -= B;
        if(A[i]>0){
            ans += (A[i]+C-1)/C;
            /* 부감독관의 수 더하기
             방법1: (A[i]+C-1)/C
             방법2: ceil(A[i]/C) -> 주의: A[i] 혹은 C를 double로 선언하거나 명시적 형변환 해주기!*/
        }
    }
    
    //output
    cout << ans;
}
