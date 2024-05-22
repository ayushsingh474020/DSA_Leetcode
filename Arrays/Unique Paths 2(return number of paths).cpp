class Solution {
public:
    int solverec(vector<vector<int>>& grid, int i, int j){
        if(grid[grid.size()-1][grid[0].size()-1]==1 || grid[0][0]==1){
            return 0;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return 1;
        }
        if(i>=grid.size() || j>=grid[0].size()){
            return 0;
        }
        if((i<grid.size() && j<grid[0].size()) && grid[i][j]==1){
            return 0;
        }
        return solverec(grid,i+1,j)+solverec(grid,i,j+1);
    }
    int solvemem(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(grid[grid.size()-1][grid[0].size()-1]==1 || grid[0][0]==1){
            return 0;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return 1;
        }
        if(i>=grid.size() || j>=grid[0].size()){
            return 0;
        }
        if((i<grid.size() && j<grid[0].size()) && grid[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j]=solvemem(grid,i+1,j,dp)+solvemem(grid,i,j+1,dp);
        return dp[i][j];
    }
    long long solvetab(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>>dp (grid.size()+1, vector<long long> (grid[0].size()+1,0));
        if(grid[m-1][n-1]==1 || grid[0][0]==1){
            return 0;
        }
        dp[m-1][n-1]=1;
        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                if(grid[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]+=dp[i+1][j]+dp[i][j+1];
                }
                
            }
        }
        return dp[0][0];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // return solverec(grid,0,0);

        // vector<vector<int>>dp (grid.size()+1, vector<int> (grid[0].size()+1,-1));
        // return solvemem(grid,0,0,dp);

        return solvetab(grid);
        // return 0;
    }
};