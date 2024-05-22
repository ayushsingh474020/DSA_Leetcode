class Solution {
public:
    static bool cmp(pair<int, int>& a,pair<int, int>& b)
    {
        return a.second > b.second;
    }  
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;
        }
        vector <int> ans;
        vector <pair<int,int>> v;
        for(auto it=m.begin() ; it!=m.end() ; it++){
            v.push_back(make_pair(((*it).first),((*it).second)));
        }
        sort(v.begin(),v.end(),cmp);
        int i=0;
        while(k>0){
            ans.push_back(v[i].first);
            i++;
            k--;
        }
        return ans;
    }
};