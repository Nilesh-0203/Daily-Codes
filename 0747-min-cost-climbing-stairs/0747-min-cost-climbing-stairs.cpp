class Solution {
public:
    int t[1001];
    int solve(int i,vector<int>&cost){
        if(i>=cost.size()){
            return 0;
        }
        
        if(t[i]!=-1){
            return t[i];
        }

        int take=cost[i]+solve(i+1,cost);
        int ntake=cost[i]+solve(i+2,cost);

        return t[i]= min(take,ntake);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int sum=0;
        memset(t,-1,sizeof(t));
        return min(solve(0,cost),solve(1,cost));
    }
};