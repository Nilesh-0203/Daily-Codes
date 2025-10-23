class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        
        priority_queue<pair<double,pair<int,int>>>pq;
        
        for(auto p:points){
            int x=p[0];
            int y=p[1];
            
             double d=(double)sqrt(x*x+y*y);
             
             pq.push({d,{x,y}});
             
             if(pq.size()>k){
                 pq.pop();
             }
        }
        
        
        
        vector<vector<int>>res;
        
        while(!pq.empty()){
            res.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        
        return res;
    }
};