/* 1065. 한수 Silver 4
 https://www.acmicpc.net/problem/1065
 */

#include<iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    
    int count;
    if (num < 100){ //100보다 작은 수는 모두 한수
        count = num;
    }
    else {
        //num은 세자리 수 이므로 (1000미만), 각 자리의 수를 구하여 등차수열인지 알아낸다.
        count = 99; //초기값
        int a, b, c; //순서대로 100,10,1의 자리수
        for (int i = 100; i <= num; i++){
            a = i / 100; b = i / 10 % 10; c = i % 10;
            if (a - b == b - c) //등차수열
                count++;
        }
    }
    
    cout << count;
}
