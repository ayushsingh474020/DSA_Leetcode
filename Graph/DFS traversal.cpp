void dfs(int i, unordered_map<int,vector<int>> adjmap, unordered_map<int,int> &visited, vector<int> &extra){
    visited[i]=1;
    extra.push_back(i);
    for(int j=0 ; j<adjmap[i].size() ; j++){
        if(!visited[adjmap[i][j]]){
            dfs(adjmap[i][j], adjmap, visited, extra);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    unordered_map<int,vector<int>> adjmap;
    unordered_map<int,int> visited;
    for(int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjmap[u].push_back(v);
        adjmap[v].push_back(u);
    }
    for(int i=0 ; i<V ; i++){
        if(!visited[i]){
            vector<int> extra;
            dfs(i,adjmap,visited,extra);
            ans.push_back(extra);
        }
    }
    return ans;
}