class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=0,j=1;
        while(j<n){
            if(arr[i]!=0){
                i++;
                j++;
            }
            else{
                while(j<n && arr[j]==0){
                    j++;
                }
                if(j>=n){
                    break;
                }
                swap(arr[i],arr[j]);
            }
        }
    }
};