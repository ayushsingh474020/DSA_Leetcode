class Solution {
public:
int binary(vector <int> nums,int low, int high, int target){
    if(low<=high){
        int mid=(high+low)/2;
        if(target==nums[mid]){
            return mid;
        }
        else if(target>nums[mid]){
            return binary(nums,mid+1,high,target);
        }
        else{
            return binary(nums,low,mid-1,target);
        }
    }
    return -1;
}
    int process(vector <int> nums){
        int low=0;
        int high=nums.size()-1;
        int mid;
        int ans=nums[high];
        int ansindi=high;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==nums[low] || nums[mid]==nums[high]){
                return ansindi;
            }
            if(nums[mid]<ans){
                ans=nums[mid];
                ansindi=mid;
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
            return 0;
        }
        if(nums.size()==2 && nums[1]<nums[0]){
            return 1;
        }
        if(nums[0]<nums[nums.size()-1]){
            return 0;
        }
        else{
            return process(nums);
        }
    }
    int search(vector<int>& nums, int target) {
        int indi=findMin(nums);
        int a=binary(nums,indi,nums.size()-1,target);
        int b=binary(nums,0,indi,target);
        if(a==-1 && b==-1){
            return -1;
        }
        else{
            if(a!=-1){
                return a;
            }
            else{
                return b;
            }
        }

    }
};