class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        int n=columnTitle.size();
        for(int i=0 ; i<columnTitle.size() ; i++){
            ans+=(int(columnTitle[i]-64))*pow(26,n-1);
            n--;
        }
        return ans;
    }
};