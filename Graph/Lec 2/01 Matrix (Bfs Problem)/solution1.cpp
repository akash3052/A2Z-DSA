// Note : I was applying bfs from each of the non zero cell. That's why tle occured.
//       37/50 tc passed.

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

    int bfs(int i, int j, vector<vector<int>> &visited, vector<vector<int>> &mat){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j++){
                    int newx = x + delx[j];
                    int newy = y + dely[j];
                    if(isValid(newx, newy, mat) && !visited[newx][newy]){
                        if(mat[newx][newy] == 0){
                            return level;
                        }else{
                            visited[newx][newy] = 1;
                            q.push({newx, newy});
                        }
                    }
                }
            }
            level++;
        }
        return level;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> res(row, vector<int>(col,0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] != 0){
                    // applying bfs from each of the non zero cell.
                    vector<vector<int>> visited(row, vector<int>(col,0));
                    res[i][j] = bfs(i, j, visited, mat);
                }
            }
        }
        return res;
    }
};
