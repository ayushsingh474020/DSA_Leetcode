vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    queue<int> q;
    q.push(0);
    unordered_map<int,int> visited;
    for(int i=0 ; i<adj.size() ; i++){
        visited[i]=0;
    }
    visited[0]=1;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        ans.push_back(top);
        for(int i=0 ; i<adj[top].size() ; i++){
            if(visited[adj[top][i]]==0){
                q.push(adj[top][i]);
                visited[adj[top][i]]=1;
            }
        }
    }
    return ans;
}