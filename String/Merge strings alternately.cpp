class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        string ans;
        int turn=1;
        while(i<word1.size() && j<word2.size()){
            if(turn%2==0){
                ans.push_back(word2[j]);
                j++;
            }
            else{
                ans.push_back(word1[i]);
                i++;
            }
            turn++;
        }
        while(i<word1.size()){
            ans.push_back(word1[i]);
            i++;
        }
        while(j<word2.size()){
            ans.push_back(word2[j]);
            j++;
        }
        return ans;
    }
};