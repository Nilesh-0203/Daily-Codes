class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
         int res = 0;
  
    // Find the time to fall off the plank for all 
    // ants moving towards left
    for(int i = 0; i < left.size(); i++) {
    	res = max(res, left[i]);
    }
  
    // Find the time to fall off the plank for all 
    // ants moving towards right
    for(int i = 0; i < right.size(); i++) {
    	res = max(res, n - right[i]);
    }
    
    // Return the maximum time among all ants
    return res;
    }
};