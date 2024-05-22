class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1, j = 1;
        int count = 1;

        while (i<n) {
            if (nums[i] == nums[i-1]) {
                if (count < 2) {
                    count++; 
                    nums[j++] = nums[i];
                }
            }
            else {
                count = 1;
                nums[j++] = nums[i];
            }

            i++;
        }

        return j;
    }
};