class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
           
        int i=0,j=1;
        int maxi=-1;
        while(j<arr.size()){
            maxi=max(maxi,arr[i]+arr[j]);
            i++;j++;
        }
        return maxi;
    }
};