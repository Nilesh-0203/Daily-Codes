class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int cnt=1;
        int ans=0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==1){
                cnt++;
            }
            else{
                if(cnt>=1)ans++;
                cnt=1;
            }
        }
        return ans+1;
    }
};
