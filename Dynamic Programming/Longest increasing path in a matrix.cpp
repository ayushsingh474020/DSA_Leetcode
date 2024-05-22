class Solution {
public:
    int solverec(vector<vector<int>>& matrix, int i, int j){
        if(i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }
        int ans1=1;
        int ans2=1;
        int ans3=1;
        int ans4=1;
        if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j]){
            ans1+=solverec(matrix, i+1,j);
        }
        if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j]){
            ans2+=solverec(matrix, i,j+1);
        }
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]){
            ans3+=solverec(matrix, i-1,j);
        }
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]){
            ans4+=solverec(matrix, i,j-1);
        }
        
        return max(ans1,max(ans2,max(ans3,ans4)));
    }

    int memoization(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &dp){
        if(i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans1=1;
        int ans2=1;
        int ans3=1;
        int ans4=1;
        if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j]){
            ans1+=memoization(matrix, i+1,j,dp);
        }
        if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j]){
            ans2+=memoization(matrix, i,j+1,dp);
        }
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]){
            ans3+=memoization(matrix, i-1,j,dp);
        }
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]){
            ans4+=memoization(matrix, i,j-1,dp);
        }
        dp[i][j]=max(ans1,max(ans2,max(ans3,ans4)));
        return dp[i][j];
    }

    int tabulation(vector<vector<int>>& matrix){
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,1));

        for(int i=0 ; i<dp.size() ; i++){
            for(int j=0 ; j<dp[0].size() ; j++){
                if(i>=matrix.size() || j>=matrix[0].size()){
                    dp[i][j]=0;
                }
            }
        }
        int ans1=0;
        int ans2=0;
        int ans3=0;
        int ans4=0;

        for(int i=dp.size()-2 ; i>=0 ; i--){
            for(int j=dp[0].size()-2 ; j>=0 ; j--){
                if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j]){
                    ans1=i+1<dp.size() ? dp[i+1][j] : 0;
                }
                if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j]){
                    ans2=j+1<dp[0].size() ? dp[i][j+1] : 0;
                }
                if(i-1>=0 && matrix[i-1][j]>matrix[i][j]){
                    ans3=i-1>=0 ? dp[i-1][j] : 0;
                }
                if(j-1>=0 && matrix[i][j-1]>matrix[i][j]){
                    ans4=j-1>=0 ? dp[i][j-1] : 0;
                }
                dp[i][j]+=max(ans1,max(ans2,max(ans3,ans4)));
            }
        }
        int maxi=0;
        for(int i=0 ; i<dp.size() ; i++){
            for(int j=0 ; j<dp[0].size() ; j++){
                if(maxi<dp[i][j]){
                    maxi=dp[i][j];
                }
            }
        }
        return maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // int maxi=0;
        // for(int i=0 ; i<matrix.size() ; i++){
        //     for(int j=0 ; j<matrix[0].size() ; j++){
        //         int temp = solverec(matrix,i,j);
        //         if(temp>maxi){
        //             maxi=temp;
        //         }
        //     }
        // }
        // return maxi;

        // vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        // int maxi=0;
        // for(int i=0 ; i<matrix.size() ; i++){
        //     for(int j=0 ; j<matrix[0].size() ; j++){
        //         int temp = memoization(matrix,i,j,dp);
        //         if(temp>maxi){
        //             maxi=temp;
        //         }
        //     }
        // }
        // return maxi;

        return tabulation(matrix);

    }
};