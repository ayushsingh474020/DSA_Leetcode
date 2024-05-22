class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> ans;
        for(int i=0 ; i<tokens.size() ; i++){
            if(tokens[i]=="+"){
                int a=ans.top();
                ans.pop();
                int b=ans.top();
                ans.pop();
                int c=b+a;
                ans.push(c);
            }
            else if(tokens[i]=="-"){
                int a=ans.top();
                ans.pop();
                int b=ans.top();
                ans.pop();
                int c=b-a;
                ans.push(c);
            }
            else if(tokens[i]=="*"){
                int a=ans.top();
                ans.pop();
                int b=ans.top();
                ans.pop();
                int c=a*b;
                ans.push(c);
            }
            else if(tokens[i]=="/"){
                int a=ans.top();
                ans.pop();
                int b=ans.top();
                ans.pop();
                int c=b/a;
                ans.push(c);
            }
            else{
                int a=stoi(tokens[i]);
                ans.push(a);
            }
        }
        return ans.top();
    }
};