#include <bits/stdc++.h> 
typedef pair<int, int> pi;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,vector<pair<int,int>>> adjmap;
    for(int i=0 ; i<vec.size() ; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int dist = vec[i][2];
        adjmap[u].push_back({v,dist});
        adjmap[v].push_back({u,dist});
    }
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pq.push({0,source});
    vector<int> distance(vertices,INT_MAX);
    distance[source]=0;
    while(!pq.empty()){
        pair<int,int> extra = pq.top();
        pq.pop();
        for(int i=0 ; i<adjmap[extra.second].size() ; i++){
            int curdistance = extra.first + adjmap[extra.second][i].second;
            if(curdistance<distance[adjmap[extra.second][i].first]){
                distance[adjmap[extra.second][i].first]=curdistance;
                pq.push({curdistance,adjmap[extra.second][i].first});
            }
        }
    }
    return distance;
}
