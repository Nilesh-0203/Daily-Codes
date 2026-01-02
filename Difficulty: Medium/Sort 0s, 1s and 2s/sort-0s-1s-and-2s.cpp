class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=0,j=n-1,k=0;
        while(k<=j){
            if(arr[k]==0){
                swap(arr[i],arr[k]);
                k++;
                i++;
            }
            else if(arr[k]==1){
                k++;
            }
            else{
                swap(arr[j],arr[k]);
                j--;
            }
        }
    }
};