class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector <int> ans;
        int a,b;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;

        }
        
        for(auto it=m.begin() ; it!=m.end() ; it++){
            if(m[target-(*it).first]>0){
                a=target-(*it).first;
                b=(*it).first;
                break;
            }
        }
        
        auto it1 = find(nums.begin(), nums.end(), a);
        ans.push_back(it1-nums.begin());
        (*it1)++;
        auto it2 = find(nums.begin(), nums.end(), b);
        
        ans.push_back(it2-nums.begin());
        return ans;
        
    }
};