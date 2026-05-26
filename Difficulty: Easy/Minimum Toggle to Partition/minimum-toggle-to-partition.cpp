class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int one = 0;
        int ans = 0;
        for(int x : arr){
            if(x==1){
                one++;
            } else{
                ans = min(ans+1,one);
            }
        }
        return ans;
    }
};