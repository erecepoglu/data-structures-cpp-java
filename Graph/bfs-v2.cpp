#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<vector<int>>& adj, int source, vector<bool>& visited){
    queue<int> q;
    visited[source] = true;
    q.push(source);
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout << front << " ";
        
        for(int v : adj[front]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void bfs_v2(vector<vector<int>>& adj, int num_of_vectors){
    // Use vector<bool> instead of bool array for standard compliance
    vector<bool> visited(num_of_vectors, false); 
    
    for(int j = 0; j < num_of_vectors; j++){
        if(!visited[j]){
            bfs(adj, j, visited);
        }
    }
}

int main(){
    // Increase size to 7 (to accommodate indices 0 through 6)
    int v = 7; 
    std::vector<std::vector<int>> adj(v);
    
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    
    // These lines are now safe because adj has size 7
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    
    bfs_v2(adj, v);
}