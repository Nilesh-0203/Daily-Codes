class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
         sort(arr.begin(),arr.end());
        int k=1;
        for(int i=0;i<arr.size();i++){
            if(i+1 < arr.size() && (arr[i]<=0 || arr[i]==arr[i+1]))continue;
            if(arr[i]!=k) return k;
            k++;
        }
        return k;
    }
};