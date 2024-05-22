class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        ans[0]=0;
        int j=0;
        for(int i=1 ; i<=n ; i++){
            if(i==pow(2,j)){
                ans[i]=1;
                j++;
            }
            else{
                ans[i]=ans[pow(2,j-1)]+ans[i-pow(2,j-1)];
            }
        }
        return ans;
    }
};