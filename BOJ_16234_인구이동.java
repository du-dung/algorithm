import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), L = sc.nextInt(), R = sc.nextInt();
        int[][] map = new int[N+2][N+2]; //√ ±‚»≠: N+2 * N+2 ≈©±‚¿« πËø≠ (πŸøÓ¥ı∏Æ √ﬂ∞°)
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        //end of input

        //solve
        int answer = -1;
        boolean [][]isChecked;
        Queue<Pair> q = new LinkedList<>();
        ArrayList<Pair> myUnion = new ArrayList<>();
        boolean isEnd = false;

        int[] dx = { -1,0,1,0 };
        int[] dy = { 0,-1,0,1 };

        while (!isEnd) {
            answer++;
            isChecked = new boolean[N+2][N+2];//새로 채우기
            for (int i = 1; i <= N; i++) { //바운더리는 이미 체크한 것으로 표시 -> 조회하지 않도록
                isChecked[0][i] = isChecked[N + 1][i] = isChecked[i][0] = isChecked[i][N + 1] = true;
            } //바운더리 end
            isEnd = true;

            for (int r = 1; r <= N; r++) {
                for (int c = 1; c <= N; c++) {
                    if (!isChecked[r][c]) { //탐색하지 않음 -> 연합 체크
                        int population = 0, num = 0;
                        q.offer(new Pair(r, c));
                        myUnion.add(new Pair(r,c));


                        while (!q.isEmpty()) {  //연합 모두 찾기 (BFS)
                            int x = q.peek().first, y = q.poll().second;
                            if (isChecked[x][y])	continue;
                            isChecked[x][y] = true;
                            population += map[x][y]; num++;

                            //4방향 탐색 -> 중복체크
                            for (int i = 0; i < 4; i++) {
                                int nx = x + dx[i], ny = y + dy[i];
                                if (!isChecked[nx][ny]) {
                                    int diff = Math.abs(map[x][y] - map[nx][ny]);
                                    if (diff >= L && diff <= R) {
                                        q.offer(new Pair(nx,ny));
                                        myUnion.add(new Pair(nx,ny));
                                    }
                                }
                            }

                        } //end of while q

                        population /= num; //재조정할 각 칸의 인구 수
                        for (int i = 0; i < myUnion.size(); i++) { //연합에 속한 모든 원소들의 값 재설정 -> 인구 이동
                            map[myUnion.get(i).first][myUnion.get(i).second] = population;
                        }
                        if (myUnion.size() > 1)	isEnd = false; //연합에 나 말고 뭔가 있으면 이동한 것
                        myUnion.clear(); //연합 비우기
                    } //end of if
                }
            } //end of for all map[r][c]

        } //end of while true
        System.out.println(answer);
    }
}

class Pair{
    int first, second;
    Pair(int a, int b){
        first = a;
        second = b;
    }
}