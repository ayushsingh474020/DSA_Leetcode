class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string str;
        int i=0;
        while(i<nums.size()){
            if(str.empty()){
                cout<<i<<endl;
                str=str+to_string(nums[i]);
                i++;
                if(i>=nums.size()){
                    ans.push_back(str);
                }
            }
            else{
                while(nums[i]==nums[i-1]+1){
                    i++;
                    if(i>=nums.size()){
                        break;
                    }
                }
                if(str!=to_string(nums[i-1])){
                    str=str+"->";
                    str=str+to_string(nums[i-1]);
                }
                ans.push_back(str);
                str.erase();
            }
        }
        return ans;
    }
};