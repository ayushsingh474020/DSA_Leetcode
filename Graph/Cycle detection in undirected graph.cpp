#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool cycleBFS(int x,unordered_map<int,vector<int>> adjmap, unordered_map<int,int> &visited, unordered_map<int,int> &parent) {
    queue<int> q;
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int i=0 ; i<adjmap[front].size() ; i++){
            if(!visited[adjmap[front][i]]){
                q.push(adjmap[front][i]);
                visited[adjmap[front][i]]=1;
                parent[adjmap[front][i]]=front;
            }
            else if(visited[adjmap[front][i]] && parent[front]!=adjmap[front][i]){
                return true;
            }
        }
    }
    return false;
}
bool cycleDFS(int x, unordered_map<int,vector<int>> adjmap, unordered_map<int,int> &visited, int parent) {
    visited[x]=1;
    for(int i=0 ; i<adjmap[x].size() ; i++){
        if(!visited[adjmap[x][i]]){
            bool ans = cycleDFS(adjmap[x][i],adjmap,visited,x);
            if(ans){
                return true;
            }
        }
        else if(visited[adjmap[x][i]] && parent!=adjmap[x][i]){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,int> parent;
    unordered_map<int,vector<int>> adjmap;
    for(int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjmap[u].push_back(v);
        adjmap[v].push_back(u);
    }
    unordered_map<int,int> visited;
    for(int i=1 ; i<=n ; i++){
        parent[i]=-1;
        visited[i]=0;
    }
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            // bool ans = cycleBFS(i,adjmap,visited,parent);
            bool ans = cycleDFS(i,adjmap,visited,-1);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";
}
