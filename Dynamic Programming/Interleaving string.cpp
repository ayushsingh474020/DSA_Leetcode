class Solution {
public:
    bool solverec(string s1, string s2,string s3, int i, int j){
        if(i+j>=s3.size()){
            return true;
        }
        if(s1[i]==s2[j] && s1[i]==s3[i+j]){
            return (solverec(s1,s2,s3,i+1,j) || solverec(s1,s2,s3,i,j+1));
        }
        else if(s1[i]==s3[i+j]){
            return solverec(s1,s2,s3,i+1,j);
        }
        else if(s2[j]==s3[i+j]){
            return solverec(s1,s2,s3,i,j+1);
        }
        return false;
    }

    int memoization(string s1, string s2,string s3, int i, int j, vector<vector<int>> &dp){
        if(i+j==s3.size() && i==s1.size() && j==s2.size()){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // int result = 0;
        if(i<s1.size() && j<s2.size() && s1[i]==s2[j] && s1[i]==s3[i+j]){
            dp[i][j]=memoization(s1,s2,s3,i+1,j,dp) || memoization(s1,s2,s3,i,j+1,dp);
            return dp[i][j];
        }
        else if(i<s1.size() && s1[i]==s3[i+j]){
            dp[i][j]=memoization(s1,s2,s3,i+1,j,dp);
            return dp[i][j];
        }
        else if(s2[j]==s3[i+j]){
            dp[i][j]=memoization(s1,s2,s3,i,j+1,dp);
            return dp[i][j];
        }
        return 0;
    }

    int tabulation(string s1, string s2,string s3){
        vector<vector<int>> dp(s1.size()+1,vector<int> (s2.size()+1,0));
        for(int i=0 ; i<s1.size()+1 ; i++){
            for(int j=0 ; j<s2.size()+1 ; j++){
                if((i==s1.size() && j==s2.size()) && i+j==s3.size()){
                    dp[i][j]=1;
                }
            }
        }

        for(int i=s1.size()-1 ; i>=0 ; i--){
            for(int j=s2.size()-1 ; j>=0 ; j--){
                if(s1[i]==s2[j] && s1[i]==s3[i+j]){
                    dp[i][j]=dp[i+1][j] || dp[i][j+1];
                    
                }
                else if(s1[i]==s3[i+j]){
                    if(i+1<s1.size()){
                        dp[i][j]=dp[i+1][j];
                    }
                    
                    
                }
                else if(s2[j]==s3[i+j]){
                    if(j+1<s2.size()){
                        dp[i][j]=dp[i][j+1];
                    }
                    
                    
                }
            }
        }
        return dp[0][0] || dp[0][1] || dp[1][0] || dp[1][1];
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size()){
            return false;
        }
        // return solverec(s1,s2,s3,0,0);

        // vector<vector<int>> dp(s1.size()+1,vector<int> (s2.size()+1,-1));
        // int ans = memoization(s1,s2,s3,0,0,dp);
        // if(ans==0){
        //     return false;
        // }
        // return true;

        return tabulation(s1,s2,s3);
    }
};