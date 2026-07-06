class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int n=a.size();
        int m=b.size();
        
        int sum1=0,sum2=0,ans=0;
        int i=0,j=0;
        while(i<n and j<m){
            if(a[i]==b[j]){
                sum1+=a[i];
                sum2+=b[j];
                ans+=max(sum1,sum2);
                sum1=0;
                sum2=0;
                i++,j++;
            }
            else if(a[i]<b[j]){
                sum1+=a[i];
                i++;
            }
            else{
                sum2+=b[j];
                j++;
            }
        }
        while(i<n){
            sum1+=a[i];
            i++;
        }
        while(j<m){
            sum2+=b[j];
            j++;
        }
        ans+=max(sum1,sum2);
        return ans;
    }
};