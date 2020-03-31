/* 1707. 이분 그래프 Gold 4
https://www.acmicpc.net/problem/1707
-> BFS
*/

import java.io.*;
import java.util.*;

public class Main {
    static Set<Integer> s[]; //연결된 정점의 정보를 저장하는 set 배열
    static int[] group; //각 정점의 집합을 저장하는 배열
    static Queue<Integer> q = new LinkedList<>(); // BFS에서 사용할 queue
    static boolean answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int TC = Integer.parseInt(st.nextToken());
        for (int testCase = 0; testCase < TC; testCase++) {
            st = new StringTokenizer(br.readLine());
            int V = Integer.parseInt(st.nextToken()), E = Integer.parseInt(st.nextToken());

	    //initialize
            s = new Set[V+1];
            group = new int[V+1];
            for (int i = 1; i <= V; i++) {
                s[i] = new HashSet<>();
            }
            answer = true; //정답 플래그

            for (int i = 0; i < E; i++) { //두 정점의 정보를 받아온다
                st = new StringTokenizer(br.readLine());  //string tokenizer 객체 생성 및 초기화
                int v1 = Integer.parseInt(st.nextToken()), v2 = Integer.parseInt(st.nextToken()); //간선 받아온다
                s[v1].add(v2); //v1번 정점에 v2로 가는 간선 추가
                s[v2].add(v1); //v2번 정점에 v1로 가는 간선 추가
            }
            //end of input

            for (int v = 1; v <= V; v++) { //모든 정점에 대해 검사
                if(group[v] != 0) continue;   
		group[v] = 1;
                bfs(v);
                if(!answer) break;
            }

            System.out.println(answer? "YES" : "NO"); //answer 값이 true이면 YES 출력, false이면 NO 출력
        }
    }

    static void bfs(int v){
        q.offer(v); //q에 현재 정점 넣음
        while(!q.isEmpty()) { //BFS, q가 빌 때까지 검사
            int a = q.poll(); //a에 연결된 값 받아옴
            for(int i : s[a]) { //a에 연결된 모든 정점 탐색
                if(group[i] == Group[a]) { //연결된 정점 i와 현재 정점 a의 그룹이 같음 -> 조건 불만족
                    answer = false; //정답 플래그 설정
                    q.clear();
                    return;
                }
                if(group[i] == 0) {
                    group[i] = group[a] == 1 ? 2 : 1; //group[a]의 값이 1이면 2, 아니면(2이면) 1 설정
                    q.offer(i); //q에 정점 i 넣어줌
                }
            }
        }
    }
}