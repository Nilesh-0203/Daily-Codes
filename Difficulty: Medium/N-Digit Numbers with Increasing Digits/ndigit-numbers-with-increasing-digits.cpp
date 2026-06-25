class Solution {
  public:
    vector<int> solve(int n){
        if(n==1){
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        }
        
        vector<int>tmp=solve(n-1);
        vector<int>ans;
        for(auto &it:tmp){
            for(int i=1; i<=9; i++){
                if(it==0 || (it%10)>=i) continue;
                ans.push_back(it*10+i);
            }
        }
        return ans;
    }
  
    vector<int> increasingNumbers(int n) {
        // code here
        return solve(n);
    }
};