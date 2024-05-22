class Solution {
public:
    string decodeString(string s) {
        stack<char> s1;
        int i=s.size()-1;
        string extra;
        while(i>=0){
            string num;
            if(s[i]==']'){
                s1.push(s[i]);
                i--;
                if(i<0){
                    break;
                }
            }
            else if(s[i]>=97 && s[i]<=122){
                s1.push(s[i]);
                i--;
                if(i<0){
                    break;
                }
            }
            else if(s[i]=='['){
                while(s1.top()!=']'){
                    extra.push_back(s1.top());
                    s1.pop();
                }
                if(s1.top()==']'){
                    s1.pop();
                }
                i--;
                if(i<0){
                    break;
                }
            }
            
            else{
                while((s[i]>=48 && s[i]<=57)){
                    num.push_back(s[i]);
                    i--;
                    if(i<0){
                        break;
                    }
                }
                reverse(num.begin(),num.end());
                int a=stoi(num);
                reverse(extra.begin(),extra.end());
                while(a--){
                    for(int x=0 ; x<extra.size() ; x++){
                        s1.push(extra[x]);
                    }
                }
                extra.clear();
            }
        }
        string ans;
        while(!s1.empty()){
            ans.push_back(s1.top());
            s1.pop();
        }
        return ans;

    }
};