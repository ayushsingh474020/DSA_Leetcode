class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int easter=0;
        if(accumulate(nums.begin()+1,nums.end(),0)==0){
            return 0;
        }
        if(accumulate(nums.begin(),nums.end()-1,0)==0){
            easter=1;
        }
        
        for(int i=1 ; i<nums.size() ; i++){
            nums[i]+=nums[i-1];
        }
        int pos=-1;
        for(int i=1 ; i<nums.size()-1 ; i++){
            if(nums[i-1]==nums[nums.size()-1]-nums[i]){
                pos=i;
                break;
            }
        } 
        if(pos==-1){
            if(easter==1){
                return nums.size()-1;
            }
        }
        return pos;
        
    }
};