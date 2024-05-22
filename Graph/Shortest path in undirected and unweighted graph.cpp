#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int,vector<int>> adjmap;
	unordered_map<int,int> visited;
	unordered_map<int,int> parents; 
	queue<int> q;
	for(int i=0 ; i<edges.size() ; i++){
		int u = edges[i].first;
		int v = edges[i].second;
		adjmap[u].push_back(v);
		adjmap[v].push_back(u);
	}
	for(int i=1 ; i<=n ; i++){
		visited[i]=0;
		parents[i]=-1;
	}
	q.push(s);
	visited[s]=1;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		for(int i=0 ; i<adjmap[front].size() ; i++){
			if(!visited[adjmap[front][i]]){
				q.push(adjmap[front][i]);
				visited[adjmap[front][i]]=1;
				parents[adjmap[front][i]]=front;
			}
		}
	}
	int dest=t;
	vector<int> ans;
	while(dest!=s){
		ans.push_back(dest);
		dest=parents[dest];
	}
	ans.push_back(s);
	reverse(ans.begin(),ans.end());
	return ans;
}
