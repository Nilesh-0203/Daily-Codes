class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int ans=0;
        long low=1,high=sqrt(p);
        while(low<=high){
            long mid=high-(high-low)/2;
            long sum=(mid*(mid+1)*(2*mid+1)/6);
            // cout<<sum<<endl;
            if(p>=sum){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};
