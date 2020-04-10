/* 1197. 최소 스패닝 트리 Gold 4
https://www.acmicpc.net/problem/1197
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    static int[] parents;
    static int[] rank;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int V = Integer.parseInt(st.nextToken()), E = Integer.parseInt(st.nextToken());
        int[][] edges = new int[E][3]; //정점 1, 정점 2, 가중치
        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            edges[i][0] = Integer.parseInt(st.nextToken());
            edges[i][1] = Integer.parseInt(st.nextToken());
            edges[i][2] = Integer.parseInt(st.nextToken());
        } //end of input

        Arrays.sort(edges, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[2] - o2[2];
            }
        }); //가중치가 작은 것부터 오름차순으로 정렬

        //makeSet
        parents = new int[V+1];
        rank = new int[V+1];
        for (int i = 1; i <= V; i++) {
            parents[i] = i;
        }

        int a, b, dist; //임시 변수
        long answer = 0;
        int cnt = 0;
        for (int i = 0; i < E; i++) {
            a = edges[i][0]; b = edges[i][1]; dist = edges[i][2];
            if (findSet(a) == findSet(b))   continue; //사이클
            answer += dist;
            union(a, b);
            if (++cnt == V-1)   break; //간선 다 찾음
        }
        System.out.println(answer);
    }

    static int findSet(int x){
        if (parents[x] == x)    return x;
        parents[x] = findSet(parents[x]);
        return parents[x];
    }

    static void union(int x, int y){
        int px = findSet(x), py = findSet(y);
        if (rank[px] > rank[py]){
            parents[px] = py;
        }else{
            parents[py] = px;
            if (rank[px] == rank[py]){
                rank[py]++;
            }
        }
    }
}
