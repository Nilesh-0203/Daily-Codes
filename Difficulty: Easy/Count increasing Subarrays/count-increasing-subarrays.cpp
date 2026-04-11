class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int ans=0;
        for(int i=1, k=1; i<arr.size(); i++){
            if(arr[i]>arr[i-1]){
                ans+=k++;
            }
            else{k=1;}
        }
        return ans;
    }
};
