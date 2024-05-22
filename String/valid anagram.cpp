class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1=s.size();
        int len2=t.size();
        map <char,int> m;
        for(int i=0 ; i<len1 ; i++){
            m[s[i]]++;

        }
        for(int i=0 ; i<len2 ; i++){
            m[t[i]]--;
        }
        for(auto it=m.begin() ; it!=m.end() ; it++){
            if((*it).second!=0){
                return false;
            }
        }
        return true;
    }
};