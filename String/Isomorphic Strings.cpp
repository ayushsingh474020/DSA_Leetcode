class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_set<char> s1;
        unordered_map<char,char> m;
        for(int i=0 ; i<s.size() ; i++){
            if(m.find(s[i])!=m.end()){
                if(m[s[i]]!=t[i]){
                    return 0;
                }
            }
            else{
                if(s1.find(t[i])!=s1.end()){
                    return 0;
                }
                m[s[i]]=t[i]; 
                s1.insert(t[i]);
                
            }
        }
        return 1;
    }
};