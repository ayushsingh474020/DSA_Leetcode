class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector <vector<int>> ans;
        int j=0;
        vector <int> universal=intervals[j];
        for(int i=j+1 ; i<intervals.size() ; i++){
            if(intervals[i][0]<=universal[1]){
                if(universal[1]<intervals[i][1]){
                    universal[1]=intervals[i][1];
                }
                
                
            }
            else{
                ans.push_back(universal);
                universal=intervals[i];
            }
        }
        ans.push_back(universal);
        return ans;
        
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> ans=merge(intervals);
        return ans;


    }
};