class Solution {
public:
    string reverseVowels(string s) {
        set<char> s1={'a','e','i','o','u','A','E','I','O','U'};
        int i=0;
        int j=s.size()-1;
        while(1){
            while(s1.find(s[i])==s1.end()){
                i++;
                if(i>=s.size()){
                    break;
                }
            }
            if(i>=j){
                break;
            }
            while(s1.find(s[j])==s1.end()){
                j--;
                if(j<0){
                    break;
                }
            }
            if(i>=j){
                break;
            }
            char ch=s[i];
            s[i]=s[j];
            s[j]=ch;
            i++;
            if(i>=s.size()){
                break;
            }
            j--;
            if(j<0){
                break;
            }
        }
        return s;
    }
};