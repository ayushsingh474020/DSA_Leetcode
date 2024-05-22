#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool dfscycle(int i, unordered_map<int,vector<int>> adjmap, unordered_map<int,int> &visited, unordered_map<int,int> &dfsvisited){
  visited[i]=1;
  dfsvisited[i]=1;
  for(int j=0 ; j<adjmap[i].size() ; j++){
    if(!visited[adjmap[i][j]]){
      bool ans = dfscycle(adjmap[i][j],adjmap,visited,dfsvisited);
      if(ans){
        return true;
      }
    }
    else if(dfsvisited[adjmap[i][j]]){
      return true;
    }
  }
  dfsvisited[i]=0;
  return false;
}

void bfskahn(unordered_map<int,vector<int>> adjmap, int v, vector<int> &ans){
    vector<int> indegree(v+1,0);
    for(auto it = adjmap.begin() ; it!=adjmap.end() ; it++){
      for(int i= 0 ; i<it->second.size() ; i++){
        indegree[it->second[i]]++;
      }
    }
    queue<int> q;
    for(int i=1 ; i<indegree.size() ; i++){
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

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,vector<int>> adjmap;
  // unordered_map<int,int> visited;
  // unordered_map<int,int> dfsvisited;
  for(int i=0 ; i<edges.size() ; i++){
    int u = edges[i].first;
    int v = edges[i].second;
    adjmap[u].push_back(v);
  }
  // for(int i=1 ; i<=n ; i++){
  //   visited[i]=0;
  //   dfsvisited[i]=0;
  // }
  // for(int i=1 ; i<=n ; i++){
  //   if(!visited[i]){
  //     bool ans = dfscycle(i,adjmap,visited,dfsvisited);
  //     if(ans){
  //       return 1;
  //     }
  //   }
  // }
  // return 0;

  vector<int> ans;
  bfskahn(adjmap,n,ans);
  if(ans.size()==n){
    return 0;
  }
  return 1;

}