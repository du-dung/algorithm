/* 괄호 변환 Level 2
 https://programmers.co.kr/learn/courses/30/lessons/60058
 
-> 처음에 내 생각대로 구현하다가 틀렸다... 문제에서 시키는 대로 하자.
 답 맞추고 나서 다른 사람 코드 보기 눌렀더니 foreach문을 쓰고 있길래 따라서 바꿨다 훨씬 깔끔해진 느낌!!
 사실 더 바꿨다 깔끔해보이는 거 다 따라했다.. 
 */

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isRight(string p){
    int count = 0;
    for (char c : p) {
        if (c == '(') count++;
        else    count--;
        if (count < 0)  return false;
    }
    return true;
}

string solution(string p) {
    if(p == "" || isRight(p))   return p; //빈 문자열 or 올바른 문자열은 바로 반환
    
    string u, v;
    int count = 0;
    for (int i=0; i<p.size(); i++) {
        if (p[i] == '(') count++;
        else    count--;
        if(count == 0){
            u = p.substr(0, i+1); //균형잡힌 괄호 문자열로 분리
            v = solution(p.substr(i+1));
            break;
        }
    }
    
    if (isRight(u)) return u + v; //u가 올바른 경우
    
    for (char &c : u) c = c == '('? ')' : '('; //괄호  역전
    return "(" + v + ")" + u.substr(1, u.size()-2);
}

int main() {
    cout << solution("(()())()") << '\n' //(()())()
        << solution(")(") << '\n' //()
        << solution(")()()()(") << '\n' //(((())))
        << solution("()))((()") << '\n'; //()(())()
}
