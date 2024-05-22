class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_set<char> s1;
        unordered_map<string,char> m;
        string extra;
        int j=0;
        int spacecount=0;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]==' '){
                spacecount++;
            }
        }
        if(spacecount+1!=pattern.size()){
            return false;
        }
        for(int i=0 ; i<s.size() ; i++){
            // if(spacecount==0){
            //     break;
            // }
            if(s[i]!=' '){
                extra.push_back(s[i]);
            }
            else{
                if(m.find(extra)!=m.end()){
                    cout<<extra<<endl;
                    if(m[extra] != pattern[j]){
                        return false;
                    }
                }
                else{
                    cout<<extra<<endl;
                    if(s1.find(pattern[j])!=s1.end()){
                        return false;
                    }
                    m[extra]=pattern[j];
                    s1.insert(pattern[j]);

                }
                j++;
                extra.erase();
            }
        }
        extra.erase();
        int i=s.size()-1;
        while(s[i]!=' '){
            extra.push_back(s[i]);
            i--;
            if(i<0){
                break;
            }
        }
        reverse(extra.begin(),extra.end());
        if(m.find(extra)!=m.end()){
            cout<<extra<<endl;
            if(m[extra] != pattern[j]){
                return false;
            }
        }
        else{
            cout<<extra<<endl;
            if(s1.find(pattern[j])!=s1.end()){
                return false;
             }
             m[extra]=pattern[j];
            s1.insert(pattern[j]);

        }
        return true;
    }
};