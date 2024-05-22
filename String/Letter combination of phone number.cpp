class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map <char,vector<string>> m;
        m['2']={"a","b","c"};
        m['3']={"d","e","f"};
        m['4']={"g","h","i"};
        m['5']={"j","k","l"};
        m['6']={"m","n","o"};
        m['7']={"p","q","r","s"};
        m['8']={"t","u","v"};
        m['9']={"w","x","y","z"};
        if(digits.size()==0){
            return ans;
        }
        else if(digits.size()==1){
            ans=m[digits[0]];
        }
        else if(digits.size()==2){
            for(int i=0 ; i<m[digits[0]].size() ; i++){
                for(int j=0 ; j<m[digits[1]].size() ; j++){
                    string str;
                    str=str+(m[digits[0]][i]);
                    str=str+(m[digits[1]][j]);
                    ans.push_back(str);
                }
            }
        }
        else if(digits.size()==3){
            for(int i=0 ; i<m[digits[0]].size() ; i++){
                for(int j=0 ; j<m[digits[1]].size() ; j++){
                    for(int x=0 ; x<m[digits[2]].size() ; x++){
                        string str;
                        str=str+(m[digits[0]][i]);
                        str=str+(m[digits[1]][j]);
                        str=str+(m[digits[2]][x]);
                        ans.push_back(str);
                    }
                }
            }
        }
        else if(digits.size()==4){
            for(int i=0 ; i<m[digits[0]].size() ; i++){
                for(int j=0 ; j<m[digits[1]].size() ; j++){
                    for(int x=0 ; x<m[digits[2]].size() ; x++){
                        for(int y=0 ; y<m[digits[3]].size() ; y++){
                            string str;
                            str=str+(m[digits[0]][i]);
                            str=str+(m[digits[1]][j]);
                            str=str+(m[digits[2]][x]);
                            str=str+(m[digits[3]][y]);
                            ans.push_back(str);
                        }
                    }
                }
            }

        }
        
        return ans;
        
    }
};