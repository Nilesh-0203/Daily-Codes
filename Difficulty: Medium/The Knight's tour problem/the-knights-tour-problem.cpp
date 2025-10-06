class Solution {
  public:
    vector<vector<int>>ans;
bool flag=false;
int arr[8]={-1,1,-2,-2,-1,1,2,2};
int brr[8]={-2,-2,-1,1,2,2,-1,1};
int n;
   void solve(int i,int j,vector<vector<int>>&vis,int sum)
   {  
       if(flag)
       {
       return;
       }
      if(sum==n*n)
       {
          ans=vis;
          flag=true;
          return ;
       }
      for(int x=0;x<8;x++)
       {
          int p=i+arr[x];
          int q=j+brr[x];
          if(p>=0 && q>=0 && p<n && q<n && vis[p][q]==-1)
           {
              vis[p][q]=sum;
              solve(p,q,vis,sum+1);
              vis[p][q]=-1;
            }
        }
   }
    vector<vector<int>> knightTour(int m) {
        // code here
        n=m;
        vector<vector<int>>vis(n,vector<int>(n,-1));
        vis[0][0]=0;
        solve(0,0,vis,1);
        return ans;
    }
};