class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int max_len=1;
        int st=0;
        int end=0;
        // int count=0;
       vector<string> extra;
            for(int i=0 ; i<n ; i++){
                int l=i;
                int r=i;
                while(l>=0 && r<n){
                    if(s[l]==s[r]){
                        extra.push_back(s.substr(l,r-l-1));
                        r++;
                        l--;
                    }
                    else{
                        break;
                    }
                }
            }
            for(int i=0 ; i<n-1 ; i++){
                int l=i;
                int r=i+1;
                while(l>=0 && r<n){
                    if(s[l]==s[r]){
                        extra.push_back(s.substr(l,r-l-1));
                        r++;
                        l--;
                    }
                    else{
                        break;
                    }
                }
            }
        
        return extra.size();
    }
};