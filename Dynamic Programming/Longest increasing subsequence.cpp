class Solution {
public:
    // int length=1;
    int solverec(vector<int> &nums, int i){
        if(i>=nums.size()){
            return 0;
        }
        if(i==nums.size()-1){
            return 1;
        }
        int extra=1;
        for(int x=i ; x<nums.size() ; x++){
            if(nums[x]>nums[i]){
                int a=1+solverec(nums,x);
                if(a>extra){
                    extra=a;
                }
            }
        }
        return extra;
    }
    int solvemem(vector<int>& nums, int i, vector<int> &dp){
        if(i>=nums.size()){
            return 0;
        }
        if(i==nums.size()-1){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int extra=1;
        for(int x=i ; x<nums.size() ; x++){
            if(nums[x]>nums[i]){
                int a=1+solvemem(nums,x,dp);
                if(a>extra){
                    extra=a;
                }
            }
        }
        dp[i]=extra;
        return extra;
    }
    int solvetab(vector<int> &nums){
        int n=nums.size();
        vector<int> dp(n+1,1);
        dp[n]=0;
        dp[n-1]=1;
        for(int x=n-2 ; x>=0 ; x--){
            for(int j=x ; j<n ; j++){
                if(nums[j]>nums[x]){
                    dp[x]=max(dp[x],1+dp[j]);
                }
            }
        }
        int ans=0;
        for(int i=0 ; i<n+1 ; i++){
            if(ans<dp[i]){
                ans=dp[i];
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        // int ans=0;
        // for(int i=0 ; i<nums.size() ; i++){
        //     int a=solverec(nums,i);
        //     if(a>ans){
        //         ans=a;
        //     }
        // }
        // return ans;

        // vector<int> dp(nums.size()+1,-1);
        // int ans=0;
        // for(int i=0 ; i<nums.size() ; i++){
        //     int a=solvemem(nums,i,dp);
        //     if(a>ans){
        //         ans=a;
        //     }
        // }
        // return ans;

        return solvetab(nums);
    }
};