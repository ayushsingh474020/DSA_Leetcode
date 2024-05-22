vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<vector<int>> ans;
    for(int i=0 ; i<n ; i++){
        vector<int> extra;
        extra.push_back(i);
        ans.push_back(extra);
    }
    for(int i=0 ; i<m ; i++){
        int n1=edges[i][0];
        int n2=edges[i][1];
        ans[n1].push_back(n2);
        ans[n2].push_back(n1);
    }
    return ans;
}