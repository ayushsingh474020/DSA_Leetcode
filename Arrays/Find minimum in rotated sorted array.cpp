class Solution {
public:
    int process(vector <int> nums){
        int low=0;
        int high=nums.size()-1;
        int mid;
        int ans=nums[high];
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==nums[low] || nums[mid]==nums[high]){
                return ans;
            }
            if(nums[mid]<ans){
                ans=nums[mid];
            }
            if(nums[mid]>nums[low]){
                low=mid;
            }
            else if(nums[mid]<nums[low]){
                high=mid;
            }
            

        }
        return ans;
    } 
    int findMin(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2 && nums[1]<nums[0]){
            return nums[1];
        }
        if(nums[0]<nums[nums.size()-1]){
            return nums[0];
        }
        else{
            return process(nums);
        }
    }
};