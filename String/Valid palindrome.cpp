class Solution {
public:
    
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(i<j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            else if(!isalnum(s[j])){
                j--;
                continue;
            }
            else{
                if(s[i]!=s[j]){
                    return 0;
                }
            }
            i++;
            j--;
        }
        return 1;

    }
};