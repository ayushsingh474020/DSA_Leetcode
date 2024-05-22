class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int j=0;
        int max=0;
        while(j<prices.size()){
            if(j<prices.size()-1){
                j++;
            }
            else{
                break;
            }
            if(prices[j]-prices[i]<=0){
                i=j;
            }
            else{
                if(prices[j]-prices[i]>max){
                    max=prices[j]-prices[i];
                }
            }
        }
        return max;
    }
};