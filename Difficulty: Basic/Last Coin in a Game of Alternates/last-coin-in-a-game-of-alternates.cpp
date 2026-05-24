class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=0,j=n-1;
        while(i<j){
            if(arr[i]>arr[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return arr[i];
    }
};