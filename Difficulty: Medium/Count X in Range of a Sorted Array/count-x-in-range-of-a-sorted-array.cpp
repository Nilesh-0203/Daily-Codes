class Solution {
  public:
     int BinarySearchLower(vector<int>& arr, int l, int r,int key){
        while(l<=r){
            int m = l + (r-l)/2;
            if(arr[m]<key){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return l;
    }
    int BinarySearchUpper(vector<int>& arr, int l, int r,int key){
        while(l<=r){
            int m = l + (r-l)/2;
            if(arr[m]<=key){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return r;
    }
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
       vector<int> results;
       for(vector<int> &q: queries){
           int l = q[0];
           int r = q[1];
           int x = q[2];
           
           int lower = BinarySearchLower(arr, l, r, x);
           int upper = BinarySearchUpper(arr, l, r, x);
           
           int cnt = upper - lower + 1;
           results.push_back(cnt);
       }
       return results;
    }
};