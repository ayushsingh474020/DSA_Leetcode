class Solution {
public:
    int solverec(vector<int> arr, int n, int i){
        if(i>=n){
            return 0;
        }
        if(i==n-1){
            return 1;
        }
        if(arr[i]==0){
            return INT_MAX;
        }
        int mini = INT_MAX;
        for(int j=i+1 ; j<=i+arr[i] ; j++){
            int ans=solverec(arr,n,j);
            if(ans!=INT_MAX){
                mini=min(1+ans,mini);
            }
        }
        return mini;
    }
    
    int memoization(vector<int> arr, int n, int i, vector<int> &dp){
        if(i>=n-1){
            return 0;
        }
        if(arr[i]==0){
            return INT_MAX;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int mini = INT_MAX;
        for(int j=i+1 ; j<=i+arr[i] ; j++){
            int ans=memoization(arr,n,j,dp);
            if(ans!=INT_MAX){
                mini=min(1+ans,mini);
            }
        }
        dp[i]=mini;
        return dp[i];
    }
    
    int tabulation(vector<int> arr, int n){
        vector<int> dp(n+1,INT_MAX);
        dp[n-1]=0;
        dp[n]=0;
        
        for(int i=n-2 ; i>=0 ; i--){
            for(int j=i+1 ; j<=i+arr[i] ; j++){
                if(j<n+1 && dp[j]!=INT_MAX){
                    dp[i]=min(dp[i],1+dp[j]);
                }
            }
        }
        
        if(dp[0]==INT_MAX){
            return -1;
        }
        
        return dp[0];
        
        
    }
    int jump(vector<int>& nums) {
        return tabulation(nums,nums.size());
    }
};