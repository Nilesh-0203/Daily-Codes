class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        map<int,int>mp;
        for(int a:arr){
            mp[a]++;
        }
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==0 || target%arr[i]!=0){
                continue;
            }
            long long b=target/arr[i];
            if(arr[i]==b && mp[b]>1){
                return true;
            }
            else if(arr[i]!=b && mp[b]>0){
                return true;
            }
        }
        return false;
    }
};