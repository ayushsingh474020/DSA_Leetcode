class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int max_len=1;
        int st=0;
        int end=0;
        
            for(int i=0 ; i<n-1 ; i++){
                int l=i;
                int r=i;
                while(l>=0 && r<n){
                    if(s[l]==s[r]){
                        r++;
                        l--;

                    }
                    else{
                        break;
                    }
                }
                if(r-l-1>max_len){
                    max_len=r-l-1;
                    st=l+1;
                    end=r-1;
                }
            }
            for(int i=0 ; i<n-1 ; i++){
                int l=i;
                int r=i+1;
                while(l>=0 && r<n){
                    if(s[l]==s[r]){
                        r++;
                        l--;

                    }
                    else{
                        break;
                    }
                }
                if(r-l-1>max_len){
                    max_len=r-l-1;
                    st=l+1;
                    end=r-1;
                }
            }

        
        return s.substr(st,max_len);
    }
};