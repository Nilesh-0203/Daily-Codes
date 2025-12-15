class Solution {
  public:
      int cntWays(vector<int>& arr) {
        int right[2] = {0}, left[2] = {0},res = 0;
        for(int i = 0;i<arr.size();i++){
            right[i%2] += arr[i];
        }
        
        for(int i = 0;i<arr.size();i++){
            right[i%2] -= arr[i];
            
            if(left[0] + right[1] == left[1] + right[0]){
                res++;
            }
            
            left[i%2] += arr[i];
        }
        return res;
    }
};