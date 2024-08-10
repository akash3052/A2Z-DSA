
class Solution {
  private:
    bool hasCycle(int src, vector<int> adj[], vector<int> &visited){
        visited[src] = true;
        // we are maintaing immediate parent of each node.
        queue<pair<int,int>> q;
        q.push({-1, src});
        while(!q.empty()){
            int parent = q.front().first;
            int node = q.front().second;
            q.pop();
            for(auto adjacentNode : adj[node]){
                if(!visited[adjacentNode]){
                    visited[adjacentNode] = true;
                    q.push({node, adjacentNode});
                }else if(parent != adjacentNode){
                    // If the adjacentNode is visited and it is not its parent, then it must have been visited by some other node.
                    // which means this contains cycle because we are visiting the same node again through 2 different paths.
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(hasCycle(i, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

TC = O(V + E)
SC = O(V)


// //{ Driver Code Starts.
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
// // } Driver Code Ends



