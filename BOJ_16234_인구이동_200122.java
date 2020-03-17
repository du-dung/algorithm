/* 16234. 인구 이동 Gold 5
 https://www.acmicpc.net/problem/16234
 -> BFS, 조합
 */

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), L = sc.nextInt(), R = sc.nextInt();
        int[][] map = new int[N+2][N+2]; //짹쨩: N+2 * N+2 짤짹쩔짬 첩 (타첩짜캇 詮째)
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
            isChecked = new boolean[N+2][N+2];//濡 梨곌린
            for (int i = 1; i <= N; i++) { //諛대由щ 대 泥댄ы 寃쇰  -> 議고吏 濡
                isChecked[0][i] = isChecked[N + 1][i] = isChecked[i][0] = isChecked[i][N + 1] = true;
            } //諛대由 end
            isEnd = true;

            for (int r = 1; r <= N; r++) {
                for (int c = 1; c <= N; c++) {
                    if (!isChecked[r][c]) { //吏  -> 고 泥댄
                        int population = 0, num = 0;
                        q.offer(new Pair(r, c));
                        myUnion.add(new Pair(r,c));


                        while (!q.isEmpty()) {  //고 紐⑤ 李얘린 (BFS)
                            int x = q.peek().first, y = q.poll().second;
                            if (isChecked[x][y])	continue;
                            isChecked[x][y] = true;
                            population += map[x][y]; num++;

                            //4諛⑺  -> 以蹂듭껜
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

                        population /= num; //ъ“ 媛 移몄 멸뎄 
                        for (int i = 0; i < myUnion.size(); i++) { //고⑹  紐⑤ ㅼ 媛 ъㅼ -> 멸뎄 대
                            map[myUnion.get(i).first][myUnion.get(i).second] = population;
                        }
                        if (myUnion.size() > 1)	isEnd = false; //고⑹  留怨 萸媛 쇰㈃ 대 寃
                        myUnion.clear(); //고 鍮곌린
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
