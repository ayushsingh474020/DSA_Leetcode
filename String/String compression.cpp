class Solution {
public:
    int compress(vector<char>& chars) {
        int ans=0;
        int n=chars.size();
        int i=0;
        if(n==1){
            return 1;
        }
        while(i<n){
            int count=0;
            char ch=chars[i];
            while(chars[i]==ch){
                count++;
                if(i+1<n && chars[i+1]==ch){
                    i++;
                }
                else{
                    break;
                }
            }
            if(count==1){
                chars.push_back(chars[i]);
                ans++;
            }
            else{
                chars.push_back(chars[i]);
                ans++;
                string str=to_string(count);
                for(int i=0 ; i<str.size() ; i++){
                    chars.push_back(str[i]);
                }
                ans+=str.size();
            }
            i++;
        }
        reverse(chars.begin(),chars.end());
        while(n--){
            chars.pop_back();
        }
        reverse(chars.begin(),chars.end());
        return ans;

    }
};