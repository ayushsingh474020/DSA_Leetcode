class Solution {
public:
    // vector<vector<int>> dp;
    int flag=0;
    int solverec(vector<int>& nums, int i, int target, vector<vector<int>> &dp){
        if(i==nums.size()){
            if(target==0){
                flag=1;
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        if(target-nums[i]>=0){
            return dp[i][target]=max(1+solverec(nums,i+1,target-nums[i],dp),solverec(nums,i+1,target,dp));
        }
        else{
            return dp[i][target]=solverec(nums,i+1,target,dp);
        }
        return 0;
    }
    int solvemem(vector<int>& nums, int i, int target, vector<vector<int>> &dp){
        
        if(nums[i]>target){
            return INT_MIN;
        }
        if(nums[i]==target){
            return 1;
        }
        if(dp[target][i]!=-1){
            return dp[target][i];
        }
        int ans=INT_MIN;
        for(int x=i+1 ; x<nums.size() ; x++){
            int a=solvemem(nums,x,target-nums[i],dp);
                if(a!=INT_MIN){
                    ans=max(ans,1+a);
                }
        }
        dp[target][i]=ans;
        return ans;
        // return ans;
    }
    // vector
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        // map<int,int> m;
        // for(int i=0 ; i<nums.size() ; i++){
        //     m[nums[i]]++;
        // }
        
        // vector<vector<int>> dp(target+1,vector<int>(nums.size()+1,-1));
        // // vector<int> dp(target+1,INT_MIN);
        // sort(nums.begin(),nums.end());
        // int answer=INT_MIN;
        // for(int i=0 ; i<nums.size() ; i++){
        //     // if(nums[i]>target){
        //     //     break;
        //     // }
        //     int ans=solvemem(nums,i,target,dp);
        //     if(ans!=INT_MIN){
        //         answer=max(ans,answer);
        //     }
        // }
        // // long long int ans=solverec(m,0,target);
        // if(answer!=INT_MIN){
        //     return answer;
        // }
        // return -1;
        
        // dp.clear();
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        int ans=solverec(nums,0,target,dp);
        if(!flag){
            return -1;
        }
        return ans;
    }
};