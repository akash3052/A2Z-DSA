class Solution {
  public:
    
    void dfs(int source, vector<int> adj[], vector<int> &res, vector<int> &visited){
        visited[source] = true;
        res.push_back(source);
        for(auto v : adj[source]){
            if(!visited[v]){
                dfs(v, adj, res, visited);
            }
        }
    }
  
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<int> visited(V);
        dfs(0, adj, res, visited);
        return res;
    }
};

TC = O(V+E)
SC = O(V)


  
