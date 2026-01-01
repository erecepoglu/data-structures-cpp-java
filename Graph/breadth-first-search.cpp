#include <iostream>
#include <vector>
#include <queue>

void addEdge(std::vector<std::vector<int>>& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
};
void breadth_first_search(std::vector<std::vector<int>>& adj, 
        int v, int s){
    bool visited[v+1];
    for(int i = 0; i < v; i++){
        visited[i]= false;
    }
    std::queue<int> q;
    visited[s] = true;
    q.push(s);
    while(q.empty() == false){
        int u = q.front();
        q.pop();
        std::cout << u << " ";
        for(int m: adj[u]){
            if(visited[m] == false){
                visited[m] = true;
                q.push(m);
            }
        }
    }
    std::cout << std::endl;
}
int main(){
    int v = 4;
    std::vector<std::vector<int>> adj(v);
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    breadth_first_search(adj,4,0);
}
