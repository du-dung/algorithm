/* 3378. 스타일리쉬 들여쓰기 D4
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWD3nB5q3T0DFAUZ&categoryId=AWD3nB5q3T0DFAUZ&categoryType=CODE
-> 완전 탐색, 중복 순열
 */
#include <iostream>
#include <string>
using namespace std;

#define Nil -1

class Num {
public:
    int dot, round, curly, bracket;
    Num(){
        dot = round = curly = bracket = 0;
    }
    Num(const Num &n){ //복사생성자
        dot = n.dot;
        round = n.round;
        curly = n.curly;
        bracket = n.bracket;
    }
};

int p, q;
Num master[10], my[10];

inline void findBracketsNum(char c, Num& n)
{
    switch (c) {
    case '(':
        n.round++;
        break;
    case ')':
        n.round--;
        break;
    case '{':
        n.curly++;
        break;
    case '}':
        n.curly--;
        break;
    case '[':
        n.bracket++;
        break;
    case ']':
        n.bracket--;
        break;
    }
}

void validCheck(int r, int c, int s)
{
    for (int i=1; i<p; i++) { //모든 줄에 대해 검사
        if(master[i].dot != (r * master[i].round + c * master[i].curly + s * master[i].bracket))    return; //not valid
    }
    //여기까지 왔으면 r, c, s의 조합이 답이 될 수도 있다는 것
    for (int i=1; i<q; i++) {
        if(my[i].dot == 0){ //처음 구함!
            my[i].dot = r * my[i].round + c * my[i].curly + s * my[i].bracket;
        }
        if(my[i].dot == -1 || my[i].dot != (r * my[i].round + c * my[i].curly + s * my[i].bracket)){ //새로 구한 dot 개수가 다름 -> not valid
            my[i].dot = -1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC;
    cin >> TC;

    for (int testCase = 1; testCase <= TC; testCase++) {
        cin >> p >> q;

        string stmp;
        Num ntmp;
        cin >> stmp;
        for (int j = 0; j < stmp.length(); j++) {
            findBracketsNum(stmp[j], ntmp);
        }

        for (int i = 1; i < p; i++) {
            cin >> stmp;
            int j = 0;
            while (stmp[j] == '.')
                j++; //들여쓰기 한 . 개수 세기
            ntmp.dot = j;
            master[i] = ntmp; //복사생성자
            for (; j < stmp.length(); j++) {
                findBracketsNum(stmp[j], ntmp);
            }
        }

        ntmp.dot = ntmp.round = ntmp.curly = ntmp.bracket = 0; //initialize
        cin >> stmp;
        for (int j = 0; j < stmp.length(); j++) {
            findBracketsNum(stmp[j], ntmp);
        }
        for (int i = 1; i < q; i++) {
            cin >> stmp;
            my[i] = ntmp;
            for (int j = 0; j < stmp.length(); j++) {
                findBracketsNum(stmp[j], ntmp);
            }
        }
        //end of input

        //가능한 모든 r,c,s 값의 조합에 대해 검사 -> 중복순열
        for (int r = 1; r < 21; r++) {
            for (int c = 1; c < 21; c++) {
                for (int s = 1; s < 21; s++) {
                    validCheck(r, c, s);
                }
            }
        }

        //output
        cout << '#' << testCase << ' ' << 0 << ' '; //첫 번째 줄은 무조건 0개
        for (int i = 1; i < q; i++) {
            cout << my[i].dot << ' ';
        }
        cout << '\n';
    }
}
