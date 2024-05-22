class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <string> process=strs;
        
        map<string,vector<string>> indices;
        for(int i=0 ; i<process.size() ; i++){
            sort(process[i].begin(),process[i].end());
        }
        for(int i=0 ; i<process.size() ; i++){
            indices[process[i]].push_back(strs[i]);

        }
        vector<vector<string>> ans;
        for(auto it=indices.begin() ; it!=indices.end() ; it++){
            ans.push_back((*it).second);
        }
        return ans;
        
        

    }
};