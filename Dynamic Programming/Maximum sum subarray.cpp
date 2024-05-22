class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=-pow(2,31);
        int cursum=0;
        int i=0;
        while(i<nums.size()){
            cursum+=nums[i];
            if(cursum>maxsum){
                maxsum=cursum;
            }
            if(cursum<0){
                cursum=0;
            }
            i++;
        }
        return maxsum;
    }
};