class Solution {
public:
    vector<int> delx = {0, 0, -1, 1};
    vector<int> dely = {-1, 1, 0, 0};
    
    bool isValid(int x, int y, vector<vector<int>> &grid){
        if( x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()){
            return false;
        }
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int level = 0;
        int freshCount = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }
        while(!q.empty() && freshCount){
            int size = q.size();
            while(size--){
                pair<int,int> node = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int newx = node.first + delx[i];
                    int newy = node.second + dely[i];
                    if(isValid(newx, newy, grid) && grid[newx][newy] == 1){
                        q.push({newx, newy});
                        grid[newx][newy] = 2;
                        freshCount--;
                        if(freshCount == 0){
                            break;
                        }
                    }
                }
                if(freshCount == 0){
                    break;
                }
            }
            level++;
        }
        return freshCount ? -1 : level;
    }
};


TC = O(row * col)
