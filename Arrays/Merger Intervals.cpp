class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort(intervals.begin(),intervals.end());
        // vector <vector<int>> ans;
        // int j=0;
        // vector <int> universal=intervals[j];
        // for(int i=j+1 ; i<intervals.size() ; i++){
        //     if(intervals[i][0]<=universal[1]){
        //         if(universal[1]<intervals[i][1]){
        //             universal[1]=intervals[i][1];
        //         }
        //     }
        //     else{
        //         ans.push_back(universal);
        //         universal=intervals[i];
        //     }
        // }
        // ans.push_back(universal);
        // return ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0 ; i<intervals.size() ; i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        }
        vector<vector<int>> ans;
        int i=0;
        vector<int> extra;
        while(i<intervals.size()){
            // vector<int> extra;
            extra.push_back(intervals[i][0]);
            int last=intervals[i][1];
            if(i!=intervals.size()-1){
                while(last>=intervals[i+1][0]){
                    i++;
                    if(intervals[i][1]>last){
                        last=intervals[i][1];
                    }
                    if(i+1>=intervals.size()){
                        break;
                    }
                }
            }
            // if(last<intervals[i][1]){
            //     extra.push_back(intervals[i][1]);
            // }
            // else{
            //     extra.push_back(last);
            // }
            extra.push_back(last);
            ans.push_back(extra);
            extra.clear();
            i++;
        }
        return ans;
        
    }
};