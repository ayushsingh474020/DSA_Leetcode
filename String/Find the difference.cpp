class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(t.size()==1){
            return t[0];
        }
        int i=0;
        while(i<s.size()){
            if(s[i]!=t[i]){
                return t[i];
            }
            i++;
        }
        return t[t.size()-1];
    }
};