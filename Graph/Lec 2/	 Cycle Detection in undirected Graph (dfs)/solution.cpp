class Solution {
  private:
    bool dfs(int parent, int src, vector<int> adj[], vector<int> &visited){
        visited[src] = true;
        for(auto adjacentNode: adj[src]){
            if(!visited[adjacentNode]){
                // If any node is returning true, then we will not check for other nodes. we will simply return true.
                // If a node is returning false, then in that case, we will check for other nodes.
                // Initially I was doing return dfs(src, adjacentNode, adj, visited) -> all tc were not passing.
                // because in case of false also, we were not checking other nodes.
                if(dfs(src, adjacentNode, adj, visited) == true ){
                    return true;
                }
            }else if (adjacentNode != parent){ 
                // if the adjacentNode is visited and adjacentNode is not parent of src, then there must be cycle.
                // because that adjacentNode is visited by some other flow.
                return true;
                
            }
        }
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dfs(-1, i, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

TC = O(V+E)
SC = O(V)

  

//{ Driver Code Starts.
// int main() {
//     int tc;
//     cin >> tc;
//     while (tc--) {
//         int V, E;
//         cin >> V >> E;
//         vector<int> adj[V];
//         for (int i = 0; i < E; i++) {
//             int u, v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         Solution obj;
//         bool ans = obj.isCycle(V, adj);
//         if (ans)
//             cout << "1\n";
//         else
//             cout << "0\n";
//     }
//     return 0;
// }
// } Driver Code Ends
