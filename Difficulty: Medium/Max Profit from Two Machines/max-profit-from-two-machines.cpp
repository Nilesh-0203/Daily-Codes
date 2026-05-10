class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        vector<pair<int,int>>vec;
        for(int i = 0 ;i<n ; i++){
            vec.push_back({a[i] - b[i] , i});
        }
        sort(vec.begin() , vec.end() , greater());
        int res = 0 , i=0;
        for(;i<x ; i++){
            if(vec[i].first<0 && n-i <=y)break;
            res+= a[vec[i].second];
        }
        for(;i<n ; i++)res+= b[vec[i].second];
        
        return res;
    }
};