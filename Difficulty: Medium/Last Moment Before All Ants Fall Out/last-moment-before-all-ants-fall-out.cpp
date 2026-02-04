class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
            int maxtime = 0;
        
        for(int i=0;i<left.size();i++){
            maxtime = max(maxtime,left[i]);
        }
        
        for(int i=0;i<right.size();i++){
            maxtime = max(maxtime,n-right[i]);
        }
        
        return maxtime;
    }
};