class Solution {
public:
    void dfs(int i, vector<int> &visited, vector<vector<int>> &adjMatrix){
        visited[i] = true;
        for(int j = 0; j < visited.size(); j++){
            if(!visited[j] && adjMatrix[i][j] == 1){
                dfs(j, visited, adjMatrix);
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
                dfs(i, visited, isConnected);
            }
        }
        return count;
    }
};


TC = O(V+E)
SC = O(V)

