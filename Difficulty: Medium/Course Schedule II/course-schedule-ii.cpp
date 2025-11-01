class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        // code here
        vector<int>ans;
        vector<int>indegree(n,0);
        unordered_map<int,list<int>>adj;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto neighbor:adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        if(ans.size()!=n){
            return {};
        }
        return ans;
    }
};