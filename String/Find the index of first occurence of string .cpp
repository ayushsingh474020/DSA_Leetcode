class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        int j=needle.size()+i-1;
        while(j<haystack.size()){
            int flag=1;
            for(int x=i ; x<=j ; x++){
                if(haystack[x]!=needle[x-i]){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                return i;
            }
            i++;
            j++;
            // if(j<haystack.size()-1){
            //     j++;
            // }
        }
        return -1;
    }
};