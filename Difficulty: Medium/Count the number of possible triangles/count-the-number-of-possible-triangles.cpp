class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int cnt=0;
        sort(arr.begin(),arr.end());
        for(int i=arr.size()-1;i>=2;i--){
            for(int j=i-1;j>=1;j--){
                for(int k=j-1;k>=0;k--){
                    if((arr[j]+arr[k])>arr[i])cnt++;
                    else break;
                }
            }
        }
        return cnt;
    }
};
