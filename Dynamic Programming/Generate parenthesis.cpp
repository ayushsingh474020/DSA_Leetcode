class Solution {
public:
    int okay(vector<int> flag){
        stack<int> ans;
        for(int i=0 ; i<flag.size() ; i++){
            if(flag[i]==0){
                ans.push(0);
            }
            else{
                if(ans.empty()){
                    return 0;
                }
                if(ans.top()==0){
                    ans.pop();
                }
                else{
                    return 0;
                }
            }
        }
        if(ans.empty()){
            return 1;
        }
        else{
            return 0;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string ans;
        vector <int> extra;
        for(int i=0 ; i<n ; i++){
            extra.push_back(0);
        }
        for(int i=0 ; i<n ; i++){
            extra.push_back(1);
        }
        vector<int> extra1=extra;
        next_permutation(extra.begin(),extra.end());
        while(extra!=extra1){
            next_permutation(extra.begin(),extra.end());
            if(okay(extra)){
                for(int i=0 ; i<extra.size() ; i++){
                    if(extra[i]==0){
                        ans.push_back('(');
                    }
                    else{
                        ans.push_back(')');
                    }
                }
                answer.push_back(ans);
                ans.clear();
            }
            next_permutation(extra.begin(),extra.end());
        }
        return answer;
    }
};