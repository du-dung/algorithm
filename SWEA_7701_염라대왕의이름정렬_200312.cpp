/* 7701. 염라대왕의 이름 정렬 D4
 https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWqU0zh6rssDFARG&categoryId=AWqU0zh6rssDFARG&categoryType=CODE
 -> tree set
 */
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Name{
public:
    string s;
    
    Name(string _s){
        s = _s;
    }
    
    bool operator < (const Name &n) const{
        if(s.length() == n.s.length()){
            return s < n.s; //사전 상 먼저인게 앞
        }
        return s.length() < n.s.length(); //길이가 짧은 게 먼저
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int TC;
    cin >> TC;
    for (int testCase = 1; testCase <= TC; testCase++) {
        int N; //이름의 개수
        set<Name> names;
        cin >> N;
        string tmp;
        for (int i=0; i<N; i++) {
            cin >> tmp;
            names.insert(Name{tmp});
        }
        //end of input
        
        //output
        cout << '#' << testCase << '\n';
//        for(Name n : names){
//            cout << n.s << '\n';
//        }
        for(auto iter = names.begin(); iter != names.end(); iter++){
            cout << iter->s << '\n';
        }
    }
}
