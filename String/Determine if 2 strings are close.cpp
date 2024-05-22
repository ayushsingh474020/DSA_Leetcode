class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int> m1;
        map<char,int> m2;
        for(int i=0 ; i<word1.size() ; i++){
            m1[word1[i]]++;
        }
        for(int i=0 ; i<word2.size() ; i++){
            m2[word2[i]]++;
        }
        set<char> s3;
        set<char> s4;
        vector<int> s1;
        for(auto it=m1.begin() ; it!=m1.end() ; it++){
            s1.push_back((*it).second);
            s3.insert((*it).first);
        }
        vector<int> s2;
        for(auto it=m2.begin() ; it!=m2.end() ; it++){
            s2.push_back((*it).second);
            s4.insert((*it).first);
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1==s2 && s3==s4){
            return true;
        }
        return false;
    }
};