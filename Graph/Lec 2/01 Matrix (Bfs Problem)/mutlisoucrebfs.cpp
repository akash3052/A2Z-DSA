class Solution {
public:
    vector<int> delx = {0, 0, -1, 1};
    vector<int> dely = {-1, 1, 0, 0};

    bool isValid(int x, int y, vector<vector<int>> &mat){
        if(x <0 || y < 0 || x >= mat.size() || y >= mat[0].size()){
            return false;
        }
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dist(row, vector<int>(col,0));
        vector<vector<int>> visited(row, vector<int>(col,0));
        queue<pair<pair<int,int>, int>> q;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 0){
                    // note : multisource bfs
                    // There are multiple starting points like rotten oranges problem.
                    q.push({{i,j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            // note : since we are maintaining distance in the queue itself. so, no need to do level order traversal.
            // int size = q.size(); while(size--) {} -> not requirred
            int x = q.front().first.first;
            int y = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            dist[x][y] = distance;
            for(int i = 0; i < 4; i++){
                int newx = x + delx[i];
                int newy = y + dely[i];
                if(isValid(newx, newy, mat) && !visited[newx][newy]){
                    q.push({{newx, newy}, distance+1});
                    visited[newx][newy] = 1;
                }
            }
        }

        return dist;
    }
};


TC = O(V+E)
SC = O(V*V)

