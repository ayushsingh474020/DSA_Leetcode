class Solution {
public:
    string addBinary(string a, string b) {
        int maxsize=max(a.size(),b.size());
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        while(b.size()<maxsize){
            b.push_back('0');
        }
        while(a.size()<maxsize){
            a.push_back('0');
        }
        string ans;
        int carry=0;
        for(int i=0 ; i<a.size() ; i++){
            if(a[i]=='1' && b[i]=='1'){
                if(carry==0){
                    ans.push_back('0');
                    carry=1;
                }
                else{
                    ans.push_back('1');
                    carry=1;
                }
            }
            else if(a[i]=='0' && b[i]=='0'){
                if(carry==0){
                    ans.push_back('0');
                    carry=0;
                }
                else{
                    ans.push_back('1');
                    carry=0;
                }
            }
            else{
                if(carry==0){
                    ans.push_back('1');
                    carry=0;
                }
                else{
                    ans.push_back('0');
                    carry=1;
                }
            }
        }
        if(carry==1){
            ans.push_back('1');
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};