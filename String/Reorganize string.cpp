class Solution {
public:
    string reorganizeString(string str) {
        unordered_map<char,int> m;
        for(int i=0 ; i<str.size() ; i++){
            m[str[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(int i='a' ; i<='z' ; i++){
            if(m[i]>0){
                if(m[i]>(str.size()+1)/2){
                    return "";
                }
                else{
                    pair<int,char> extra={m[i],i};
                    pq.push(extra);
                }
            }
        }
        string ans="";
        while(pq.size()>=2){
            pair<int,char> first=pq.top();
            pq.pop();
            pair<int,char> second=pq.top();
            pq.pop();
            first.first--;
            second.first--;
            if(first.first>0){
                pq.push(first);
            }
            if(second.first>0){
                pq.push(second);
            }
            ans+=first.second;
            ans+=second.second;
        }
        while(!pq.empty()){
            pair<int,char> extra=pq.top();
            ans+=extra.second;
            pq.pop();
        }
        return ans;
    }
};