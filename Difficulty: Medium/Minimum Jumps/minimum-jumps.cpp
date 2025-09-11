class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int jump = 0;
        int maxJump = 0;
        int currMax = 0;
        int n = arr.size();
        for(int i=0;i<n-1;i++){
            maxJump = max(maxJump,i+arr[i]);
            if(currMax == i){
                currMax = max(currMax,maxJump);
                jump++;
            }
        }
        if(currMax >= n-1) return jump;
        return -1;
    }
 
};
