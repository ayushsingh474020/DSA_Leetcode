class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int one=1,two=1;
        for(int i=0 ; i<nums.size()-1 ; i++){
            if(nums[i]>nums[i+1]){
                one=0;
                break;
            }
        }
        for(int i=0 ; i<nums.size()-1 ; i++){
            if(nums[i]<nums[i+1]){
                two=0;
                break;
            }
        }
        if(one || two){
            return 1;
        }
        return 0;
    }
};