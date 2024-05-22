#include <bits/stdc++.h>
int findmin(vector<int> key, vector<int> mst){
    int maxi = INT_MAX;
    int indi;
    for(int i=1 ; i<key.size() ; i++){
        if(maxi>key[i] && mst[i]==0){
            maxi=key[i];
            indi = i;
        }
    }
    // cout<<maxi<<" "<<indi<<endl;
    return indi;
} 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,vector<pair<int,int>>> adjmap;
    for(int i=0 ; i<g.size() ; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int dist = g[i].second;
        adjmap[u].push_back({v,dist});
        adjmap[v].push_back({u,dist});
    }
    vector<int> key(n+1,INT_MAX);
    vector<int> mst(n+1,0);
    vector<int> parent(n+1,-1);
    key[1]=0;
    for(int i=0 ; i<n ; i++){
        int indi = findmin(key,mst);
        mst[indi]=1;
        for(int j=0 ; j<adjmap[indi].size() ; j++){
            if(adjmap[indi][j].second<key[adjmap[indi][j].first] && mst[adjmap[indi][j].first]==0){
                key[adjmap[indi][j].first]=adjmap[indi][j].second;
                parent[adjmap[indi][j].first]=indi;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2 ; i<parent.size() ; i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}
