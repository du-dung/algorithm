/* 17136. 색종이 붙이기 Gold 3
 https://www.acmicpc.net/problem/17136
 -> 완전탐색
 */

#include <iostream>
using namespace std;

bool paper[10][10];
int answer = 30; //최대 색종이 개수는 25개이므로
int limit[6] = {0, 5, 5, 5, 5, 5};

bool check(int i, int j, int size){
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if(!paper[i+r][j+c]){
                return false;
            }
        }
    }
    return true;
}

void setValue(int i, int j, int size, int value){
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            paper[i+r][j+c] = value;
        }
    }
}

void solve(int i, int j, int count){
    if(count >= answer)  return;
    if(j==10){ //다음 줄로
        solve(i+1, 0, count);
        return;
    }
    if(i==10){ //전부 다 함
        if(answer > count)    answer = count; //갱신
        return;
    }
    if(!paper[i][j]){ //덮을 필요 x
        solve(i, j+1, count);
        return;
    }
    for(int size = 5; size >= 1; size--){
        if(limit[size] == 0 || i + size > 10 || j + size > 10)  continue; //개수 초과 or 범위 초과
        //덮을 수 있는지 체크
        if(!check(i, j, size))  continue;
        
        //덮기 가능
        setValue(i, j, size, false); //덮었다
        limit[size] --;
        solve(i, j+size, count+1); //다음으로
        
        //원상복구
        setValue(i, j, size, true); //떼었다
        limit[size] ++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> paper[i][j];
        }
    } //end of input
    
    //solve
    solve(0, 0, 0);
    
    //output
    if (answer == 30)
        cout << -1;
    else
        cout << answer;
}
