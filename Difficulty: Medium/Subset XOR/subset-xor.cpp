class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        vector<int>ans;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=sum^i;
        }
        int req=abs(n-sum);
        for(int i=1;i<=n;i++){
            if(i!=req) ans.push_back(i);
        }
        return ans;
    }
};
