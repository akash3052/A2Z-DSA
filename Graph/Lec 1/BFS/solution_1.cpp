class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        q.push(0);
        vector<int> res;
        vector<int> visited(V);
        visited[0] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(auto v : adj[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return res;
    }
};


TC = O(V+ E)
SC = O(V)


