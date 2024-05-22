class Solution {
public:
    string removeStars(string s) {
        stack<char> s1; 
        int i=0;
        while(i<s.size()){
            if(s[i]=='*'){
                if(!s1.empty()){
                    s1.pop();
                }
            }
            else{
                s1.push(s[i]);
            }
            i++;
        }
        string ans;
        while(!s1.empty()){
            ans.push_back(s1.top());
            s1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
   }
};