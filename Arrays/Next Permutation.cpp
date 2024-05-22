class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakpoint=-1;;
        for(int i=nums.size()-1 ; i>=1 ; i--){
            if(nums[i]>nums[i-1]){
                breakpoint=i-1;
                break;
            }
        }
        if(breakpoint==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int min=nums[breakpoint+1];
        int minindi=breakpoint+1;
        for(int i=breakpoint+2 ; i<nums.size() ; i++){
            if(nums[i]<=min && nums[i]>nums[breakpoint]){
                min=nums[i];
                minindi=i;
            }
        }
        int a=nums[breakpoint];
        nums[breakpoint]=min;
        nums[minindi]=a;
        reverse(nums.begin()+breakpoint+1,nums.end());



    }
};