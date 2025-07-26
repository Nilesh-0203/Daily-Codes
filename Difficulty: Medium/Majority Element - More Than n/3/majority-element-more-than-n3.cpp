class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int cnt=1;
        vector<int>v;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                cnt++;
            }
            else{
                if(cnt>(n/3)){
                    v.push_back(arr[i]);
                }
                cnt=1;
            }
        }
        if(cnt>(n/3)){
            v.push_back(arr[n-1]);
        }
        
        return v;
    }
};