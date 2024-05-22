class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int size1=str1.size();
        int size2=str2.size();
        int minsize=min(size1,size2);
        vector<int> anssizes;
        for(int i=1 ; i<=minsize ; i++){
            if(size1%i==0 && size2%i==0){
                anssizes.push_back(i);
            }
        }
        for(int i=anssizes.size()-1 ; i>=0 ; i--){
            unordered_set<string> s1;
            unordered_set<string> s2;
            string extra1;
            int e1size=0;
            string extra2;
            int e2size=0;
            int x=0;
            while(x<size1){
                extra1.push_back(str1[x]);
                e1size++;
                if(e1size==anssizes[i]){
                    s1.insert(extra1);
                    extra1.clear();
                    e1size=0;
                }
                x++;
            }
            x=0;
            while(x<size2){
                extra2.push_back(str2[x]);
                e2size++;
                if(e2size==anssizes[i]){
                    s2.insert(extra2);
                    extra2.clear();
                    e2size=0;
                }
                x++;
            }
            if(s1.size()==1 && s2.size()==1){
                if(s1==s2){
                   return *s1.begin();
                }
                
            }
            s1.clear();
            s2.clear();

        }
        return "";
    }
};