class Solution {
  public:
     int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int cnt=0;
        int i=0;
        int a=1;
        while(i<arr.size()){
            if(arr[i]==a){
                i++;
            }
            else{
                cnt++;
            }
            if(cnt==k)return a;
            a++;
        }
        while(cnt<k-1){
            a++;
            cnt++;
        }
        return a;
    }
};