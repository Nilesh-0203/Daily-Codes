class Solution {
  public:
      string solve(int num ,int n){
        string ans;
        while(num>0){
            ans.push_back('0'+(num%2));
            num/=2;
        }
        reverse(ans.begin(), ans.end()); // fix order
        //for leading zero pad the ans
        while(ans.size()<n){
                ans='0'+ans;
            }
        
        return ans;
    }
    vector<string> binstr(int n) {
        int m=1<<n;
        vector<string>ans;
        for(int i=0;i<m;i++)
        {
            ans.push_back(solve(i,n));
        }
        return ans;
    }
};