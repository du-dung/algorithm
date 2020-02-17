#include <iostream>
#include <algorithm>
using namespace std;

#define max4(a, b, c, d){ max(a,b) > max(c,d) ? max(a,b) : max(c,d) }

int main() {
	int N, map[1000]; //가로 길이는 항상 1000 이하
	int answer;
	for (int testCase = 1; testCase <= 10; testCase++) {
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> map[i];
		}//end of input

		//solve
		answer = 0;
		int around;
		for (int i = 2; i < N-2; i++) {
			around = max4(map[i - 2], map[i - 1], map[i + 1], map[i + 2]); //좌우 4칸 중 가장 높은 빌딩의 높이
			if(map[i]>around){ //조망권 확보
				answer += map[i] - around;
				i += 2; //우측 두 칸은 조망권 확보 불가
			}
		}

		//answer
		cout << "#" << testCase << " " << answer << '\n';
	}
} //end of main