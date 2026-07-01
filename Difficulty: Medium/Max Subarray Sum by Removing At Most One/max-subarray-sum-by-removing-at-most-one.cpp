class Solution {
  public:
    int maxSumSubarray(vector<int> &arr) {
    // Tabulation SO
    const int size = arr.size();
    int ans = arr[0];
    int prevNoDelete = arr[0];
    int prevOneDelete = -1e9;
    
    for(int i = 1; i < size; i++) {
        // Either add to prevNoDelete maintaining no delete
        // Or sart a new subarray in itself
        int currNoDelete = max(prevNoDelete + arr[i], arr[i]);
        
        // Either delete itself to prevNoDelete maintaining one delete
        // Or add to prevOneDelete
        int currOneDelete = max(prevNoDelete, prevOneDelete + arr[i]);
        
        // Taking maximum
        ans = max( {ans, currNoDelete, currOneDelete} );
        
        // Updation
        prevNoDelete = currNoDelete;
        prevOneDelete = currOneDelete;
    }
    
    return ans;
}

};