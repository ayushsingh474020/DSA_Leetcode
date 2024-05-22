class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int ans=2000;
        vector <pair<string,int>> answer;
        unordered_map<string,int> m1;
        for(int i=0 ; i<list1.size() ; i++){
            m1.insert(make_pair(list1[i],i));
        }
        for(int i=0 ; i<list2.size() ; i++){
            if(m1.find(list2[i])!=m1.end()){
                if(ans>=i+m1[list2[i]]){
                    ans=i+m1[list2[i]];
                    answer.push_back({list2[i],ans});
                }
            }
        }
        int min=answer[0].second;
        for(int i=0 ; i<answer.size() ; i++){
            if(min>answer[i].second){
                min=answer[i].second;
            }
        }
        vector<string> real;
        for(int i=0 ; i<answer.size() ; i++){
            if(answer[i].second==min){
                real.push_back(answer[i].first);
            }
        }
        return real;
    }
};