class Solution {
public:
    bool isSubsequence(string s, string t){
        if(s.size()==0){
            return 1;
        }
        int count=0;
        int i=0;
        int j=0;
        while(j<t.size()){
            if(t[j]==s[i]){
                i++;
                count++;
                if(count==s.size()){
                    return 1;
                }
            }
            j++;
        }
        return 0;
    }
    
};