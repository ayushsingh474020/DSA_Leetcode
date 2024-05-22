class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        int count=0;
        while(s[i]==' '){
            i--;
        }
        while(s[i]!=' '){
            count++;
            if(i>0){
                i--;
            }
            else{
                break;
            }
        }
        return count;
    }
};