class Solution {
  public:
    int minMoves(vector<int>& arr) {
         // code here
         int n=arr.size();
         vector<int>pos(n, 0);
         for(int i=0; i<n; i++){
             pos[arr[i]-1]=i;
         }
         int len=1, maxi=1;

         for(int i=1; i<n; i++){
             if(pos[i]>pos[i-1]){
                 len++;
                 maxi=max(maxi, len);
             }else len=1;
         }

         return n-maxi;
     }
};