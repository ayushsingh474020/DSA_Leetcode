class Solution {
public:
    int solverec(vector<int> &num, int x){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    int mini=INT_MAX;
    for(int i=0 ; i<num.size() ; i++){
        int ans=solverec(num,x-num[i]);
        if(ans!=INT_MAX){
            mini=min(mini,1+ans);
        }
    }
    return mini;
}
// int solvemem(vector<int> &num, vector<int> &dp, int x){
//     if(x==0){
//         dp[x]=0;
//         return 0;
//     }
//     if(x<0){
//         return INT_MAX;
//     }
//     if(dp[x]!=-1){
//         return dp[x];
//     }
//     int mini=INT_MAX;
//     for(int i=0 ; i<num.size() ; i++){
//         int ans=solvemem(num,dp,x-num[i]);
//         if(ans!=INT_MAX){
//             mini=min(mini,1+ans);
//         }
//     }
//     dp[x]=mini;
//     return mini;
// }
int solvetab(vector<int> num, int x){
    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=1 ; i<=x ; i++){
        for(int j=0 ; j<num.size() ; j++){
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-num[j]]);
            }
            
        }
    }
    if(dp[x]==INT_MAX){
        return -1;
    }
    return dp[x];
}
    int coinChange(vector<int>& coins, int amount) {
        return solvetab(coins,amount);
    }
};