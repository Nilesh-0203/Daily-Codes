class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        vector<pair<int,int>> v; // {abs diff, index}
        vector<int> temp=arr;
        for(int i=0;i<arr.size();i++){
            v.push_back({abs(x-arr[i]),i});
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<arr.size();i++){
            arr[i] = temp[v[i].second];
        }
    }
};