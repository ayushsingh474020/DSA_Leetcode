class Solution {
public:
    // int solverec(vector<int> &nums, int x){
//     if(x>=nums.size()){
//         return 0;
//     }
//     int maxi=nums[x];
//     for(int i=x+2 ; i<nums.size() ; i++){
//         int ans=solverec(nums,i);
//         int extra=nums[x];
//         maxi=max(maxi,extra+ans);
//         // cout<<maxi<<endl;
//     }
//     return maxi;
// }
// int solvemem(vector<int> &nums, int x, vector<int> &dp){
//     if(x>=nums.size()){
//         return 0;
//     }
//     if(dp[x]!=-1){
//         return dp[x];
//     }
//     int maxi=nums[x];
//     for(int i=x+2 ; i<nums.size() ; i++){
//         int ans=solvemem(nums,i,dp);
//         int extra=nums[x];
//         maxi=max(maxi,extra+ans);
//         // cout<<maxi<<endl;
//     }
//     dp[x]=maxi;
//     return maxi;
// }
// int solvetab(vector<int> &nums){
//     vector<int> dp(nums.size(),-1);
//     dp[nums.size()-1]=nums[nums.size()-1];
//     if(nums.size()-2>=0){
//         dp[nums.size()-2]=nums[nums.size()-2];
//     }
//     for(int i=nums.size()-3 ; i>=0 ; i--){
//         int maxi=nums[i];
//         for(int j=i+2 ; j<nums.size() ; j++){
//             maxi=max(maxi,nums[i]+dp[j]);
//         }
//         dp[i]=maxi;
//     } 
//     return max(dp[0],dp[1]);

// }
// int solverec(vector<int> &nums, int n){
//     if(n<0){
//         return 0;
//     }
//     if(n==0){
//         return nums[0];
//     }
//     int incl=solverec(nums,n-2)+nums[n];
//     int excl=solverec(nums,n-1);
//     return max(incl,excl);
// }
// int solvemem(vector<int> &nums, int n, vector<int> &dp){
//     if(n<0){
//         return 0;
//     }
//     if(n==0){
//         return nums[0];
//     }
//     if(dp[n]!=-1){
//         return dp[n];
//     }
//     int incl=solvemem(nums,n-2,dp)+nums[n];
//     int excl=solvemem(nums,n-1,dp);
//     dp[n]=max(incl,excl);
//     return dp[n];
// }
// int solvetab(vector<int> &nums){
//     vector<int> dp(nums.size(),-1);
//     dp[0]=nums[0];
//     // dp[1]=nums[1];
//     for(int i=1 ; i<nums.size() ; i++){
//         dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
//     }
//     return dp[nums.size()-1];
//     // return max(dp[nums.size()-2],dp[nums.size()-1]);
// }
int solveopt(vector<int> &nums){
    int n=nums.size();
    int prev1=0;
    int prev2=nums[0];
    // int prev2=nums[1];
    // int ans;
    for(int i=1 ; i<n ; i++){
        int ans=max(prev1+nums[i],prev2);
        prev1=prev2;
        prev2=ans;
    }
    return prev2;
}
    int rob(vector<int>& nums) {
        return solveopt(nums);
    }
};