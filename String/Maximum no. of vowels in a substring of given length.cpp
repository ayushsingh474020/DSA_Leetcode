class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int i=0;
        int j=i+k-1;
        int ans=0;
        for(int x=i ; x<=j ; x++){
            if(s[x]=='a' || s[x]=='e' || s[x]=='i' || s[x]=='o' || s[x]=='u'){
                ans++;
            }
        }
        int count=ans;
        while(j<n){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                count--;
            }
            i++;
            j++;
            if(j<n){
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                    count++;
                }
            }
            else{
                break;
            }
            if(count>ans){
                ans=count;
            }
            
        }
        return ans;
    }
};