class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n=gas.size();
        int gasSum=accumulate(gas.begin(),gas.end(),0);
        int costSum=accumulate(cost.begin(),cost.end(),0);

        if(gasSum<costSum){
            return -1;
        }
        int total=0;
        int resultIndex=0;
        for(int i=0;i<n;i++){
            total+=gas[i]-cost[i];
            if(total<0){
                total=0;
                resultIndex=i+1;
            }
        }
        return resultIndex;
    }
};