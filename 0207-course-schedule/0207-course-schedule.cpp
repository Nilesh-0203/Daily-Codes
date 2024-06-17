class Solution {
public:
    bool dfsCycle(int node,unordered_map<int,bool>&dfsVisited,unordered_map<int,bool>&visited,
    unordered_map<int,list<int>>&adj){
        visited[node]=true;
        dfsVisited[node]=true;
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                bool cycle=dfsCycle(neighbor,dfsVisited,visited,adj);
                if(cycle){
                    return true;
                }
            }
            else if(dfsVisited[neighbor]){
                return true;
            }
        }
        dfsVisited[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool cycle=dfsCycle(i,dfsVisited,visited,adj);
                if(cycle){
                    return false;
                }
            }
        }
        return true;
    }
};