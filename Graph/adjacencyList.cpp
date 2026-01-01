#include <iostream>
#include <vector>

void addEdge(std::vector<std::vector<int>>& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
};
/*Robust version
using namespace std;
void addEdge(vector<vector<int>>& adj, int u, int v, bool directed = false) {
    // 1. Bounds Checking
    if (u < 0 || u >= adj.size() || v < 0 || v >= adj.size()) {
        cerr << "Error: Nodes " << u << " and " << v << " must be within graph size bounds." << endl;
        return;
    }

    // 2. Add forward edge
    adj[u].push_back(v);

    // 3. Handle Undirected logic (and avoid double-add on self-loops)
    if (!directed && u != v) {
        adj[v].push_back(u);
    }
}
*/
void printing(std::vector<std::vector<int>>& adj){
    for(int i = 0; i < adj.size(); i++){
        std::cout << i << ": ";
        for(int j = 0; j < adj[i].size(); j++){
            std::cout << adj[i][j] << " ";
        }
       std::cout << std::endl;
    }
}
int main(){
    int v = 4;
    std::vector<std::vector<int>> adj(v);
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    printing(adj);
}