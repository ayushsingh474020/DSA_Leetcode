class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int ans=0;
        int n=s.size()-1;
        int i=0;
        while(i<s.size()){
            if(m[s[i]]<m[s[i+1]]){
                if(s[i]=='I' && s[i+1]=='V'){
                    ans+=4;
                }
                else if(s[i]=='I' && s[i+1]=='X'){
                    ans+=9;
                }
                else if(s[i]=='X' && s[i+1]=='L'){
                    ans+=40;
                }
                else if(s[i]=='X' && s[i+1]=='C'){
                    ans+=90;
                }
                else if(s[i]=='C' && s[i+1]=='D'){
                    ans+=400;
                }
                else if(s[i]=='C' && s[i+1]=='M'){
                    ans+=900;
                }
                i+=2;
            }
            else{
                ans+=m[s[i]];
                i+=1;
            }
            
        }
        return ans;
    }
};