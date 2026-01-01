import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

class BFS{
    static void addEdge(ArrayList<ArrayList<Integer>> adj, 
                        int u, int v){
        adj.get(u).add(v);
        adj.get(v).add(u);
    }
    static void bfs(ArrayList<ArrayList<Integer>> adj, int v, int s){
        boolean visited[] = new boolean[v+1];
        Queue<Integer> q = new LinkedList<Integer>();
        visited[s] = true;
        q.add(s);
        while (q.isEmpty() == false) {
            int u = q.poll(); // = q.front() in cpp
            System.out.print(u + " ");
            for(int m : adj.get(u)){
                if(visited[m] == false){
                    visited[m] = true;
                    q.add(m);
                }
            }
        }
        System.out.println();
    }
    public static void main(String[] args){
        int v = 5;
        ArrayList<ArrayList<Integer>> adj = 
                new ArrayList<ArrayList<Integer>>(v);
        for(int i = 0; i < v; i++){
            adj.add(new ArrayList<Integer>());
        }
        addEdge(adj,0,1);
        addEdge(adj,0,2);
        addEdge(adj,1,2);
        addEdge(adj,1,3);
        bfs(adj,5,1);
    }
}