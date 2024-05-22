class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        vector<int> extra={-1,n,n+1};
        int i=0;
        int j=0;
        int sum=nums[i];
        while(j<n){
            if(sum<target){
                j++;
                if(j>=n){
                    break;
                }
                sum+=nums[j];
            }
            else if(sum>=target){
                if(j-i+1<extra[2]){
                    extra[0]=i;
                    extra[1]=j;
                    extra[2]=j-i+1;
                }
                if(i!=j){
                    sum-=nums[i];
                    i++;
                }
                else{
                    i++;
                    j++;
                    if(j>=n){
                        break;
                    }
                    sum=nums[i];
                }
            }
            // else{
            //     if(i!=j){
            //         sum-=nums[i];
            //         i++;
            //     }
            //     else{
            //         i++;
            //         j++;
            //         if(j>=n){
            //             break;
            //         }
            //         sum=nums[i];
            //     }
            // }
        }
        if(extra[2]==nums.size()+1){
            return 0;
        }
        return extra[2];
    }
};