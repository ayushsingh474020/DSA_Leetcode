
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> temp;
        for(int i=0 ; i<nums.size() ; i++){
            int t=-nums[i];
            int x=i+1;
            int j=nums.size()-1;
            while(x<j){
                if(nums[x]+nums[j]>t){
                   j--;
                }
                else if(nums[x]+nums[j]<t){
                    x++;
                }
                else{
                    temp.push_back(nums[i]);
                    temp.push_back(nums[x]);
                    temp.push_back(nums[j]);
                    s.insert(temp);
                    temp.clear();
                    x++;
                    j--;
                }
            }
        }
        for(auto it=s.begin() ; it!=s.end() ; it++){
            ans.push_back(*it);
        }
        return ans;
    }
};