class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>> extra;
        for(int i=0 ; i<26 ; i++){
            pair<int,int> p={s.size()+1,0};
            extra.push_back(p);
        }
        for(int i=0 ; i<s.size() ; i++){
            if(extra[s[i]-97].first>i){
                extra[s[i]-97].first=i;
            }
            extra[s[i]-97].second++;

        }
        int ans=s.size()+1;
        for(int i=0 ; i<26 ; i++){
            if(extra[i].second==1){
                if(ans>extra[i].first){
                    ans=extra[i].first;
                }
            }
        }
        if(ans==s.size()+1){
            return -1;
        }
        return ans;
        
    }
};