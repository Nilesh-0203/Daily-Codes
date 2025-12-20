class Solution {
  public:
     int searchInsertK(vector<int> &arr, int k) {
      int n = arr.size();
      int i=0;
      for( i=0;i<n;++i){
          if(arr[i]==k)
          return i;
          if(arr[i]>k) return i;
      }
      if(i==n) return i;
        
    }
};