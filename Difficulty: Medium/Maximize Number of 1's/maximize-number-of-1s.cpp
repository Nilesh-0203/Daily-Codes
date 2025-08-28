class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int m=k;
         int s=0,e=0;
        
        int ans=0;
        int c=0;
        
        while(e<n){
            if(arr[e]==0)
                c++;
        
            while(c>m){
                if(arr[s]==0)
                    c--;
                
                s++;
            }
            ans=max(ans,e-s+1);
            e++;
        }
        
        return ans;
    }
};
