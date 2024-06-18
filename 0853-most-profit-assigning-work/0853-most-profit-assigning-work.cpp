class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int k=worker.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i]={difficulty[i],profit[i]};
        }
        int profitt=0;
        for(int i=0;i<k;i++){
           int maxi=0;
           for(int j=0;j<n;j++){
            if(worker[i]>=v[j].first){
                maxi=max(maxi,v[j].second);
             }
           }
           profitt+=maxi;
        }
        return profitt;
    }
};