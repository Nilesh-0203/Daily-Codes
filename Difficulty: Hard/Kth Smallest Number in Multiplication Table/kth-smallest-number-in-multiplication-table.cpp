class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        int l=1,r=m*n;
        int ans=r;
        while(l<=r){
            int  mid=l+(r-l)/2;
            int count=0;
            
            for(int i=1;i<=m;i++){
                count+=min(mid/i,n);
            }
            
            if(count<k){
                l=mid+1;
            }
            else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};
