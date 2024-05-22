class Solution {
public:
    int solverec(vector<vector<int>>& grid, int i, int j){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        int a=INT_MAX;
        int b=INT_MAX;
        if(i+1<grid.size()){
            a=solverec(grid,i+1,j);
        }
        if(j+1<grid[0].size()){
            b=solverec(grid,i,j+1);
        }
        return grid[i][j]+min(a,b);
    }
    int solvemem(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=INT_MAX;
        int b=INT_MAX;
        if(i+1<grid.size()){
            a=solvemem(grid,i+1,j,dp);
        }
        if(j+1<grid[0].size()){
            b=solvemem(grid,i,j+1,dp);
        }
        dp[i][j]=grid[i][j]+min(a,b);
        return grid[i][j]+min(a,b);
    }
    int solvetab(vector<vector<int>>& grid){
        vector<vector<int>> dp(grid.size()+1, vector<int> (grid[0].size()+1,0));
        dp[grid.size()-1][grid[0].size()-1]=grid[grid.size()-1][grid[0].size()-1];
        for(int i=grid.size()-1 ; i>=0 ; i--){
            for(int j=grid[0].size()-1 ; j>=0 ; j--){
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        // int ans=solverec(grid,0,0);
        // return ans;

        // vector<vector<int>> dp(grid.size()+1, vector<int> (grid[0].size()+1,-1));
        // int ans=solvemem(grid,0,0,dp);
        // return ans;

        return solvetab(grid);
    }
};