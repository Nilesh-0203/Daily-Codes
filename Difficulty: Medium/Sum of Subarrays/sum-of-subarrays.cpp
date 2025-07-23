class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int n=arr.size();
        int result=0;
        for(int i=0;i<n;i++)
        {
            int a=(i+1)*(n-i);
            result+=a*arr[i];
            
        }
        return result;
    }
};