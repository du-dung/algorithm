/* 2252. 줄 세우기 Gold 2
 https://www.acmicpc.net/problem/2252
 */

import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] before = new int[N+1];
        List<Integer>[] after = new LinkedList[N+1];
        for (int i = 1; i <= N; i++) {
            after[i] = new LinkedList<>();
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int tmp1 = Integer.parseInt(st.nextToken()), tmp2 = Integer.parseInt(st.nextToken());
            before[tmp2]++;
            after[tmp1].add(tmp2);
        }

        //초기값 -> 앞에 서야 하는 학생이 없는 경우 queue에 추가
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            if(before[i] == 0) queue.add(i);
        }

        while(!queue.isEmpty()){
            int now = queue.poll();
            sb.append(now).append(' ');
            for (int next : after[now]) {
                before[next]--;
                if(before[next] == 0) queue.add(next);
            }
        }

        System.out.println(sb.toString());
    }
}
