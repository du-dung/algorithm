/* 16235. 나무 재테크 Gold 5
 https://www.acmicpc.net/problem/16235
 -> 시뮬레이션
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //인접한 8개 칸 계산
    int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    int N, M, K; /*땅의 크기: NxN, 초기 나무 개수: M개, 기간: K년*/
    cin >> N >> M >> K; //input
    
    vector< vector<int> > food(N, vector<int>(N, 5)); /*땅의 양분: 5로 채워진 N*N 2차원 벡터*/
    vector< vector<int> > A(N, vector<int>(N)); /*겨울마다 추가되는 양분: N*N 2차원 벡터*/
    for (int r = 0; r < N; r++) { //A배열의 값 입력받기
        for (int c = 0; c < N; c++) {
            cin >> A[r][c];
        }
    }
    
    vector<vector<vector<int>>> trees(N, vector<vector<int>>(N));
    int tmp_x, tmp_y, tmp_z;
    for (; M; --M) { //나무 정보 입력받기
        cin >> tmp_x >> tmp_y >> tmp_z;
        trees[--tmp_x][--tmp_y].push_back(tmp_z); //r,c는 1부터 시작
    }
    
    //solve
    for (int n = 1; n <= K; n++) { /* K년이 지난 후 상도의 땅에 살아있는 나무의 개수를 구하는 프로그램을 작성하시오. */
        vector<vector<int>>size(N, vector<int>(N, 0)); //봄, 여름이 끝난 뒤 나무의 개수
        
        /* spring:    봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
         각각의 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다.
         하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다.
         만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다. */
        /* summer:    여름에는 봄에 죽은 나무가 양분으로 변하게 된다.
         각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다. */
        for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
                sort(trees[r][c].begin(), trees[r][c].end()); //어린 나무부터
                for(auto t=trees[r][c].begin(); t!=trees[r][c].end(); t++){ //t는 iterator
                    if(*t <= food[r][c]){ //양분을 섭취할 수 있음
                        food[r][c] -= *t; //양분을 먹고
                        *t += 1; //나이가 1 증가
                    }else{ //양분 섭취 불가 -> 쥬금 & 이후의 모든 나무들도 죽음 (무조건 t보다 나이가 많거나 같으므로)
                        for(auto tt = t; tt!=trees[r][c].end(); tt++){
                            food[r][c] += *tt/2; //양분 추가
                        }
                        trees[r][c].erase(t, trees[r][c].end()); //죽은 나무 삭제
                        break;
                    }
                }
                size[r][c]=(int)trees[r][c].size(); //현재 나무 개수 저장 -> 가을에 추가된 나무는 연산 x
            }
        }
        
        /* fall:    가을에는 나무가 번식한다.
         번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
         어떤 칸 (r, c)와 인접한 칸은 (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1) 이다.
         상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다. */
        for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
                for(int i=0; i<size[r][c]; i++){ //봄, 여름에 있었던 나무에 대해 연산
                    if(trees[r][c][i] %5 ==0){ //나이가 5의 배수 -> 번식가능
                        for(int j=0; j<8; j++){ //인접한 8칸 계산
                            int nr = r+dr[j]; int nc = c+dc[j];
                            if(nr>=0 && nr<N && nc >=0 && nc<N){ //땅의 범위 이내
                                trees[nr][nc].push_back(1); //한 살짜리 나무 추가
                            }
                        }
                    }
                }
            }
        }
        
        /* winter:    겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다.
         각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다. */
        for (int r = 0; r < N; r++) { //A배열
            for (int c = 0; c < N; c++) {
                food[r][c] += A[r][c];
            }
        }
    }
    
    //output
    int ans=0;
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            ans += trees[r][c].size();
        }
    }
    cout<<ans;
}
