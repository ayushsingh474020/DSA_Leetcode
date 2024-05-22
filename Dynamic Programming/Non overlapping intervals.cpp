class Solution {
public:
    static bool sortbyCond(const vector<int>& a,
                const vector<int>& b)
{
    // if (a.first != b.first)
    //     return (a.first < b.first);
    // else
       return (a[1] < b[1]);
}
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        // set<pair<int,int>> s;
        // for(int i=0 ; i<intervals.size() ; i++){
        //     int a=intervals[i][0];
        //     int b=intervals[i][1];
        //     s.insert({a,b});
        // }
        // int ans=intervals.size()-s.size();
        // vector<pair<int,int>> arr;
        // for(auto it=s.begin() ; it!=s.end() ; it++){
        //     arr.push_back(*it);
        // }
        // for(int i=0 ; i<intervals.size() ; i++){
        //     int a=intervals[i][0];
        //     int b=intervals[i][1];
        //     arr.push_back({a,b});
        // }
        int ans=0;
        sort(arr.begin(),arr.end(),sortbyCond);
        int i=0;
        int j=1;
        while(j<arr.size()){
            j=i+1;
            while(j<arr.size() && arr[i][1]>arr[j][0]){
                j++;
                ans++;
            }
            i=j;
        }
        return ans;
    }
};