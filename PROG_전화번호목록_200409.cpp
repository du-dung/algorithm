/* 전화번호 목록 Level 2
https://programmers.co.kr/learn/courses/30/lessons/42577
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for(auto iter = phone_book.begin(); iter != phone_book.end()-1; iter++){
        if(*iter == (*(iter+1)).substr(0, (*iter).length())){
            return false;
        }
    }
    return true;
}
