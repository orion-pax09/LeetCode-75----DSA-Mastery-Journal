class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int , int> , int>>Q;
        int n = grid.size();
        int m = grid[0].size();
        int maxTime = 0;
        int fresh = 0;
        for (int i = 0 ; i < grid.size() ; i++){
            for (int j = 0 ; j < grid[0].size() ; j++){
                if (grid[i][j]==2){
                    Q.push({{i,j} , 0});
                }
                else if (grid[i][j]==1){
                    fresh++;
                }
            }
        }
        vector<int>rs={1,-1,0,0};
        vector<int>cs={0,0,-1,1};
        while(!Q.empty()){
            int rows = Q.front().first.first;
            int cols = Q.front().first.second;
            int t = Q.front().second;
            Q.pop();
            maxTime = max(maxTime , t);
            for (int i = 0 ; i < 4 ; i++){
                int nc = cs[i] + cols;
                int nr = rs[i] + rows;
                if (nc >=0 &&nc<grid[0].size()&&nr>=0&&nr<grid.size()&&grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    fresh--;
                    Q.push({{nr,nc} , t+1});
                }
            }
        }
        if (fresh>0){
            return -1;
        }
        return maxTime;
    }
};
