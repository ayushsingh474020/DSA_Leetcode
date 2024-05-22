class Solution {
public:
    string reverseWords(string s){
        int n=s.size();
        int i=n-1;
        int flag=0;
        string ans; 
        while(i>=0){
            string str;
            while(s[i]==' '){
                if(i>0){
                    i--;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
            while(s[i]!=' '){
                str.push_back(s[i]);
                if(i>0){
                    i--;
                }
                else{
                    flag=1;
                    break;
                }
            }
            reverse(str.begin(),str.end());
            ans+=str; 
            if(flag==1){
                break;
            } 
            ans.push_back(' ');
        }
        if(ans[ans.size()-1]==' '){
            ans.pop_back();
        }
        return ans;
    }
};