class Solution {
public:
    void bfs(int i, vector<int> &visited, vector<vector<int>> &adjMatrix){
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int j = 0; j < visited.size(); j++){
                if(!visited[j] && adjMatrix[u][j] == 1){
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int vertices = isConnected.size();
        vector<int> visited(vertices);
        int count = 0;
        for(int i = 0; i < vertices; i++){
            if(!visited[i]){
                // counting number of times dfs is called, that will be the answer
                count++;
                bfs(i, visited, isConnected);
            }
        }
        return count;
    }
};


TC = O(V+E)
SC = O(V)


  
