class Solution {
public:
    string process(string num1, string num2){
        string ans;
        int carry=0;
        for(int i=num1.size()-1 ; i>=0 ; i--){
            if(num1[i]+num2[i]+carry-96<=9){
                ans.push_back((num1[i]+num2[i]+carry-48));
                carry=0;

            }
            else{
                ans.push_back((num1[i]+num2[i]+carry-96)%10+48);
                carry=(num1[i]+num2[i]+carry-96)/10;
            }
        }
        if(carry>0){
            ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string addStrings(string num1, string num2) {
        if(num1.size()>num2.size()){
            reverse(num2.begin(),num2.end());
            int len=num1.size()-num2.size();
            for(int i=0 ; i<len ; i++){
                num2.push_back('0');
            }
            reverse(num2.begin(),num2.end());
        }
        else{
            reverse(num1.begin(),num1.end());
            int len=num2.size()-num1.size();
            for(int i=0 ; i<len ; i++){
                num1.push_back('0');
            }
            reverse(num1.begin(),num1.end());;
        }
        string ans;
        ans=process(num1,num2);
        return ans;

    }
};