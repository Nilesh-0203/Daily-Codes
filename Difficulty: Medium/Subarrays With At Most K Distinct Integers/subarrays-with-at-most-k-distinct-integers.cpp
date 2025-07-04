class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>mp;
        int n=arr.size();
        int i=0,j=0;
        int ans=0;
        while(j<n){
            mp[arr[j]]++;
            while(mp.size()>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    mp.erase(arr[i]);
                }
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};