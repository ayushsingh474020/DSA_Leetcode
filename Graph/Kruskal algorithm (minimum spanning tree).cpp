#include <bits/stdc++.h>
#include <iostream>
bool cmp(vector<int> &a, vector<int> &b){
  return a[2]<b[2];
}
void initialise(vector<int> &parent, vector<int> &rank, int n){
  for(int i=0 ; i<n ; i++){
    parent[i]=i;
    rank[i]=0;
  }
}
int findParent(vector<int> &parent, int node){
  if(parent[node]==node){
    return node;
  }
  return parent[node]=findParent(parent,parent[node]);
}
void unionset(int u, int v, vector<int> &parent, vector<int> &rank){
  u = parent[u];
  v = parent[v];
  if(rank[u]>rank[v]){
    parent[v]=u;
  }
  else if(rank[v]>rank[u]){
    parent[u]=v;
  }
  else{
    parent[v]=u;
    rank[u]++;
  }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  sort(edges.begin(),edges.end(),cmp);
  vector<int> parent(n);
  vector<int> rank(n);
  initialise(parent,rank,n);

  int wt=0;
  for(int i=0 ; i<edges.size() ; i++){
    int u = findParent(parent,edges[i][0]);
    int v = findParent(parent,edges[i][1]);
    int weight = edges[i][2];
    if(u!=v){
      unionset(u,v,parent,rank);
      wt+=weight;
    }
  }
  return wt;

}