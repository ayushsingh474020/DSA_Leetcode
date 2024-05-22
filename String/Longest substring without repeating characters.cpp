class Solution {
public:
    int process(vector <int> local){
        for(int i=0 ; i<95 ; i++){
            if(local[i]>1){
                return 0;
            }
        }
        return 1;

    }
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;
        }
        int i=0;
        int j=0;
        int max=1;
        vector <int> local(95,0);
        local[s[i]-32]++;
        while(j<s.size()){
            if(j<s.size()-1){
                j++;
            }
            else{
                break;
            }
            local[s[j]-32]++;
            if(process(local)==1){
                max=j-i+1;
                
            }
            else{
                local[s[i]-32]--;
                i++;
            }
            

        }
        return max;
    }
};