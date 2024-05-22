class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=0;
        int n=nums.size();
        int i=0;
        int j=i+k-1;
        for(int x=i ; x<=j ; x++){
            ans+=nums[x];
        }
        double sum=ans;
        ans=ans/k;
        while(j<n){
            sum-=nums[i];
            i++;
            j++;
            if(j<n){
                sum+=nums[j];
            }
            else{
                break;
            }
            if(ans<=(sum/k)){
                ans=sum/k;
            }

        }
        return ans;
    }
};