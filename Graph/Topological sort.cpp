#include <bits/stdc++.h> 
void dfs(int i, vector<vector<int>> adjmap, vector<int> &visited, vector<int> &ans){
    visited[i]=1;
    for(int j=0 ; j<adjmap[i].size() ; j++){
        if(!visited[adjmap[i][j]]){
            dfs(adjmap[i][j],adjmap,visited,ans);
        }
    }
    ans.push_back(i);
}
void bfskahn(vector<vector<int>> adjmap, int v, vector<int> &ans){
    vector<int> indegree(v,0);
    for(int i=0 ; i<adjmap.size() ; i++){
        for(int j=0 ; j<adjmap[i].size() ; j++){
            indegree[adjmap[i][j]]++;
        }
    }
    queue<int> q;
    for(int i=0 ; i<indegree.size() ; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    // vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(int i=0 ; i<adjmap[front].size() ; i++){
            indegree[adjmap[front][i]]--;
            if(indegree[adjmap[front][i]]==0){
                q.push(adjmap[front][i]);
            }
        }
    }
    // return ans;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    // unordered_map<int,vector<int>> adjmap;
    vector<vector<int>> adjmap;
    vector<int> visited(v,0);
    for(int i=0 ; i<v ; i++){
        vector<int> extra;
        adjmap.push_back(extra);
    }
    // unordered_map<int,int> visited;
    for(int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjmap[u].push_back(v);
    }
    for(int i=0 ; i<v ; i++){
        visited[i]=0;
    }
    for(int i=0 ; i<v ; i++){
        if(!visited[i]){
            dfs(i,adjmap,visited,ans);
        }
    }
    // reverse(ans.begin(),ans.end());
    // return ans;
    bfskahn(adjmap,v,ans);
    return ans;
}