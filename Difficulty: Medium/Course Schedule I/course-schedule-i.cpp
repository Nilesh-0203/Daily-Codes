class Solution {
  public:
     bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>graph(n);
        
        vector<int>indegree(n,0);
        
        for(auto course: prerequisites) { 
            
            graph[course[0]].push_back(course[1]);
            indegree[course[1]]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        int cnt=0;
        while(!q.empty()){
            
              int node = q.front();
              q.pop();
              cnt++;

              for(auto it:graph[node]){
                  indegree[it]--;
                  if(indegree[it]==0){
                   
                      q.push(it);
                  }
              }
        
        }
        return cnt==n;
        
    }
};