class Solution {
public:
    bool canJump(vector<int>& nums) {
        int j=1;
        int i=0;
        int steps=0;
        int zeroi=-1;
        while(i<nums.size()-1){
            i+=nums[i];
            steps++;
            if(i>=nums.size()-1){
                break;
            }
            if(steps>nums.size()){
                return false;
            }
            if(nums[i]==0){
                if(zeroi==-1){
                    zeroi=i;
                    i-=j;
                    if(i<0){
                        return false;
                    }
                    j++;
                }
                else if(zeroi==i){
                    i-=j;
                    if(i<0){
                        return false;
                    }
                    j++;
                }
                else if(zeroi!=i){
                    j=1;
                    zeroi=i;
                    i-=j;
                    if(i<0){
                        return false;
                    }
                    j++; 
                }
                // else if(zeroi<i){
                //     zeroi=i;
                //     i-=j;
                //     if(i<0){
                //         return false;
                //     }
                //     j++; 
                // }
            }
            else if(nums[i]!=0){
                j=1;
            }
        }
        return true;
    }
};