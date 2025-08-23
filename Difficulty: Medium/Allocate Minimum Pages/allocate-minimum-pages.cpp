class Solution {
  public:
    bool isPossible(vector<int>&arr,int n,int k,int mid){
        int studentCount=1;
        int pageSum=0;
        for(int i=0;i<n;i++){
            if(pageSum+arr[i]<=mid){
                pageSum+=arr[i];
            }
            else{
                studentCount++;
                if(studentCount>k || arr[i]>mid){
                    return false;
                }
                pageSum=arr[i];
            }
        }
        return true;
    }
    int findPages(vector<int>&arr, int k) {
        // code here
        int n=arr.size();
        if(n<k){
            return -1;
        }
        int start=0;
        int end=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(arr,n,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};