class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3){
            return false;
        }
        int i=0;
        long long int left=pow(2,31);
        long long int mid=left;
        while(i<nums.size()){
            if(nums[i]<=left){
                left=nums[i];
            }
            else if(nums[i]<=mid){
                mid=nums[i];
            }
            else{
                return true;
            }
            i++;
        }
        return false;
    }
};