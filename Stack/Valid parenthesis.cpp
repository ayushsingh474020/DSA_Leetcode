class Solution {
public:
    bool isValid(string s) {
        int flag=1;
        stack<char> ans;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='[' || s[i]=='(' || s[i]=='{'){
                ans.push(s[i]);
            }
            else if(s[i]==']'){
                if(!ans.empty() && ans.top()=='['){
                    ans.pop();
                }
                else{
                    flag=0;
                    break;
                }
            }
            else if(s[i]=='}'){
                if(!ans.empty() && ans.top()=='{'){
                    ans.pop();
                    continue;
                }
                else{
                    flag=0;
                    break;
                }
            }
            else if(s[i]==')'){
                if(!ans.empty() && ans.top()=='('){
                    ans.pop();
                    continue;
                }
                else{
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0 || !ans.empty()){
            return 0;
        }
        return 1;
        
    }
};